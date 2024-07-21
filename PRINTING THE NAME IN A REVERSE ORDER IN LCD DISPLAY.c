/*
 * File:   3-2.c
 * Author: uppu harika
 *
 * Created on 2 August, 2023, 1:56 PM
 */
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include<xc.h>
#define _XTAL_FREQ 6000000
void init(void);
void Lcd_Command(unsigned char);
void Lcd_Data(unsigned char);
unsigned char na_me[10]={"HARIKA"};
unsigned char i,j,m,n;

void main() 
{
init();
j=0x83;   // TO PRINT OUTPUT IN FIRST LINE  
for (i=0;i<sizeof(na_me);i++,j++)   //TO PRINT DATA FROM LEFT TO RIGHT
{
Lcd_Command(j);
Lcd_Data(na_me[i]);
}
n=0xCD;                     //TO PRINT OUTPUT IN SECOND LINE
for (m=0;m<sizeof(na_me);m++,n--)    //TO PRINT OUTPUT IN REVERSE ORDER 
{
Lcd_Command(n);
Lcd_Data(na_me[m]);
}
    
while(1);
return;
}
void init()
{
    TRISC = 0X00;
    TRISD = 0X00;
    Lcd_Command(0X38); // INITIALIZATION OF DATA
    __delay_ms(100);
    Lcd_Command(0X38);
    __delay_ms(100);
    Lcd_Command(0X38);
    __delay_ms(100);
    Lcd_Command(0X38);
    __delay_ms(100); 
     Lcd_Command(0X0C);   // PINS FOR CURSOR DISPLAY
    __delay_ms(100);
    Lcd_Command(0X01);   // TO CLEAR DISPLAY
    __delay_ms(100); 
    return;
    }
void Lcd_Command(unsigned char x)  //TO GIVE DATA COMMANDS
{
PORTC&=~0X08;
PORTD=x;
PORTC|=0X01;
PORTC&=~0X01;
__delay_ms(100);
}

void Lcd_Data(unsigned char x)   // TO SET DATA PINS FOR PORTC
{
PORTC|= 0X08;
PORTD= x;
PORTC|= 0X01;
PORTC&= ~0X01;
__delay_ms(100);
}
