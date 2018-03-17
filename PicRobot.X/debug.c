#include <stdint.h>
#include "debug.h"



void DEBUG_Pin0Enable(void)
{
    PIN0_DEBUG = LOW;    
    PIN0_DEBUG_DIRECTION = OUTPUT;

    
}
void DEBUG_Pin0High(void)
{
    PIN0_DEBUG = HIGH;
}

void DEBUG_Pin0Low(void)
{
    PIN0_DEBUG = LOW;
}

void DEBUG_Pin0Toggle(void)
{
    PIN0_DEBUG = ~PIN0_DEBUG;
}


