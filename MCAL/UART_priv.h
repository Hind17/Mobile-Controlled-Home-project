/*
 * UART_priv.h
 *
 *  Created on: Oct 30, 2020
 *      Author: dell
 */

#ifndef MCAL_UART_PRIV_H_
#define MCAL_UART_PRIV_H_

#define UDR *((volatile u8*)0x2c)
#define UCSRA *((volatile u8*)0x2b)
#define UCSRB *((volatile u8*)0x2a)
#define UCSRC *((volatile u8*)0x40)
#define UBRRH *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)

#define UCSRA_Rxc 7
#define UCSRA_Txc 6
#define UCSRA_UDRE 5
#define UCSRA_U2X 1

#define UCSRB_RXEN 4
#define UCSRB_TXEN 3
#define UCSRB_UCSZ2 2

#define UCSRC_URSEL 7
#define UCSRC_UCSZ1 2
#define UCSRC_UCSZ0 1

#endif /* MCAL_UART_PRIV_H_ */
