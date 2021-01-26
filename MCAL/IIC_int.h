/*
 * IIC_int.h
 *
 *  Created on: Oct 19, 2018
 *      Author: HOSNY
 */

#ifndef IIC_INT_H_
#define IIC_INT_H_

/* IIC Operation Selection */
#define IIC_Read             0x01
#define IIC_Write            0x00

/* Status Check Return Values */
#define IIC_OK               0x01
#define IIC_NOK              0x00

/* Common Status code */
#define IIC_START            0x08
#define IIC_REP_START        0x10
#define IIC_ARB_LOST         0x38

/* Master transmitter Status Code */
#define IIC_MT_SLA_ACK       0x18
#define IIC_MT_SLA_NOT_ACK   0x20
#define IIC_MT_DATA_ACK      0x28
#define IIC_MT_DATA_NOT_ACK  0x30

/* Master Receiver Status Code    */
#define IIC_MR_SLA_ACK       0x40
#define IIC_MR_SLA_NOT_ACK   0x48
#define IIC_MR_DATA_ACK      0x50
#define IIC_MR_DATA_NOT_ACK  0x58


void IIC_vidInit(void);
void IIC_vidSendStart(void);
void IIC_vidSendStop(void);
void IIC_vidSendSLA(u8 u8SlaveAdd,u8 u8Operation);
void IIC_vidSendData(u8 u8SendData);

u8 IIC_u8CheckStatus(u8 u8Status);
u8 IIC_u8ReceiveWithAck(void);
u8 IIC_u8ReceiveWithNAck(void);

#endif /* IIC_INT_H_ */
