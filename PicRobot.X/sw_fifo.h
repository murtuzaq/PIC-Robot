/* 
 * File:   sw_fifo.h
 * Author: Murtuza
 *
 * Created on February 18, 2017, 9:57 AM
 */

#ifndef SW_FIFO_H
#define	SW_FIFO_H

#ifdef	__cplusplus
extern "C" {
#endif

#define SIZE 16 

typedef enum {
    FIFO_FAIL = 0,
    FIFO_SUCCESS = 1
}FIFO_STATUS;

void Fifo_Init(void);
FIFO_STATUS Fifo_Put(uint16_t data);
FIFO_STATUS Fifo_Get(uint16_t *datapt);
uint8_t Fifo_Size(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SW_FIFO_H */

