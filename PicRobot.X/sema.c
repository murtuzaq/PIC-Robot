#include "os.h"
#include "sema.h"

static int8_t sema_irdetect = 0;
static int8_t sema_picbot = 0;
static int8_t sema_clock = 0;

static int8_t sema_Task2 = 0;
static int8_t sema_Task3 = 0;
static int8_t sema_Task4 = 0;

void SEMA_SetIRdetect(void)
{
    OS_Signal(&sema_irdetect);
}

uint8_t SEMA_WaitForIRdetect(void)
{
    if(OS_Wait(&sema_irdetect))
        return(1);
    else
        return(0);
}

void SEMA_BlockOnIRdetect(void)
{
    OS_Block(&sema_picbot);
}

void SEMA_SetPICBot(void)
{
    OS_Signal(&sema_picbot);
}

uint8_t SEMA_WaitForPICBot(void)
{
    if(OS_Wait(&sema_picbot))
        return(1);
    else
        return(0);
}

void SEMA_BlockOnPICBot(void)
{
    OS_Block(&sema_picbot);
}

void SEMA_SetClock(void)
{
    OS_Signal(&sema_clock);
}

uint8_t SEMA_WaitForClock(void)
{
    if(OS_Wait(&sema_clock))
        return(1);
    else
        return(0);
}

void SEMA_BlockOnClock(void)
{
    OS_Block(&sema_clock);
}


void SEMA_SetTask2(void)
{
    OS_Signal(&sema_Task2);
}

uint8_t SEMA_WaitForTask2(void)
{
    if(OS_Wait(&sema_Task2))
        return(1);
    else
        return(0);
}

void SEMA_BlockOnTask2(void)
{
    OS_Block(&sema_Task2);
}

void SEMA_SetTask3(void)
{
    OS_Signal(&sema_Task3);
}

uint8_t SEMA_WaitForTask3(void)
{
    if(OS_Wait(&sema_Task3))
        return(1);
    else
        return(0);
}

void SEMA_BlockOnTask3(void)
{
    OS_Block(&sema_Task3);
}

void SEMA_SetTask4(void)
{
    OS_Signal(&sema_Task4);
}

uint8_t SEMA_WaitForTask4(void)
{
    if(OS_Wait(&sema_Task4))
        return(1);
    else
        return(0);
}

void SEMA_BlockOnTask4(void)
{
    OS_Block(&sema_Task4);
}