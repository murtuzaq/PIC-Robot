#include <xc.h>
#include "mcu_oscillator.h"

//FOSC = 48Mhz
void OSCILLATOR_Init(void)
{
         /* Typical actions in this function are to tweak the oscillator tuning
    register, select new clock sources, and to wait until new clock sources
    are stable before resuming execution of the main project. */

	OSCCONbits.IDLEN = 0;  // Idel Enable bit
	OSCCONbits.SCS = 0;		//use Primary Oscillator;
	while(!OSCCONbits.OSTS ){};  //wait till oscilator is stable
    
}