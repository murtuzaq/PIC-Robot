/* 
 * File:   debug.h
 * Author: Murtuza
 *
 * Created on February 16, 2017, 10:48 PM
 */

#ifndef DEBUG_H
#define	DEBUG_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define HIGH                     1
#define LOW                      0

#define INPUT                    1    
#define OUTPUT                   0
    
#define PIN0_DEBUG               LATEbits.LATE1
    
#define PIN0_DEBUG_DIRECTION     TRISEbits.TRISE1
    
void DEBUG_Pin0Enable(void);

void DEBUG_Pin0High(void);

void DEBUG_Pin0Low(void);

void DEBUG_Pin0Toggle(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

