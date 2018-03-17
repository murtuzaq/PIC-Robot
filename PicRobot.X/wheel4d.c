#include "wheel4d.h"
#include <xc.h>

void Wheel_Front_Right(typedef_MtrDir motion)
{
	switch(motion)
	{
		case stop:           
			Motor_Right_B_1A(0);
			Motor_Right_B_1B(0);
			break;

		case forward:
			Motor_Right_B_1A(0);
			Motor_Right_B_1B(1);
			break;

		case reverse:
			Motor_Right_B_1A(1);
			Motor_Right_B_1B(0);
			break;
	}
}

void Wheel_Front_Left(typedef_MtrDir motion)
{
	switch(motion)
	{
		case stop:
			Motor_Left_A_1A(0);
			Motor_Left_A_1B(0);
			break;

		case forward:
			Motor_Left_A_1A(0);
			Motor_Left_A_1B(1);
			break;

		case reverse:
			Motor_Left_A_1A(1);
			Motor_Left_A_1B(0);
			break;
	}

}

void Wheel_Back_Right(typedef_MtrDir motion)
{
	switch(motion)
	{
		case stop:
			Motor_Right_A_1A(0);
			Motor_Right_A_1B(0);
			break;

		case forward:
			Motor_Right_A_1A(0);
			Motor_Right_A_1B(1);
			break;

		case reverse:
			Motor_Right_A_1A(1);
			Motor_Right_A_1B(0);
			break;
	}

}

void Wheel_Back_Left(typedef_MtrDir motion)
{
	switch(motion)
	{
		case stop:
			Motor_Left_B_1A(0);
			Motor_Left_B_1B(0);
			break;

		case forward:
			Motor_Left_B_1A(0);
			Motor_Left_B_1B(1);
			break;

		case reverse:
			Motor_Left_B_1A(1);
			Motor_Left_B_1B(0);
			break;
	}

}

void Wheel_Init(void)
{
    MTR_RGH_A1A_DIR = 0;
    MTR_RGH_A1B_DIR = 0;
    MTR_RGH_B1A_DIR = 0;
    MTR_RGH_B1B_DIR = 0;
    
    MTR_LFT_A1A_DIR = 0;
    MTR_LFT_A1B_DIR = 0;
    MTR_LFT_B1A_DIR = 0;
    MTR_LFT_B1B_DIR = 0;
}
void Motor_Right_B_1A(unsigned char dir)
{
	LATAbits.LATA3 = dir;
}

void Motor_Right_B_1B(unsigned char dir)
{
	LATAbits.LATA2 = dir;
}

void Motor_Right_A_1A(unsigned char dir)
{
	LATAbits.LATA1 = dir;
}

void Motor_Right_A_1B(unsigned char dir)
{
	LATAbits.LATA0 = dir;
}

void Motor_Left_B_1A(unsigned char dir)
{
	LATBbits.LATB5 = dir;
}

void Motor_Left_B_1B(unsigned char dir)
{
	LATBbits.LATB4 = dir;
}

void Motor_Left_A_1A(unsigned char dir)
{
	LATBbits.LATB3 = dir;
}

void Motor_Left_A_1B(unsigned char dir)
{
	LATBbits.LATB2 = dir;
}

