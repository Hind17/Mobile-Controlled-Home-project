/*
 * IIC_prog.c
 *
 *  Created on: Oct 19, 2018
 *      Author: HOSNY
 */
#include "../LIB/StandardTypes.h"
#include "../LIB/macros.h"
#include "IIC_int.h"
#include "IIC_priv.h"

void IIC_vidInit(void)
{
	/* set prescaler to 1 */
	clr_bit(TWSR,TWPS0);
	clr_bit(TWSR,TWPS1);
	/* set clock frequency to 250KHz at clock 8M */
	TWBR = 8;
	/* Set Slave Address to 3 */
	TWAR = 6;
	/* Enable TWI */
	set_bit(TWCR,TWEN);
}

void IIC_vidSendStart(void)
{
	/* Clear interrupt flag TWINT */
	/* Set TWI Start Condition */
	/* Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	/* Wait for TWINT flag set */
	while(get_bit(TWCR,TWINT) == 0);
}

void IIC_vidSendStop(void)
{
	/* Clear interrupt flag TWINT */
	/* Set TWI Stop Condition */
	/* Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

void IIC_vidSendSLA(u8 u8SlaveAdd,u8 u8Operation)
{
	/* Set Slave address + Operation to Data register */
	TWDR = (u8SlaveAdd << 1) | u8Operation;
	/* Clear interrupt flag TWINT */
	/* Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* Wait for TWINT flag set */
	while(get_bit(TWCR,TWINT) == 0);
}

void IIC_vidSendData(u8 u8SendData)
{
	/* Set Slave address + Operation to Data register */
	TWDR = u8SendData  ;
	/* Clear interrupt flag TWINT */
	/* Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* Wait for TWINT flag set */
	while(get_bit(TWCR,TWINT) == 0);
}

u8 IIC_u8ReceiveWithAck(void)
{
	/* Clear interrupt flag TWINT */
	/* Enable TWI */
	/* Set Ack enable bit */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	/* Wait for TWINT flag set */
	while(get_bit(TWCR,TWINT) == 0);
	/* Return Received Data */
	return TWDR;
}

u8 IIC_u8ReceiveWithNAck(void)
{
	/* Clear interrupt flag TWINT */
	/* Enable TWI */
	/* Clear Ack enable bit */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* Wait for TWINT flag set */
	while(get_bit(TWCR,TWINT) == 0);
	/* Return Received Data */
	return TWDR;
}

u8 IIC_u8CheckStatus(u8 u8Status)
{
	/* Check the current value of status register same as required */
	if((TWSR & TWS_MASK) == u8Status)
	{
		/* Return OK if same as expected */
		return IIC_OK;
	}
	else
	{
		/* Return Not OK if not the same */
		return IIC_NOK;
	}
}
