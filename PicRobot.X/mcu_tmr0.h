/* 
 * File:   mcu_tmr1.h
 * Author: mquaizar
 *
 * Created on January 31, 2017, 3:33 PM
 */

#ifndef MCU_TMR0_H
#define	MCU_TMR0_H


#include <stdint.h>
#include "mcu_oscillator.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define TMR0_FOSC       93750  //94Khz
#define TMR0_TICK_us    (1000000/TMR0_FOSC)  //10.6 us     
    
// Initialize TMR0 module
void TMR0_Init(void);

// Start TMR0
void TMR0_Enable(void);

// Stop TMR0;
void TMR0_Disable(void);

// Read the current value of TMR0
uint16_t TMR0_ReadTimer(void);

// Write the TMR0 register
void TMR0_WriteTimer(uint16_t timerVal);

// Reload the initial value of TMR0
void TMR0_Reload(void);



#ifdef	__cplusplus
}
#endif

#endif	/* MCU_TMR1_H */

