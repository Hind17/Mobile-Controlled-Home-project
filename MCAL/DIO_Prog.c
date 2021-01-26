/*
 * DIO_Prog.c
 *
 *  Created on: Sep 18, 2020
 *      Author: dell
 */
#include "../LIB/StandardTypes.h"
#include "../LIB/macros.h"
#include "DIO_Interface.h"
#include "DIO_Priv.h"

/****************************************************************/
/**************************Public Functions**********************/
/****************************************************************/
void DIO_vidSetPinVal(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8valCopy){
	if (u8PortIdCopy <= DIO_PORTD && u8PinIdCopy  <= DIO_PIN7){
		if(u8valCopy == DIO_HIGH){
			switch (u8PortIdCopy){
				case DIO_PORTA: set_bit(DIO_PORTA_REG,u8PinIdCopy); break;
				case DIO_PORTB: set_bit(DIO_PORTB_REG,u8PinIdCopy); break;
				case DIO_PORTC: set_bit(DIO_PORTC_REG,u8PinIdCopy); break;
				case DIO_PORTD: set_bit(DIO_PORTD_REG,u8PinIdCopy); break;
			}
		}
		else if (u8valCopy == DIO_LOW){
			switch (u8PortIdCopy){
				case DIO_PORTA: clr_bit(DIO_PORTA_REG,u8PinIdCopy); break;
				case DIO_PORTB: clr_bit(DIO_PORTB_REG,u8PinIdCopy); break;
				case DIO_PORTC: clr_bit(DIO_PORTC_REG,u8PinIdCopy); break;
				case DIO_PORTD: clr_bit(DIO_PORTD_REG,u8PinIdCopy); break;
			}
		}
		else{
			// invalid Value
		}
	}
	else{
		// Input Out of Range
	}
}
void DIO_vidSetPinDir(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8DirCopy){
	if (u8PortIdCopy <= DIO_PORTD && u8PinIdCopy  <= DIO_PIN7){
		if(u8DirCopy == DIO_OUTPUT){
			switch (u8PortIdCopy){
				case DIO_PORTA: set_bit(DIO_DDRA_REG,u8PinIdCopy); break;
				case DIO_PORTB: set_bit(DIO_DDRB_REG,u8PinIdCopy); break;
				case DIO_PORTC: set_bit(DIO_DDRC_REG,u8PinIdCopy); break;
				case DIO_PORTD: set_bit(DIO_DDRD_REG,u8PinIdCopy); break;
			}
		}
		else if (u8DirCopy == DIO_INPUT){
			switch (u8PortIdCopy){
				case DIO_PORTA: clr_bit(DIO_DDRA_REG,u8PinIdCopy); break;
				case DIO_PORTB: clr_bit(DIO_DDRB_REG,u8PinIdCopy); break;
				case DIO_PORTC: clr_bit(DIO_DDRC_REG,u8PinIdCopy); break;
				case DIO_PORTD: clr_bit(DIO_DDRD_REG,u8PinIdCopy); break;
			}
		}
		else{
			//invalid Value
		}
	}
	else{
		//input out of range
	}
}
u8 DIO_GetPinVal(u8 u8PortIdCopy, u8 u8PinIdCopy){
	u8 ResultLOC;
	if(u8PortIdCopy <= DIO_PORTD && u8PinIdCopy <= DIO_PIN7){
		switch(u8PortIdCopy){
		case DIO_PORTA:ResultLOC=get_bit(DIO_PINA_REG,u8PinIdCopy); break;
		case DIO_PORTB:ResultLOC=get_bit(DIO_PINB_REG,u8PinIdCopy); break;
		case DIO_PORTC:ResultLOC=get_bit(DIO_PINC_REG,u8PinIdCopy); break;
		case DIO_PORTD:ResultLOC=get_bit(DIO_PIND_REG,u8PinIdCopy); break;
		}
	}
	else{
		ResultLOC=0xff;
	}
	return ResultLOC;
}

void DIO_vidSetPortVal(u8 u8PortIdCopy,u8 u8valCopy){
	switch(u8PortIdCopy){
	case DIO_PORTA:DIO_PORTA_REG = u8valCopy; break;
	case DIO_PORTB:DIO_PORTB_REG = u8valCopy; break;
	case DIO_PORTC:DIO_PORTC_REG = u8valCopy; break;
	case DIO_PORTD:DIO_PORTD_REG = u8valCopy; break;
	}
}
void DIO_vidSetPortDir(u8 u8PortIdCopy,u8 u8DirCopy){
	switch(u8PortIdCopy){
	case DIO_PORTA:DIO_DDRA_REG = u8DirCopy; break;
	case DIO_PORTB:DIO_DDRB_REG = u8DirCopy; break;
	case DIO_PORTC:DIO_DDRC_REG = u8DirCopy; break;
	case DIO_PORTD:DIO_DDRD_REG = u8DirCopy; break;
	}
}
void DIO_vidEnablePullUpRes(u8 u8PortId, u8 u8PinId)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortId <= DIO_PORTD) && (u8PinId <= DIO_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortId)
		{
			case DIO_PORTA: set_bit(DIO_PORTA_REG,u8PinId); break;
			case DIO_PORTB: set_bit(DIO_PORTB_REG,u8PinId); break;
			case DIO_PORTC: set_bit(DIO_PORTC_REG,u8PinId); break;
			case DIO_PORTD: set_bit(DIO_PORTD_REG,u8PinId); break;
		}
	}
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}
