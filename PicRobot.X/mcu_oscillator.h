/* 
 * File:   mcu_oscillator.h
 * Author: mquaizar
 *
 * Created on January 31, 2017, 4:48 PM
 */

#ifndef MCU_OSCILLATOR_H
#define	MCU_OSCILLATOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MCU_FOSC  48000000

void OSCILLATOR_Init(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MCU_OSCILLATOR_H */

