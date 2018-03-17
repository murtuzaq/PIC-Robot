/* 
 * File:   sema.h
 * Author: Murtuza
 *
 * Created on February 17, 2017, 6:25 AM
 */

#ifndef SEMA_H
#define	SEMA_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif


void SEMA_SetIRdetect(void);
uint8_t SEMA_WaitForIRdetect(void);
void SEMA_BlockOnIRdetect(void);

void SEMA_SetTask2(void);
uint8_t SEMA_WaitForTask2(void);
void SEMA_BlockOnTask2(void);

void SEMA_SetTask3(void);
uint8_t SEMA_WaitForTask3(void);
void SEMA_BlockOnTask3(void);

void SEMA_SetTask4(void);
uint8_t SEMA_WaitForTask4(void);
void SEMA_BlockOnTask4(void);

void SEMA_SetClock(void);
uint8_t SEMA_WaitForClock(void);
void SEMA_BlockOnClock(void);

void SEMA_SetPICBot(void);
uint8_t SEMA_WaitForPICBot(void);
void SEMA_BlockOnPICBot(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SEMA_H */

