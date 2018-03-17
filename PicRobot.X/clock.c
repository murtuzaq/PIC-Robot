#include <stdint.h>
#include "clock.h"
#include "mcu_tmr0.h"
#include "sema.h"
#include "PICBot.h"

static uint32_t usecs;
static uint32_t mills;
static uint32_t secs;

//The main purpose of this task is to 
void CLOCK_Task(void)
{
    static uint8_t STATE_CLOCK = 0;
    
    switch(STATE_CLOCK)
    {
        case 0: //idle state;
            if(SEMA_WaitForClock())
                return;
            
            STATE_CLOCK = 1;
            break;
            
        case 1: // active state;
            //Timeout should occur in 1.3 seconds;
            if ( (CLOCK_TIMEOUT == TIMEOUT) ||
                    (CLOCK_ReadTimer() > 10000) )
            {
                CLOCK_TIMEOUT = CLOCK_RESET;
                PICBOT_Stop();
                STATE_CLOCK = 0;
            }
            break;
            
        default: 
            STATE_CLOCK = 0;
            break;
            
    }
}
void CLOCK_Enable(void)
{
    TMR0_Enable();
}

void CLOCK_Disable(void)
{
    TMR0_Disable();
}

void CLOCK_Reload(void)
{
    TMR0_Reload();
}


uint16_t CLOCK_ReadTimer(void)
{
    return(TMR0_ReadTimer());
}

uint16_t CLOCK_ReadTimer_100us(void)
{
    return((uint16_t)(TMR0_ReadTimer()/TMR0_TICK_us));
}


uint16_t CLOCK_Time_Tick(void)
{
    uint16_t tick_time;
    CLOCK_Disable();
    tick_time = CLOCK_ReadTimer();
    
    CLOCK_TIMEOUT = CLOCK_RESET;
    CLOCK_Reload();
    CLOCK_Enable();
    
    return(tick_time);
}

uint16_t CLOCK_Time_100us (void)
{
    uint16_t us_time;
    CLOCK_Disable();
    us_time = (uint16_t)(CLOCK_ReadTimer()/(TMR0_TICK_us));
    
    CLOCK_TIMEOUT = CLOCK_RESET;       
    CLOCK_Reload();
    CLOCK_Enable();
    
    return(us_time);
}

