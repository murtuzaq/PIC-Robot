#include "mcu_ports.h"
#include <xc.h>

void PORTS_Init(void)
{
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xFF;
    TRISD = 0xFF;
    TRISE = 0xFF;
    
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    LATD = 0x00;
    LATE = 0x00;
    
    ADCON1bits.PCFG = 0xF;  //ALL pins are digital;
}
