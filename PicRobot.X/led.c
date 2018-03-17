#include "led.h"


void LED_Enable(void)
{
    LED = OFF;    
    LED_DIRECTION = LED_ENABLE;

    
}
void LED_On(void)
{
    LED = ON;
}

void LED_Off(void)
{
    LED = OFF;
}

void LED_Toggle(void)
{
    LED = ~LED;
}
