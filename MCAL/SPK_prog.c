/*
 * SPK_prog.c
 *
 *  Created on: Jan 8, 2021
 *      Author: dell
 */
#include "../LIB/StandardTypes.h"
#include  "../LIB/macros.h"
#include "DIO_Interface.h"
#include "SPK_Interface.h"
void SPK_Init(){
	//PIN Intialization
	DIO_vidSetPinDir(SPK_Port,SPK_Pin,DIO_OUTPUT);
	DIO_vidSetPinVal(SPK_Port,SPK_Pin,DIO_LOW);
}
void SPK_OPEN(){
	DIO_vidSetPinVal(SPK_Port,SPK_Pin,DIO_HIGH);
}
void SPK_CLOSED(){
	DIO_vidSetPinVal(SPK_Port,SPK_Pin,DIO_LOW);
}
