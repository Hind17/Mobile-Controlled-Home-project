/*
 * LCD_Prog.c
 *
 *  Created on: Sep 19, 2020
 *      Author: dell
 */
#define F_CPU 8000000UL
#include "../LIB/StandardTypes.h"
#include "../LIB/macros.h"
#include "avr/delay.h"
#include "../MCAL/DIO_Interface.h"
#include "LCD_Priv.h"
#include "LCD_Interface.h"


void LCD_vidInit(void){
	_delay_ms(30);
	/*function set command*/
	LCD_VidSendCmd(LCD_FUNCSET_8BIT);
	_delay_ms(1);
	LCD_VidSendCmd(LCD_DISPON_CURSON);
	_delay_ms(1);
	//LCD_VidSendCmd(LCD_HOME);
	//_delay_ms(15);
	LCD_VidSendCmd(LCD_CLR);
	_delay_ms(2);
	LCD_VidSendCmd(LCD_ENTRYMODE);
	_delay_ms(2);
}

void LCD_VidSendCmd(u8 u8CmdCpy){
	DIO_vidSetPinVal(LCD_Port,LCD_RS,DIO_LOW);
	DIO_vidSetPinVal(LCD_Port,LCD_RW,DIO_LOW);
	DIO_vidSetPinVal(LCD_Port,LCD_E,DIO_HIGH);
	DIO_vidSetPortVal(LCD_Data_Port,u8CmdCpy);
	DIO_vidSetPinVal(LCD_Port,LCD_E,DIO_LOW);
	_delay_ms(5);
	DIO_vidSetPinVal(LCD_Port,LCD_E,DIO_HIGH);
	_delay_ms(10);

}

void LCD_VidSendChar(u8 u8CharCpy){
	DIO_vidSetPinVal(LCD_Port,LCD_RS,DIO_HIGH);
	DIO_vidSetPinVal(LCD_Port,LCD_RW,DIO_LOW);
	DIO_vidSetPinVal(LCD_Port,LCD_E,DIO_HIGH);
	DIO_vidSetPortVal(LCD_Data_Port,u8CharCpy);
	DIO_vidSetPinVal(LCD_Port,LCD_E,DIO_LOW);
	_delay_ms(5);
	DIO_vidSetPinVal(LCD_Port,LCD_E,DIO_HIGH);
	_delay_ms(10);
}
void LCD_VidSendString(u8 *u8StrCpy){
	u8 u8LoopCtr=0;
	while(u8StrCpy[u8LoopCtr] != 0){
		LCD_VidSendChar(u8StrCpy[u8LoopCtr]);
		u8LoopCtr++;
	}
}
void LCD_VidWriteNumber(u16 u16Num){
	u16 u16Range=1;
	while( (u16Num/u16Range) >= 10){
		u16Range *=10;
	}
	while(u16Range != 0	){
		LCD_VidSendChar((u16Num/u16Range)+48);
		u16Num%=u16Range;
		u16Range /= 10;
	}
}

void LCD_vidGotoXY(u8 u8RowCpy, u8 u8ColCpy)
{

	u8 u8inst= 0x80;
	if(u8RowCpy == R0W2)
	{
		u8inst |=0x40;
	}

	u8inst |=u8ColCpy;
	LCD_VidSendCmd(u8inst);

}
