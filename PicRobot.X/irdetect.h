/* 
 * File:   irdetect.h
 * Author: Murtuza
 *
 * Created on February 17, 2017, 6:00 AM
 */

#ifndef IRDETECT_H
#define	IRDETECT_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif
   
#define		IR_END 				    0
#define		IR_BEGIN				1
#define		IR_BIT_COLLECT          2
#define		IR_TERMINATE      		3
    
#define IR_TOTAL_STATES     (IR_TERMINATE + 1)
    
#define IR_MAX_DATA_BITS        16    

#define DIRECTV_UP          0x610F          
#define DIRECTV_DOWN        0xD10F
#define DIRECTV_RIGHT         0xC90F
#define DIRECTV_LEFT         0xF10F
#define DIRECTV_SELECT      0xE90F
#define DIRECTV_RED         0x608F
#define DIRECTV_GREEN       0x708F
#define DIRECTV_YELLOW      0x508F
#define DIRECTV_BLUE        0x488F    
    
typedef struct {

    uint16_t dtime;      //delta time;
    //uint16_t dtime_us;   // delta time in us;
    uint8_t level;       //high or low;
    
        
}t_irHandle;

typedef struct{
	void (*Output_Func) (void);
	unsigned char 	Next[IR_TOTAL_STATES];

}t_irStateMachine;

typedef struct {
	unsigned char Input;  	  //index into the next state;
	unsigned char state;	  //index into the current state;
}t_irstate;

void IR_Init(void);
void IR_Task(void);

t_irHandle* IR_handle(void);


#ifdef	__cplusplus
}
#endif

#endif	/* IRDETECT_H */

