#include "PICBot.h"
#include "wheel4d.h"
#include "sema.h"
#include "sw_fifo.h"
#include "debug.h"

#define PICBOTC


void PICBOT_Task(void)
{
    uint16_t command;
    FIFO_STATUS status;
    
    if(SEMA_WaitForPICBot())
        return;
    
    status = Fifo_Get(&command);
    
    if(status == FIFO_FAIL)
    {
        //if fifo is empty then escape
        SEMA_BlockOnPICBot();
        return;
    }
	
    switch(command)
	{
		case BOT_FORWARD:
            DEBUG_Pin0Toggle();
			PICBOT_fwd();
            SEMA_SetClock();
			break;

		case BOT_BACKWARD:
			PICBOT_rvs();
            SEMA_SetClock();
			break;

		case BOT_RIGHT:
			PICBOT_rgt();
            SEMA_SetClock();
			break;

		case BOT_LEFT:
			PICBOT_lft();
            SEMA_SetClock();
			break;
            
        case BOT_STOP:
            PICBOT_Stop();
            break;

		default:
			PICBOT_Stop();
			break;
	}

}

void PICBOT_Stop(void)
{
	Wheel_Front_Right(stop);
	Wheel_Back_Right(stop);
	Wheel_Front_Left(stop);
	Wheel_Back_Left(stop);
}

void PICBOT_fwd(void)
{
	Wheel_Front_Right(forward);
	Wheel_Back_Right(forward);
	Wheel_Front_Left(forward);
	Wheel_Back_Left(forward);
}

void PICBOT_rvs(void)
{
	
	Wheel_Front_Right(reverse);
	Wheel_Back_Right(reverse);
	Wheel_Front_Left(reverse);
	Wheel_Back_Left(reverse);
}

void PICBOT_lft(void)
{
	Wheel_Front_Right(forward);
	Wheel_Back_Right(forward);
	Wheel_Front_Left(stop);
	Wheel_Back_Left(reverse);
}

void PICBOT_rgt(void)
{
	Wheel_Front_Right(stop);
	Wheel_Back_Right(reverse);
	Wheel_Front_Left(forward);
	Wheel_Back_Left(forward);
}

