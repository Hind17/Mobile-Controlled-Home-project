/*
 * DIO_Priv.h
 *
 *  Created on: Sep 18, 2020
 *      Author: dell
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_
/*******************Private Macros************/
#define DIO_PORTA_REG *((volatile u8*)0x3b)
#define DIO_PINA_REG *((volatile u8*)0x39)
#define DIO_DDRA_REG *((volatile u8*)0x3a)

#define DIO_PORTB_REG *((volatile u8*)0x38)
#define DIO_PINB_REG *((volatile u8*)0x36)
#define DIO_DDRB_REG *((volatile u8*)0x37)

#define DIO_PORTC_REG *((volatile u8*)0x35)
#define DIO_PINC_REG *((volatile u8*)0x33)
#define DIO_DDRC_REG *((volatile u8*)0x34)

#define DIO_PORTD_REG *((volatile u8*)0x32)
#define DIO_PIND_REG *((volatile u8*)0x30)
#define DIO_DDRD_REG *((volatile u8*)0x31)

#endif /* DIO_PRIV_H_ */
