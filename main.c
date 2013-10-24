#include <msp430.h> 
#include "LCD.h"
//Comment
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    InitSPI();
    InitLCD();
    ClrLCD();
	
	return 0;
}
