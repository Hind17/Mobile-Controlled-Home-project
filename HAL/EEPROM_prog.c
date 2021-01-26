/*
 * EEPROM_prog.c
 *
 *  Created on: Nov 7, 2020
 *      Author: dell
 */
#include "../LIB/StandardTypes.h"
#include "../LIB/macros.h"
#include "../MCAL/IIC_int.h"
#include "EEPROM_int.h"


u8 EEPROM_u8WriteByte(u16 u16Address,u8 u8Data){
	u8 u8BlockId,u8Location,u8stat;
	u8BlockId = ((u16Address >> 8) & 0x03) | 0x50;
	u8Location= (u8) u16Address;
	IIC_vidSendStart();
	if(IIC_u8CheckStatus(IIC_START) != IIC_OK ){
		return 1;
	}
	IIC_vidSendSLA(u8BlockId,IIC_Write);
	if(IIC_u8CheckStatus(IIC_MT_SLA_ACK) != IIC_OK){
		return 2;
	}
	IIC_vidSendData(u8Location);
	if(IIC_u8CheckStatus(IIC_MT_DATA_ACK) != IIC_OK){
		return 3;
	}
	IIC_vidSendData(u8Data);
	if(IIC_u8CheckStatus(IIC_MT_DATA_ACK) != IIC_OK){
		return 4;
	}
	IIC_vidSendStop();
	return 0;

}
u8 EEPROM_u8ReadByte(u16 u16Address,u8* pu8Data){
	u8 u8BlockId,u8Location,u8stat;
	u8BlockId = ((u16Address >> 8) & 0x03) | 0x50;
	u8Location= (u8) u16Address;
	IIC_vidSendStart();
	if(IIC_u8CheckStatus(IIC_START) != IIC_OK ){
		return 1;
	}
	IIC_vidSendSLA(u8BlockId,IIC_Write);
	if(IIC_u8CheckStatus(IIC_MT_SLA_ACK) != IIC_OK){
		return 2;
	}
	IIC_vidSendData(u8Location);
	if(IIC_u8CheckStatus(IIC_MT_DATA_ACK) != IIC_OK){
		return 3;
	}
	IIC_vidSendStart();
	if(IIC_u8CheckStatus(IIC_REP_START) != IIC_OK){
		return 4;
	}
	IIC_vidSendSLA(u8BlockId,IIC_Read);
	if(IIC_u8CheckStatus(IIC_MR_SLA_ACK) != IIC_OK){
		return 5;
	}
	*pu8Data = IIC_u8ReceiveWithNAck();
	if(IIC_u8CheckStatus(IIC_MR_DATA_NOT_ACK) != IIC_OK){
		return 6;
	}
	IIC_vidSendStop();
	return 0;
}

