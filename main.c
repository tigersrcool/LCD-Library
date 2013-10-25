#include <msp430.h> 
#include "LCD.h"
//Comment
/*
 * main.c
 */

char message1[] = "I love ECE382!";
char message2[] = "It's the best!";
char message1size = 14;
char message2size = 14;

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    InitSPI();
    InitLCD();
    ClrLCD();

    while(1){
        Writemessage(message1, 8);
        CursorDown();
        Writemessage(message2, 8);
        CursorUp();
        _delay_cycles(100000);
        Scroll(message1, message1size);
        Scroll(message2, message2size);
        ClrLCD();
    }
	
	return 0;
}
