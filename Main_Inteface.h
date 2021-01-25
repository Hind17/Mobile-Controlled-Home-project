/*
 * Main_Inteface.h
 *
 *  Created on: Jan 8, 2021
 *      Author: dell
 */

#ifndef MAIN_INTEFACE_H_
#define MAIN_INTEFACE_H_

#define Led_Port 		DIO_PORTB
#define Red_Led_Pin 	DIO_PIN3
#define Green_Led_Pin 	DIO_PIN4
#define buzzer_Pin      DIO_PIN5
#define Start			0
#define Maxmimum_Trys 	3
#define IsAdmin         1
#define NotAdmin  		0
#define IsUser			1
#define Clear_LCD       1
#define Create  		'1'
#define Update			'2'
#define Delete			'3'
#define Exit 			'9'
#define Number_of_Chars 4
#define User_Add_Start  0
#define Pass_Add_Start 	100
#define First_user  0
#define Max_User  10

void Welcomeing_Message(void);
u8* Get_User(u8* user);
u8* Get_Pass(u8* pass);
u8 Login_Checking(u8* u8user,u8* u8pass);
u8 Login_Process();
u8 Admin_Checking(u8* u8user);
u8 Create_User(void);
u8 Update_User(void);
u8 Delete_User(void);
void Access_Led(void);
void EXIT_all(void);
void Alarm(void);


#endif /* MAIN_INTEFACE_H_ */
