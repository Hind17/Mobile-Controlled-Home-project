/*
 * SPK_Interface.h
 *
 *  Created on: Jan 8, 2021
 *      Author: dell
 */

#ifndef MCAL_SPK_INTERFACE_H_
#define MCAL_SPK_INTERFACE_H_

#define SPK_Port DIO_PORTC
#define SPK_Pin  DIO_PIN2

void SPK_Init();
void SPK_OPEN();
void SPK_CLOSED();
#endif /* MCAL_SPK_INTERFACE_H_ */
