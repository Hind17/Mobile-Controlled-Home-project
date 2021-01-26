/*
 * UART_int.h
 *
 *  Created on: Oct 30, 2020
 *      Author: dell
 */

#ifndef MCAL_UART_INT_H_
#define MCAL_UART_INT_H_

void UART_vidInit(void);
void UART_vidSendData(u8 u8Data);
u8 UART_RecieveData(void);
#endif /* MCAL_UART_INT_H_ */
