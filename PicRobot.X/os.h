/* 
 * File:   os.h
 * Author: mquaizar
 *
 * Created on December 8, 2016, 5:36 PM
 */

#ifndef OS_H
#define	OS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

#define ENTER_CRITICAL()     // (GLOBAL_INTERRUPT_ENABLE = 0)
#define LEAVE_CRITICAL()     // (GLOBAL_INTERRUPT_ENABLE = 1)
    
void OS_AddThreads( void(*func1)(void), 
                        void(*func2)(void),
                        void(*func3)(void),
                        void(*func4)(void));

void OS_Launch(void);

void OS_Scheduler(void);

uint8_t OS_Wait(int8_t *semaPt);

void OS_Signal(int8_t *semaPt);

void OS_Block(int8_t *semaPt);

#ifdef	__cplusplus
}
#endif

#endif	/* OS_H */

