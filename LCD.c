/*
 * LCD.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Kirsten.Larson
 */

#include "LCD.h"

void InitSPI() {
	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;
	UCB0CTL1 |= UCSSEL1;
	UCB0STAT |= UCLISTEN;
	P1SEL |= BIT5;
	P1SEL2 |= BIT5;
	P1SEL |= BIT6;
	P1SEL2 |= BIT6;
	P1SEL |= BIT7;
	P1SEL2 |= BIT7;
	UCB0CTL1 |= UCSWRST;
}

void InitLCD() {

}

void ClrLCD() {

}

void WritetoLCD() {

}

void CursorDown() {

}

void CursorUp() {

}

void Scroll() {

}



