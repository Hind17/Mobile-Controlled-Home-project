/*
 * LCD_Interface.h
 *
 *  Created on: Sep 19, 2020
 *      Author: dell
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

/********************************************************/
/*******************Public Definitions*******************/
/********************************************************/
/*Comment!: LCD control commands*/


#define LCD_CLR           		0x01          /* replace all characters with ASCII 'space'                       */
#define LCD_HOME          		0x02          /* return cursor to first position on first line                   */
#define LCD_ENTRYMODE     		0x06          // shift cursor from left to right on read/write
#define LCD_DISPOFF       		0x08          // turn display off
#define LCD_DISPON_CURSON 		0x0E          // display on, cursor off, don't blink character
#define LCD_FUNCRESET     		0x30          // reset the LCD
#define LCD_FUNCSET_8BIT  		0x38          // 8-bit data, 2-line display, 5 x 7 font
#define LCD_SETCURSOR     		0x80          // set cursor position
#define LCD_DISPON_CURSBLINK	0x0F 		  //display on , cursor blinking
#define LCD_DISPON_CURSOFF		0x0C 		  //display on ,cursor off

/* Comment!: LCD displaying locations commands */
//rows definition
#define R0W1      0x00
#define R0W2      0x01
//col defination
#define COL1      0
#define COL2      1
#define COL3      2
#define COL4      3
#define COL5      4
#define COL6      5
#define COL7      6
#define COL8      7
#define COL9      8
#define COL10     9
#define COL11     10
#define COL12     11
#define COL13     12
#define COL14     13
#define COL15     14


/***************************************************************************************/
/**********************************Public Functions*************************************/
/***************************************************************************************/
/* Description: Apply initialization sequence for LCD module****************************/
/* Input      : Void                                                                   */
/* Output     : Void                                                                   */
/* Scope      : Public                                                                 */
/***************************************************************************************/

void LCD_vidInit(void);

void LCD_VidSendCmd(u8 u8CmdCpy);

void LCD_VidSendChar(u8 u8DCharCpy);

void LCD_VidSendString(u8* u8StrCpy);

void LCD_VidWriteNumber(u16 u16Num);

void LCD_vidGotoXY(u8 u8RowCpy, u8 u8ColCpy);

#endif /* HAL_LCD_INTERFACE_H_ */
