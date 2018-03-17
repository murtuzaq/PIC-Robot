/* 
 * File:   wheel4d.h
 * Author: Murtuza
 *
 * Created on February 18, 2017, 2:24 PM
 */

#ifndef WHEEL4D_H
#define	WHEEL4D_H

#ifdef	__cplusplus
extern "C" {
#endif


    
#define MTR_RGH_A1A         LATAbits.LATA3
#define MTR_RGH_A1B         LATAbits.LATA2
#define MTR_RGH_B1A         LATAbits.LATA1
#define MTR_RGH_B1B         LATAbits.LATA0
    
#define MTR_LFT_A1A         LATBbits.LATB5
#define MTR_LFT_A1B         LATBbits.LATB4
#define MTR_LFT_B1A         LATBbits.LATB3
#define MTR_LFT_B1B         LATBbits.LATB2    
    
#define MTR_RGH_A1A_DIR     TRISAbits.TRISA3
#define MTR_RGH_A1B_DIR     TRISAbits.TRISA2
#define MTR_RGH_B1A_DIR     TRISAbits.TRISA1
#define MTR_RGH_B1B_DIR     TRISAbits.TRISA0
    
#define MTR_LFT_A1A_DIR     TRISBbits.TRISB5
#define MTR_LFT_A1B_DIR     TRISBbits.TRISB4
#define MTR_LFT_B1A_DIR     TRISBbits.TRISB3
#define MTR_LFT_B1B_DIR     TRISBbits.TRISB2      
    
    
    
    
    
typedef enum{
	stop,
	forward,
	reverse	
}typedef_MtrDir; //typdef motor direction;


void Wheel_Init(void);

void Wheel_Front_Right(typedef_MtrDir);
void Wheel_Front_Left(typedef_MtrDir);
void Wheel_Back_Right(typedef_MtrDir);
void Wheel_Back_Left(typedef_MtrDir);


void Motor_Left_A_1A(unsigned char dir);
void Motor_Left_A_1B(unsigned char dir);
void Motor_Left_B_1A(unsigned char dir);
void Motor_Left_B_1B(unsigned char dir);
void Motor_Right_A_1A(unsigned char dir);
void Motor_Right_A_1B(unsigned char dir);
void Motor_Right_B_1A(unsigned char dir);
void Motor_Right_B_1B(unsigned char dir);


#ifdef	__cplusplus
}
#endif

#endif	/* WHEEL4D_H */

