
#include <stdint.h>
#include <xc.h>
#include "mcu_tmr0.h"

volatile uint16_t timer0ReloadVal;

void TMR0_Init(void)
{
    
    T0CONbits.T0PS = 7; //Divide by 256 Prescale;
    T0CONbits.PSA = 0; // Prescaler is assigned;
    T0CONbits.T0CS = 0;  //CLK0 Source;
    T0CONbits.T08BIT = 0;  //Timer0 is configured as a 16 bit timer;
    T0CONbits.TMR0ON = 0; //Stop Timer0;
    

    TMR1H = 0x00; 
    TMR0L = 0x00;

    // Load the TMR value to reload variable
    timer0ReloadVal=(TMR0H << 8) | TMR0L;

    timer0ReloadVal = TMR0L;
    // Clearing IF flag.
    INTCONbits.TMR0IF = 0;

}

void TMR0_Enable(void)
{
    // Start the Timer by writing to TMRxON bit
    T0CONbits.TMR0ON = 1;
}

void TMR0_Disable(void)
{
    // Stop the Timer by writing to TMRxON bit
    T0CONbits.TMR0ON = 0;
}

uint16_t TMR0_ReadTimer(void)
{
    uint16_t readVal;

    readVal = (TMR0H << 8) | TMR0L;
    
    return readVal;
}



void TMR0_Reload(void)
{
    //Write to the Timer1 register
    TMR0H = (timer0ReloadVal >> 8);
    TMR0L = timer0ReloadVal;
}


