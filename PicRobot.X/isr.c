#include "isr.h"
#include <xc.h>
#include "mcu_int0.h"
#include "clock.h"
#include "irdetect.h"
#include "led.h"
#include "sema.h"

extern t_irHandle irhandle;

void interrupt HighISR(void)                   // High priority interrupt
{
    if(INTCONbits.INT0IF)
    {
        if(INT0_Pin == 0)
        {
            INT0_RisingEdge();
            LED_On();
        }
        else
        {
            INT0_FallingEdge();
            LED_Off();
        }
        
        IR_handle()->level = INT0_Pin;
        IR_handle()->dtime = CLOCK_Time_Tick();
        //IR_handle()->dtime_us = CLOCK_Time_100us();
        SEMA_SetIRdetect();
        
        
        
        INTCONbits.INT0IF = 0;
    }
}
 
void interrupt low_priority   LowISR(void)    //Low priority interrupt
{

}
