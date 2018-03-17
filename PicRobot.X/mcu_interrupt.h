/* 
 * File:   mcu_interrupt.h
 * Author: mquaizar
 *
 * Created on January 31, 2017, 3:19 PM
 */

#ifndef MCU_INTERRUPT_H
#define	MCU_INTERRUPT_H

#include <stdint.h>
#ifdef	__cplusplus
extern "C" {
#endif
    
#define GLOBAL_INTERRUPT_ENABLE         INTCONbits.GIE
#define PERIPHERAL_INTERRUPT_ENABLE     INTCONbits.PEIE    

void INTERRUPT_Init(void);    
void INTERRUPT_Enable(void); 



#ifdef	__cplusplus
}
#endif

#endif	/* MCU_INTERRUPT_H */

