#include <xc.h>
#include <stdint.h>
#include "mcu_interrupt.h"




void INTERRUPT_Enable(void)
{   
    GLOBAL_INTERRUPT_ENABLE = 1;        // set global interrupt enable;
    PERIPHERAL_INTERRUPT_ENABLE = 1;       // set peripheral interrupt enable;
}

void INTERRUPT_Init(void)
{   
	/*Initilize Interrupts*/
	//	PIR1
	PIR1bits.TMR1IF = 0;    //Flag Timer 1 overflow
	PIR1bits.TMR2IF = 0;	//Flag Timer 2 overflow
	PIR1bits.CCP1IF = 0; 	//Flag Capture Mode;
	PIR1bits.SSPIF = 0;		//Flag Master Syn Serial Port Interrupt 
	PIR1bits.TXIF	= 0;	//Flag tranmit buffer;
	PIR1bits.RCIF	= 0;	//Flag Receive interrupt 
	PIR1bits.ADIF	= 0;	//Flag AD Converter Interrupt
	PIR1bits.SPPIF = 0;		//Flag Streaming Parallel Port

	// PIR2
	PIR2 = 0x00;
	
	//PIE
	PIE1bits.TMR1IE = 0;  	//Interrupt Enable Timer 1 overflow
	PIE1bits.TMR2IE = 0;	//Interrupt Enable Timer 2 overflow
	PIE1bits.CCP1IE = 0; 	//Interrupt Enable Capture Mode;
	PIE1bits.SSPIE = 0;		//Interrupt Enable Master Syn Serial Port Interrupt 
	PIE1bits.TXIE	= 0;	//Interrupt Enable tranmit buffer;
	PIE1bits.RCIE	= 0;	//Interrupt Enable Receive interrupt 
	PIE1bits.ADIE	= 0;	//Interrupt Enable AD Converter Interrupt
	PIE1bits.SPPIE = 0;		//Interrupt Enable Streaming Parallel Port

	//PIE2
	PIE2 = 0x00;
		
	//IPR
	IPR1bits.TMR1IP = 0;  	//Interrupt Priority Timer 1 overflow
	IPR1bits.TMR2IP = 0;	//Interrupt Priority Timer 2 overflow
	IPR1bits.CCP1IP = 0; 	//Interrupt Priority Capture Mode;
	IPR1bits.SSPIP = 0;		//Interrupt Priority Master Syn Serial Port Interrupt 
	IPR1bits.TXIP	= 0;	//Interrupt Priority tranmit buffer;
	IPR1bits.RCIP	= 0;	//Interrupt Priority Receive interrupt 
	IPR1bits.ADIP	= 0;	//Interrupt Priority AD Converter Interrupt
	IPR1bits.SPPIP = 0;		//Interrupt Priority Streaming Parallel Port
	
	//IPR2
	IPR2 = 0x00;

	//INTCON3
	INTCON3bits.INT1F = 0;  //FLAG External 1 
	INTCON3bits.INT2F = 0;  //FLAG External 2 
	INTCON3bits.INT1E = 0;  //Interrupt Enable External 1 
	INTCON3bits.INT2E = 0;  //Interrupt Enable External 2 
	INTCON3bits.INT1P = 0;  //Interrupt Priority External 1 
	INTCON3bits.INT2P = 0;  //Interrupt Priority External 2 
	
	//INTCON2
	INTCON2bits.NOT_RBPU = 0;	//PORTB pull-ups 
	INTCON2bits.INTEDG0 = 0;   	// INT0 Edge Select (rising edge)
	INTCON2bits.INTEDG1 = 0;   	// INT1 Edge Select	(rising edge)
	INTCON2bits.INTEDG2 = 0;   	// INT2 Edge Select (rising edge)
	INTCON2bits.TMR0IP = 0; 	// Interrupt Priority TMR0
	INTCON2bits.RBIP = 0; 		// Interrupt Priority RB Change

	/* Enable interrupts */
	//INTCON
	INTCONbits.RBIF = 0;		//FLAG RB Change
	INTCONbits.INT0IF = 0;		//FLAG External 0 
	INTCONbits.TMR0IF = 0;		//FLAG Timer 0 Overflow
	INTCONbits.RBIE = 0;		//Interrupt Enable RB Change
	INTCONbits.INT0IE = 0;		//Interrupt Enable External 0
	INTCONbits.TMR0IE = 0;		//Interrupt Enable Timer 0
	INTCONbits.PEIE = 0;		//Enable Low Priority Interrupt
	INTCONbits.GIE = 0;			//Enable High Priority Interrupt
  
    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */
	RCONbits.IPEN = 1;		// Enable priority levels
}

