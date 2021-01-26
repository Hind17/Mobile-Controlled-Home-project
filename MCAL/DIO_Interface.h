/*
 * DIO_Interface.h
 *
 *  Created on: Sep 18, 2020
 *      Author: dell
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/****************************************************************/
/*************************Public macros**************************/
/****************************************************************/

//Ports Definitions
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


//Pins Definitions
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

//IO Values
#define DIO_HIGH 0xff
#define DIO_LOW  0x00
#define DIO_PORT_HIGH 0xff


//IO_direction
#define  DIO_INPUT 0x00
#define DIO_OUTPUT 0xff

/****************************************************************/
/**************************Public Functions**********************/
/****************************************************************/
void DIO_vidSetPinVal(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8valCopy);
void DIO_vidSetPinDir(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8DirCopy);
u8 DIO_GetPinVal(u8 u8PortIdCopy, u8 u8PinIdCopy);
void DIO_vidSetPortVal(u8 u8PortIdCopy,u8 u8valCopy);
void DIO_vidSetPortDir(u8 u8PortIdCopy,u8 u8DirCopy);
void DIO_vidEnablePullUpRes(u8 u8PortId, u8 u8PinId);
#endif /* DIO_INTERFACE_H_ */
