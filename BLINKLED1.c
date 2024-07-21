/*
 * File:   LED1.c
 * Author: uppu harika
 *
 * Created on 13 July, 2023, 2:12 PM
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 6000000


void main() {
     
    TRISD = 0XBD;
    
    while (1) {
        PORTD = 0XFF;
        __delay_ms(3000);
        PORTD = 0X00;   // RD2=0 // RD6=0
        __delay_ms(3000);
        PORTD = 0X40;   //RD2=0 //RD6=1
        __delay_ms(3000);
        PORTD = 0X02;         //RD2=1 //RD6=0
        __delay_ms(3000);
        PORTD = 0X82;           //RD2=1 //RD=1
        __delay_ms(3000);
        
        
    }
        
    
    /* Replace with your application code */
   
}
