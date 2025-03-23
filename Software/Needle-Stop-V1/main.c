/******************************************************************************
 * @file     main.c
 * @brief    The main file for Needle Stop application.
 * @version  1.0.0
 * @authors  Alperen KOLAMUC
 * @date     23 March 2025
 ******************************************************************************/

#include "ms51_32k.h"

#define true	1
#define false 0

#define LED1		P13
#define LED2		P24
#define TOUCH1	P25
#define TOUCH2	P14
#define RELAY1	P33
#define RELAY2 	P01
#define RELAY3	P00
#define RELAY4	P10
#define RST_BTN	P15

int	lock_state = false;

//----------------------------------------------------------------------------------------------//
void main (void)
{

	P25_INPUT_MODE;
	P14_INPUT_MODE;
	P15_INPUT_MODE;
	
	P13_PUSHPULL_MODE;
	P24_PUSHPULL_MODE;
	P33_PUSHPULL_MODE;
	P01_PUSHPULL_MODE;
	P00_PUSHPULL_MODE;
	P10_PUSHPULL_MODE;
	
	
	RELAY1 = 0;
	RELAY2 = 0;
	RELAY3 = 0;
	RELAY4 = 0;
	
	Timer0_Delay(16000000,200,100);;
	
  while(1)
  {
		
		LED1 = TOUCH1;	//LED1 = TOUCH1
		LED2 = TOUCH2;	//LED2 = TOUCH2
		
		
		if((TOUCH1 == 1) && (lock_state == false)){
			RELAY1 = 1;	//RELAY1 on
			RELAY2 = 1;	//RELAY2 on
			RELAY4 = 1;	//RELAY4 on
			lock_state = true;
		}
		
		if((TOUCH2 == 1) && (lock_state == false)){
			RELAY3 = 1;		//RELAY3 on
			RELAY4 = 1;		//RELAY4 on
			lock_state = true;
		}
	
		if(P15 == 0){
			RELAY1 = 0;	//RELAY1 off
			RELAY2 = 0;	//RELAY2 off
			RELAY3 = 0;	//RELAY3 off
			RELAY4 = 0; //RELAY4 off
			lock_state = false;
		}
  }
}



