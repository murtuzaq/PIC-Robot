/* 
 * File:   rtclock.h
 * Author: Murtuza
 *
 * Created on February 17, 2017, 5:01 AM
 */

#ifndef RTCLOCK_H
#define	RTCLOCK_H

#include <stdint.h>
#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

    
#define CLOCK_TIMEOUT   INTCONbits.TMR0IF
#define TIMEOUT         1
#define CLOCK_RESET     0    
    
void CLOCK_Task(void);

void CLOCK_Enable(void);

void CLOCK_Disable(void);

void CLOCK_Reload(void);

uint16_t CLOCK_Time_Tick(void);

uint16_t CLOCK_ReadTimer(void);

uint16_t CLOCK_ReadTimer_100us(void);


#ifdef	__cplusplus
}
#endif

#endif	/* RTCLOCK_H */

