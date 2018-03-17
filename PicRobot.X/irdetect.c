/* DESC -------------------------------------------------------------------
 |
 |  MODULE NAME:    IRdetect.c
 |
 |       AUTHOR:    Murtuza Quaizar
 |
 |  DESCRIPTION:    Driver for the IR Detection Scheme.
 +------------------------------------------------------------------------*/

#include <stdint.h>
#include "irdetect.h"
#include "clock.h"
#include "sw_fifo.h"
#include "sema.h"


static t_irHandle irhandle;
static t_irstate irstate;
static uint16_t IRdata;
static uint8_t IRdigit;


void ir_end(void);
void ir_Begin(void);
void ir_bitcollect(void);
void ir_terminate(void);

#define TRIGGER_EDGE       0
#define DATA_PULSE         1
#define TIME_OUT           2
#define NO_PULSE           0xFF

//each dtime is 21.3us
                                                            // _________                ___            _________       
const t_irStateMachine IRSTATEMACHINE[IR_TOTAL_STATES] = {  // 			|_			___|			___|		   	    
    //	OUTPUT FUNC			                                 TRIGGER_EDGE      DATA_PULSE            TIME_OUT     
	/* [0] [IR_END]*/					{ ir_end,           { IR_BEGIN, 	0,                          0,               }},
	/* [1] [IR_BEGIN]*/                 { ir_Begin, 		{ IR_BEGIN,	    IR_BIT_COLLECT,             0,               }},
	/* [2] [IR_BIT_COLLECT]*/			{ ir_bitcollect, 	{ IR_BEGIN, 	IR_BIT_COLLECT,             IR_TERMINATE,	 }},
	/* [3] [IR_TERMINATE]*/             { ir_terminate, 	{ IR_BEGIN,     0,                          0,               }}
};


//main operating task;
void IR_Task(void)
{
    static uint8_t prvLevel = 1;
    
    irstate.Input = NO_PULSE;
    
    if ( (irhandle.level == 1) && (CLOCK_ReadTimer() > 400)) //8ms;
    {
        irstate.Input = TIME_OUT;
        SEMA_BlockOnIRdetect();
        
    }
    else if (!(irhandle.level == prvLevel ))
    {
        prvLevel = irhandle.level;
       
        if( (irhandle.level == 0) && (irhandle.dtime > 300))           //Greater than 6ms 
        {
            
            irstate.Input = TRIGGER_EDGE;
        }
        else if( (irhandle.dtime > 20) && (irhandle.dtime < 300))   // 400us - 6.5ms
        {
            irstate.Input = DATA_PULSE;
        }
       
        
    }
    
    if (irstate.Input != NO_PULSE)
    {
        irstate.state = IRSTATEMACHINE[irstate.state].Next[irstate.Input ];  //get me to the next state;

        (IRSTATEMACHINE[irstate.state].Output_Func)();
    }

}

void ir_end(void)
{
    //nothing to do here;
    return;
}
void ir_Begin(void)
{    
    IRdata = 0;
    IRdigit = 0;
}
void ir_bitcollect(void)
{
    uint8_t n;
    
    n = irhandle.dtime/26;  
    
    if ( (n > 1) && (IRdigit < IR_MAX_DATA_BITS) )
    {
      IRdata |= (1 << IRdigit);
    }
    
    IRdigit++;              
}


    
void ir_terminate(void)
{
    //message complete;   
    Fifo_Put(IRdata);
    SEMA_SetPICBot();
}


//API to access structure;
t_irHandle* IR_handle(void)
{
    return(&irhandle);
}

void IR_Init(void)
{
    irstate.state = 0;
    irstate.Input = NO_PULSE;
    Fifo_Init();
}