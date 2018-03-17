/*
 * File:   main.c
 * Author: mquaizar
 *
 * Created on January 31, 2017, 10:30 AM
 */

#include <stdint.h>
#include "os.h"
#include <xc.h>
#include "mcu_config.h"
#include "mcu_tmr0.h"
#include "mcu_int0.h"
#include "mcu_interrupt.h"
#include "debug.h"
#include "led.h"
#include "isr.h"
#include "clock.h"
#include "irdetect.h"
#include "sema.h"
#include "wheel4d.h"
#include "PICBot.h"

//sample task functions;
void task1 (void);
void task2 (void);
void task3 (void);
void task4 (void);

//Task run counter;
int i = 0;
int j = 0;
int k = 0;
int l = 0;


void main(void) 
{
    
    CONFIG_mcu();
    
    OS_AddThreads( IR_Task,PICBOT_Task,CLOCK_Task,task4);
    
    DEBUG_Pin0Enable();
    
    LED_Enable();
    
    
    INT0_Enable();
    
    CLOCK_Enable();
    
    INTERRUPT_Enable();
    
    IR_Init();
    
    Wheel_Init();
   
    OS_Launch();
    
    while(1)
    {
        OS_Scheduler();
    }
}


void task4(void)
{
    
    if(SEMA_WaitForTask4())
        return;
    
    l++;
}