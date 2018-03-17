#include <stdint.h>
#include "sw_fifo.h"

static uint8_t PutI;// put next
static uint8_t GetI;// get next
static uint16_t Fifo[SIZE];


// initialize index FIFO
void Fifo_Init(void)
{
    int i = 0;
    
    for (i = 0; i < SIZE; i++)
    {
        Fifo[i] = 0;
    }
    
    PutI = GetI = 0;  // Empty
}
// add element to end of index FIFO
// return SUCCESS if successful
FIFO_STATUS Fifo_Put(uint16_t data)
{
  if((PutI-GetI) & ~(SIZE-1))
  {
    return(FIFO_FAIL); // Failed, fifo full
  }
  Fifo[PutI&(SIZE-1)] = data; // put
  PutI++;  // Success, update
  return(FIFO_SUCCESS);
}
// remove element from front of index FIFO
// return TXFIFOSUCCESS if successful
FIFO_STATUS Fifo_Get(uint16_t *datapt)
{
  if(PutI == GetI ){
    return(FIFO_FAIL); // Empty if TxPutI=TxGetI
  }
  *datapt = Fifo[GetI&(SIZE-1)];
  GetI++;  // Success, update
  return(FIFO_SUCCESS);
}
// number of elements in index FIFO
// 0 to TXFIFOSIZE-1
uint8_t Fifo_Size(void)
{
 return ((PutI- GetI));
}