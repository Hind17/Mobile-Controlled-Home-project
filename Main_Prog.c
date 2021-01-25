#define F_CPU 8000000UL
#include "LIB/StandardTypes.h"
#include "LIB/macros.h"
#include <avr/delay.h>
#include "MCAL/DIO_Interface.h"
#include "MCAL/UART_int.h"
#include "MCAL/IIC_int.h"
#include "MCAL/SPK_Interface.h"
#include "HAL/LCD_Interface.h"
#include "HAL/EEPROM_int.h"
#include "Main_Inteface.h"


u8 pass_loc_end=0;

void Welcomeing_Message(){
	LCD_VidSendString("Welcome");
	_delay_ms(1000);
	LCD_VidSendCmd(LCD_CLR);
}
u8* Get_User(u8* user){
	u8 i;

	LCD_VidSendString("Enter User");
	_delay_ms(1000);
	LCD_VidSendCmd(LCD_CLR);
	for(i=Start;i<Number_of_Chars;i++){
		user[i]=UART_RecieveData();
		LCD_VidSendChar(user[i]);
		_delay_ms(1000);

	}
	LCD_VidSendCmd(LCD_CLR);
	return user;

}
u8* Get_Pass(u8* pass){
	u8 i;
	LCD_VidSendCmd(LCD_CLR);
	LCD_VidSendString("Enter Pass");
	_delay_ms(1000);
	LCD_VidSendCmd(LCD_CLR);
	for(i=Start;i<Number_of_Chars;i++){
		pass[i]=UART_RecieveData();
		LCD_VidSendChar('*');
		_delay_ms(1000);

	}
	LCD_VidSendCmd(LCD_CLR);
	return pass;

}


u8 Login_Checking(u8* u8user,u8* u8pass)
{    u8 u8Data , count_correct_name=0,count_correct_pass=0,count_char=0,name_loc_end=0,count_pass=0;

		for(u8 i=First_user;i<Max_User;i++){
			for(u8 j=i* Number_of_Chars;j<((i* Number_of_Chars)+4);j++) // checking name of the user if correct or not
			{
				EEPROM_u8ReadByte(j,&u8Data);
				if (u8user[count_char]==u8Data)
				{
					count_char++;      //counts digits in the name of user
					count_correct_name++;   // counts the correct digits in the name of user compared with storing in eeprom
				    name_loc_end=j;
				}
				else{
					j=((i*Number_of_Chars)+4);   //break;

				}
			}

			count_char=0;
			if(count_correct_name== Number_of_Chars){
				i=Max_User;
			}
		}
			if(count_correct_name== Number_of_Chars)
			{
				for(u8 k=((name_loc_end-3)+Pass_Add_Start),count_pass=0;k<((name_loc_end-3)+Pass_Add_Start+4);k++) // checking password of the user if correct or not
				{
					EEPROM_u8ReadByte(k,&u8Data);
					if (u8pass [count_pass]==u8Data)
					{
						count_pass++;      //counts digits in the password of user
						count_correct_pass++;   // counts the correct digits in the password of user compared with storing in eeprom
						pass_loc_end=k;
					}
					else{
								k=((name_loc_end-4)+Pass_Add_Start+4);  //break

					}


				}


			}


			if(count_correct_pass== Number_of_Chars && count_correct_name== Number_of_Chars )
				return 1;

			else
				return 0;




}


u8 Admin_Checking(u8* u8user)
{   u8 admin_name[Number_of_Chars]={'H','I','N','D'};
    u8 admin_correct=0;
	for(u8 i=0;i<Number_of_Chars;i++){

		if(admin_name[i]==u8user[i])
		{
			admin_correct=1;
		}
		else
		{
			admin_correct=0;
			i=Number_of_Chars;
		}
	}

		if(admin_correct==1)
			return 1;
		else
			return 0;


}

u8 Create_User(void)
{  u8 u8Data;
   u8 free_loc_name=0;
   u8 user_new,pass_new,operatio_correct=0;
   u8 j=0;

	for(u8 i=First_user;i<Max_User;i++){
		for(j=i*Number_of_Chars;j<((i*Number_of_Chars)+4);j++) // checking  if X IS existing or not
			{
				EEPROM_u8ReadByte(j,&u8Data);
				if (u8Data=='X')
				{
				  free_loc_name++;    //checking if there are four x or not

				}
				else
					{j=((i*Number_of_Chars)+4);}

			}
		if(free_loc_name==Number_of_Chars)
				{i=Max_User;}
	}
		if(free_loc_name==Number_of_Chars)
		{   LCD_VidSendString("Enter user");
			_delay_ms(1000);
			LCD_VidSendCmd(LCD_CLR);
			for(u8 i=0;i<Number_of_Chars;i++)
		        {
				 user_new=UART_RecieveData();
				 EEPROM_u8WriteByte( ((j-1)-(Number_of_Chars-1)+i ) , user_new );
				 _delay_ms(100);
				 EEPROM_u8ReadByte(((j-1)-(Number_of_Chars-1)+i ),&u8Data);
				 LCD_VidSendChar(u8Data);
		        }
			 _delay_ms(500);
			LCD_VidSendCmd(LCD_CLR);
		    _delay_ms(500);
		    LCD_VidSendString("Enter Pass");
		    _delay_ms(1000);
		    LCD_VidSendCmd(LCD_CLR);

		     for(u8 i=0;i<Number_of_Chars;i++)
				 {
					pass_new=UART_RecieveData();
					EEPROM_u8WriteByte( (((j-1)-(Number_of_Chars-1))+Pass_Add_Start+i ) , pass_new );
					_delay_ms(100);
					EEPROM_u8ReadByte((((j-1)-(Number_of_Chars-1))+Pass_Add_Start+i ),&u8Data);
					LCD_VidSendChar(u8Data);
				 }


		     operatio_correct=1;
		  }





	 if( operatio_correct==1)
	         {  _delay_ms(500);
				LCD_VidSendCmd(LCD_CLR);
		       _delay_ms(500);
		       LCD_VidSendString("successful");
				_delay_ms(1000);
				LCD_VidSendCmd(LCD_CLR);
				return 1;
	        	     }
	 else{
		 _delay_ms(500);
		 LCD_VidSendCmd(LCD_CLR);
		 _delay_ms(500);
		LCD_VidSendString("failed");
		_delay_ms(1000);
		LCD_VidSendCmd(LCD_CLR);
		return 0;
			}


}



