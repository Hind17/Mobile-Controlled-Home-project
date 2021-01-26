/*
 * IIC_PRIV.h
 *
 *  Created on: Oct 19, 2018
 *      Author: HOSNY
 */

#ifndef IIC_PRIV_H_
#define IIC_PRIV_H_

#define TWBR  (*(volatile u8*)0x20)
#define TWSR  (*(volatile u8*)0x21)
#define TWAR  (*(volatile u8*)0x22)
#define TWDR  (*(volatile u8*)0x23)
#define TWCR  (*(volatile u8*)0x56)

/* TWCR bits */
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2

/* TWSR bit */
#define TWS_MASK 0xF8
#define TWPS1 1
#define TWPS0 0

#endif /* IIC_PRIV_H_ */
