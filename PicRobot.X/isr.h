/* 
 * File:   isr.h
 * Author: Murtuza
 *
 * Created on February 17, 2017, 5:41 AM
 */

#ifndef ISR_H
#define	ISR_H

#ifdef	__cplusplus
extern "C" {
#endif

void interrupt HighISR(void);     
void interrupt low_priority LowISR(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ISR_H */

