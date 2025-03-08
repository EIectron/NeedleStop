/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


//***********************************************************************************************************
//  File Function: MS51 GPIO toggle demo code
//***********************************************************************************************************
#include "ms51_32k.h"

// LED1	P1.3
// LED2 P2.4
// TOUCH1 P2.5
// TOUCH2 P1.4
// RELAY1 P3.3
// RELAY2 P0.1
// RELAY3 P0.0
// RELAY4 P1.0
// RST-BTN P1.5


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
	
	
	P33 = 0;
	P01 = 0;
	P00 = 0;
	P10 = 0;
	
	Timer0_Delay(16000000,200,100);;
	
  while(1)
  {
		
		P13 = P25;	//LED1 = TOUCH1
		P24 = P14;	//LED2 = TOUCH2
		
		
		if(P25 == 1){
			P33 = 1;	//RELAY1 on
			P00 = 1;	//RELAY3 on
		}
		
		if(P14 == 1){
			P01	= 1;	//RELAY2 on
			P00 = 1;	//RELAY3 on
		}
	
		if(P15 == 0){
			P33 = 0;	//RELAY1 off
			P01	= 0;	//RELAY2 off
			P00 = 0;	//RELAY3 off
		}
  }
}



