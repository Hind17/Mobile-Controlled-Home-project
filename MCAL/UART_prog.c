/*
 * UART_prog.c
 *
 *  Created on: Oct 30, 2020
 *      Author: dell
 */
#include "../LIB/StandardTypes.h"
#include "../LIB/macros.h"
#include "UART_priv.h"
#include "UART_int.h"

void UART_vidInit(void){
	clr_bit(UCSRA,UCSRA_U2X);
	clr_bit(UCSRB,UCSRB_UCSZ2);
	UCSRC=(1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
	UBRRL=51;
	UBRRH=0;
	set_bit(UCSRB,UCSRB_TXEN);
	set_bit(UCSRB,UCSRB_RXEN);
}
void UART_vidSendData(u8 u8Data){
	while(get_bit(UCSRA,UCSRA_UDRE) == 0);
	UDR=u8Data;
}
u8 UART_RecieveData(void){
	while(get_bit(UCSRA,UCSRA_Rxc)==0);
	return UDR;
}


