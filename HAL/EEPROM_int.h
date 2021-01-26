/*
 * EEPROM_int.h
 *
 *  Created on: Nov 7, 2020
 *      Author: dell
 */

#ifndef HAL_EEPROM_INT_H_
#define HAL_EEPROM_INT_H_

u8 EEPROM_u8WriteByte(u16 u16Address,u8 u8Data);
u8 EEPROM_u8ReadByte(u16 u16Address,u8* u8Data);

#endif /* HAL_EEPROM_INT_H_ */





