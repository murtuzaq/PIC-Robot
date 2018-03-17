/* 
 * File:   led.h
 * Author: Murtuza
 *
 * Created on February 17, 2017, 4:28 AM
 */

#ifndef LED_H
#define	LED_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

    
#define LED             LATEbits.LATE2
#define LED_DIRECTION   TRISEbits.TRISE2
    
#define ON      1
#define OFF     0

#define LED_ENABLE  0
#define LED_DISABLE 1    

    

void LED_Enable(void);

void LED_On(void);

void LED_Off(void);

void LED_Toggle(void);   

#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

