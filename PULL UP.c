/*
 * File:   PULL UP-PULL DOWN.c
 * Author: uppu harika
 *
 * Created on 20 July, 2023, 7:49 PM
 */

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 6000000
void main() 
{
    unsigned char x;
    TRISC = 0X0F;     // RC0 to RC3 as input
    TRISD = 0X00;
    PORTD = 0X00;
    PORTC = 0X00;
    while(1)
    {
        x = PORTC;
        switch(x)
        {
            case 0X0E:   PORTD= 0X04;    // 0000 0100 RD5 LED OFF RDZ LED ON
            break;
            case 0x0D:   PORTD= 0X24;   // 0010 0100 RD5 LED ON RD2 LED ON
            break;
            case 0x0B:    PORTD =  0X20;   // 0010 0000 RD5 LED ON RD2 LED OFF
            break;
            case 0X07:    PORTD= 0X00;     // 0000 0000 RD5 LED OFF RD2 LED OFF
            break;
            case 0X0F:     PORTD = 0X00;
            
            
        }
    }
    
}


