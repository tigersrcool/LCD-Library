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

void WritetoLCD(char*string);

void CursorDown();

void CursorUp();

void Scroll();

#endif /* LCD_H_ */
