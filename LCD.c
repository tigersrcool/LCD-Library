/*
 * LCD.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Kirsten.Larson
 */

#include "LCD.h"

#define RS_MASK 0x40

int LCDCON=0;

void writeCommandNibble(char commandNibble);
void writeCommandByte(char commandByte);
void LCD_write_8(char byteToSend);
void SPI_send(char byteToSend);
void LCD_write_4(char byteToSend);
void delayMicro();
void delayMilli();
void set_SS_lo();
void set_SS_hi();

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
	UCB0CTL1 &= ~UCSWRST;
}

void InitLCD() {
    writeCommandNibble(0x03);
    writeCommandNibble(0x03);
    writeCommandNibble(0x03);
    writeCommandNibble(0x02);
    writeCommandByte(0x28);
    writeCommandByte(0x0C);
    writeCommandByte(0x01);
    writeCommandByte(0x06);
    writeCommandByte(0x01);
    writeCommandByte(0x02);
    SPI_send(0);
    delayMicro();
}


void ClrLCD(){
    writeCommandByte(1);
}

void writeCommandNibble(char commandNibble){
    LCDCON &= ~RS_MASK;
    LCD_write_4(commandNibble);
    delayMilli();
}

void writeCommandByte(char commandByte){
    LCDCON &= ~RS_MASK;
    LCD_write_8(commandByte);
    delayMilli();
}

void writeDataByte(char dataByte){
    LCDCON |= RS_MASK;
    LCD_write_8(dataByte);
    delayMilli();
}

void LCD_write_8(char byteToSend){
    unsigned char sendByte = byteToSend;
    sendByte &= 0xF0;
    sendByte = sendByte >> 4;               // rotate to the right 4 times
    LCD_write_4(sendByte);
    sendByte = byteToSend;
    sendByte &= 0x0F;
    LCD_write_4(sendByte);
}

void SPI_send(char byteToSend){
    volatile char readByte;
    set_SS_lo();
    UCB0TXBUF = byteToSend;
    while(!(UCB0RXIFG & IFG2)){
        // wait until you've received a byte
    }
    readByte = UCB0RXBUF;
    set_SS_hi();
}

void LCD_write_4(char byteToSend){
	unsigned char sendByte = byteToSend;
	sendByte &= 0xF0;
	sendByte |= LCDCON;
	sendByte &= 0x7F;
	SPI_send(sendByte);
	delayMicro();
	sendByte |= 0x80;
	SPI_send(sendByte);
	delayMicro();
	sendByte &= 0x7F;
	SPI_Send(sendByte);
	delayMicro();
}

void WritetoLCD(char*StringtoWrite){

}

void CursorDown() {
	writeCommandByte(0xC0);
}

void CursorUp() {
	writeCommandByte(0xC0);
}

void Scroll() {

}

void delayMicro(){
	__delay_cycles(45);
}

void delayMilli(){
	__delay_cycles(1829);
}

void set_SS_lo(){
	P1DIR |= BIT0;
	P1OUT &= ~BIT0;
}

void set_SS_hi(){
	P1DIR |= BIT0;
	P1OUT |= BIT0;
}
