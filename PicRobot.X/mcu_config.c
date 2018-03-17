#include "mcu_config.h"
#include "mcu_oscillator.h"
#include "mcu_interrupt.h"
#include "mcu_int0.h"
#include "mcu_tmr0.h"
#include "mcu_ports.h"


//Configure MCU hardware;
void CONFIG_mcu(void)
{
    OSCILLATOR_Init();
    
    PORTS_Init();
    
    INTERRUPT_Init();  
    
    TMR0_Init();
    
    INT0_Init();
}
