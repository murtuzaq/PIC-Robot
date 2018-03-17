/* 
 * File:   mcu_int0.h
 * Author: Murtuza
 *
 * Created on February 16, 2017, 10:17 PM
 */

#ifndef MCU_INT0_H
#define	MCU_INT0_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

void INT0_Init(void);
void INT0_Enable(void);
void INT0_RisingEdge(void);
void INT0_FallingEdge(void);

#define INT0_Pin    PORTBbits.RB0

#ifdef	__cplusplus
}
#endif

#endif	/* MCU_INT0_H */

