/*

 * main.c
 *
 *  Created on: Oct 30, 2020
 *      Author: lenovo
 */
#define F_CPU 8000000UL
#include "LIB/StandardTypes.h"
#include "LIB/macros.h"
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "MCAL/DIO_Interface.h"
#include "MCAL/UART_int.h"
#include "MCAL/IIC_int.h"
#include "HAL/LCD_Interface.h"
#include "HAL/EEPROM_int.h"
#include "Main_Inteface.h"

void main(void)
{
      /////////////lcd_port////////////////////

	    DIO_vidSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
		DIO_vidSetPinDir(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
		DIO_vidSetPinDir(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
		DIO_vidSetPortDir(DIO_PORTA,DIO_OUTPUT);

		u8 u8Data,u8Ret;
	    u8 i,admin,option,user_found;
		u8 User_arr[4],Pass_arr[4];
		u8 *user,*pass;
		user=User_arr;
		pass=Pass_arr;
		option=0;
		admin=0;
		user_found=0;
		//2 Leds for Green/Red to show if access granted or not
		//Leds Intialized
		DIO_vidSetPinDir(Led_Port,Red_Led_Pin,DIO_OUTPUT);
		DIO_vidSetPinDir(Led_Port,Green_Led_Pin,DIO_OUTPUT);
		//buzzer Intialized
		DIO_vidSetPinDir(Led_Port,buzzer_Pin,DIO_OUTPUT);
		//LCD Intialized
		LCD_vidInit();
		// Bluetooth Intialized
		UART_vidInit();   //UART-Polling-Based
		//EEPROM Intialized
		IIC_vidInit();   //EEPORM Works Based on I2C Protocol
		//SPK Intialized
		SPK_Init();



/*
///////////////////storing 10 names and pass in EEprom///////////////////////////
	    u8 user_new,pass_new;
     for(u8 i=First_user;i<Max_User;i++)
     {  LCD_VidSendChar(i+48);
		 _delay_ms(500);
		LCD_VidSendCmd(LCD_CLR);
		_delay_ms(500);
	    LCD_VidSendString("Enter user");
		 _delay_ms(1000);
		 LCD_VidSendCmd(LCD_CLR);
		 for(u8 j=Number_of_Chars*i;j<((Number_of_Chars*i)+4);j++)
			{
			 user_new=UART_RecieveData();
			 EEPROM_u8WriteByte( j  , user_new );
			 _delay_ms(100);
			 EEPROM_u8ReadByte(j ,&u8Data);
			 LCD_VidSendChar(u8Data);

			}
		 _delay_ms(500);
		LCD_VidSendCmd(LCD_CLR);
		_delay_ms(500);
		LCD_VidSendString("Enter Pass");
		_delay_ms(1000);
		LCD_VidSendCmd(LCD_CLR);
		 for(u8 k=Number_of_Chars*i;k<((Number_of_Chars*i)+4);k++)
			{
			 pass_new=UART_RecieveData();
			 EEPROM_u8WriteByte(k+100, pass_new );
			 _delay_ms(100);
			 EEPROM_u8ReadByte(k+100,&u8Data);
			 LCD_VidSendChar(u8Data);

			}
		 _delay_ms(500);
		LCD_VidSendCmd(LCD_CLR);
		_delay_ms(500);

     }*/
		 /*   for(u8 i=8;i<12;i++)  //reading from eeprom
			{
			   EEPROM_u8ReadByte(i,&u8Data);

				LCD_VidSendChar(u8Data);
					}*/


		while(1){
				Welcomeing_Message();
				for(i=Start;i<Maxmimum_Trys;i++){
					user=Get_User(user);
					pass=Get_Pass(pass);
					if(Login_Checking(user,pass)== IsUser){
						admin=Admin_Checking(user);
						i=Maxmimum_Trys;
						user_found=1;
					}
					else{
						_delay_ms(500);
						LCD_VidSendCmd(Clear_LCD);
						LCD_VidSendString(" Invalid ");
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);

					}

				}
				if(user_found==1)
				{
					if(Login_Checking(user,pass) == IsUser && admin != IsAdmin){
						Access_Led();
						LCD_VidSendString("Access Granted");
						SPK_OPEN();
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);
						LCD_VidSendString("The Door opened");
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);


					}
					else if (Login_Checking(user,pass) == IsUser && admin == IsAdmin){
						Access_Led();
						LCD_VidSendString("Access Granted");
						SPK_OPEN();
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);
						LCD_VidSendString("The Door opened");
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);
						LCD_VidSendString("Welcome Admin");
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);
						LCD_vidGotoXY(R0W1,COL1);
						LCD_VidSendString("To Create User");
						LCD_vidGotoXY(R0W2,COL1);
						LCD_VidSendString("  Press One ");
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);
						LCD_vidGotoXY(R0W1,COL1);
						LCD_VidSendString("To Update User");
						LCD_vidGotoXY(R0W2,COL1);
						LCD_VidSendString("  Press Two ");
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);
						LCD_vidGotoXY(R0W1,COL1);
						LCD_VidSendString("To Delete User");
						LCD_vidGotoXY(R0W2,COL1);
						LCD_VidSendString("  Press Three ");
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);
						LCD_vidGotoXY(R0W1,COL1);
						LCD_VidSendString("To Exit User");
						LCD_vidGotoXY(R0W2,COL1);
						LCD_VidSendString("  Press nine ");
						_delay_ms(1000);
						LCD_VidSendCmd(Clear_LCD);
						option=UART_RecieveData();
						while(option != Exit){
							switch(option){
							case Create:Create_User(); break;
							case Update:Update_User(); break;
							case Delete:Delete_User(); break;
							}
							LCD_VidSendString("Another option");
							_delay_ms(1000);
							option=UART_RecieveData();
						}


					}
					LCD_VidSendCmd(Clear_LCD);
					LCD_VidSendString("DONE");
					_delay_ms(1000);
					LCD_VidSendCmd(Clear_LCD);
					_delay_ms(1000);
					EXIT_all();

				}

				else{
					LCD_VidSendString("7ramy");
					Alarm();
					_delay_ms(1000);
					LCD_VidSendCmd(Clear_LCD);

				}

			}


}