u8 Update_User(void){
	u8 u[4];
	u8 p[4];
	u8 u8Data;
	u8 *user,*pass;
	user=u;
	pass=p;
	u8 pass_new ;
	u8 correct_oper=0;
	user=Get_User(user);
	pass=Get_Pass(pass);
	if(Login_Checking(user,pass)==1)
	{
		 LCD_VidSendString("Enter pass");
		_delay_ms(1000);
		LCD_VidSendCmd(LCD_CLR);

		for(u8 i=Start;i<Number_of_Chars;i++){
			 pass_new=UART_RecieveData();
			 EEPROM_u8WriteByte((( pass_loc_end-Number_of_Chars)+i),pass_new);
			 _delay_ms(100);
			 EEPROM_u8ReadByte((( pass_loc_end-Number_of_Chars)+i),&u8Data);
			 LCD_VidSendChar(u8Data);
     		 correct_oper=1;           //to check  that the operation of changing pass is done successfully
		}

	}

    if(correct_oper==1)
    {    _delay_ms(500);
	    LCD_VidSendCmd(LCD_CLR);
	    _delay_ms(500);
    	LCD_VidSendString("successful");
		_delay_ms(1000);
		LCD_VidSendCmd(LCD_CLR);
		return 1;
    }
    else{
    	_delay_ms(500);
		LCD_VidSendCmd(LCD_CLR);
		_delay_ms(500);
    	LCD_VidSendString("failed");
		_delay_ms(1000);
		LCD_VidSendCmd(LCD_CLR);
		return 0;
    }

}



u8 Delete_User(void){
	u8 i,j,R_val,counter,CUC=0; //CUC -> Correct User Check
	u8* u[4],p[4];
	u8 *user,*pass;
	u8 *EEPROM_Reader=&R_val;
	u8 user_ind,CPC;   // CPC --> Correct Password Check
	user=u;
	pass=p;
	user=Get_User(user);
	pass=Get_Pass(pass);
	//Find The User To be Deleted
	for(i=First_user;i<Max_User;i++){
		user_ind=i*Number_of_Chars; // i can use the i instead but this is better for understanding
		for(j=i*Number_of_Chars,counter=0;j<((i*Number_of_Chars)+4);j++,counter++){
			EEPROM_u8ReadByte(j,EEPROM_Reader);
			//check User Chars
			if(*EEPROM_Reader == user[counter]){
				CUC=1;
			}
			else{
				CUC=0;
				j=((i*Number_of_Chars)+4);
			}

		}
		if(CUC == 1){
			i=Max_User;
		}
	}
	counter=0;
	if(CUC == 1){
		for(i=Pass_Add_Start+user_ind;i<(Pass_Add_Start+user_ind+4);i++){
			EEPROM_u8ReadByte(i,EEPROM_Reader);
			if(*EEPROM_Reader == pass[counter]){
				CPC=1;
			}
			else{
				CPC=0;
				i=(Pass_Add_Start+user_ind+4);
			}
			counter++;
		}
	}
	// Delete The Found User
	if(CPC & CUC == 1){
		for(i=Start;i<Number_of_Chars;i++){
			EEPROM_u8WriteByte((user_ind+i),'X');
			_delay_ms(100);
			EEPROM_u8WriteByte((Pass_Add_Start+user_ind+i),'X');
			_delay_ms(100);
		}
		return 1;
	}
	else{
		return 0;
	}
}
void Access_Led(){
	DIO_vidSetPinVal(Led_Port,Red_Led_Pin,DIO_LOW);
	DIO_vidSetPinVal(Led_Port,Green_Led_Pin,DIO_HIGH);
	_delay_ms(3000);
	DIO_vidSetPinVal(Led_Port,Green_Led_Pin,DIO_HIGH);

}

void Alarm(void){
	DIO_vidSetPinVal(Led_Port,Green_Led_Pin,DIO_LOW);
	DIO_vidSetPinVal(Led_Port,Red_Led_Pin,DIO_HIGH);
	DIO_vidSetPinVal(Led_Port,buzzer_Pin,DIO_HIGH);//buzzer
	_delay_ms(3000);
	DIO_vidSetPinVal(Led_Port,Red_Led_Pin,DIO_LOW);
	DIO_vidSetPinVal(Led_Port,buzzer_Pin,DIO_LOW);//buzer

}

void EXIT_all(void){
	DIO_vidSetPinVal(Led_Port,Red_Led_Pin,DIO_LOW);
	DIO_vidSetPinVal(Led_Port,Green_Led_Pin,DIO_LOW);
	DIO_vidSetPinVal(Led_Port,buzzer_Pin,DIO_LOW);
	SPK_CLOSED();

}
