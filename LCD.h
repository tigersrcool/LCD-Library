/*
 * LCD.h
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Kirsten.Larson
 */

#ifndef LCD_H_
#define LCD_H_
#include <msp430.h>

void InitSPI();

void InitLCD();

void ClrLCD();

void Writeletter(char asciiChar);

void WritetoLCD(char*string);

void CursorDown();

void CursorUp();

void Scroll(char message[], char messagelength);

#endif /* LCD_H_ */
