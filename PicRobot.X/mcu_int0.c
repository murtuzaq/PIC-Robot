#include <stdint.h>
#include "mcu_int0.h"
#include <xc.h>

void INT0_Init(void)
{   
    INTCONbits.INT0IF = 0;  //Clear int0 flag;
    
    INTCONbits.INT0IE = 0;  //Disable int0 Interrupt;
    
    INT0_FallingEdge();   
}

void INT0_Enable(void)
{
    TRISBbits.TRISB0 = 1; // INT0 as input;
    INTCONbits.INT0IF = 0;  //Clear int0 flag;
    INTCONbits.INT0IE = 1;  //Enable Int;
    
}

void INT0_RisingEdge(void)
{
    INTCON2bits.INTEDG0 = 1;
}

void INT0_FallingEdge(void)
{
    INTCON2bits.INTEDG0 = 0;
}

