# Mobile-Controlled-Home-project
The system allows controlling the home by mobile phone application through Bluetooth. Two subsystems are implemented; Safety door that could be opened by   the mobile application by entering user name and password, and light on/off that could be controlled also by the mobile phone. The system supports 10 users with different names and   password. In case of entering the name and the password 3 times wrong, the system should give alarm.The system make the admin is the only one that can (update-create-delete).

The system is Connecting Bluetooth Module With Atmega32 using UART protocol to write Username & Password Verification from the EEPROM using the LCD interface with 
Atmega32 if the user is a normal user the Solenoid Lock-Door will open & Green Led for access granted & if he is an Admin user the Admin will have the option to CRUD(Update the name or password of any user  -Create a new user if there is a free space  -Delete any user) users and if the data wasn’t correct the user will have 3 tries for each wrong then the Buzzer & Red Led will be triggered then the system will be restarted.

