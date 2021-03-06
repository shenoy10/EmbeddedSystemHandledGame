// SpaceInvaders.c
// Runs on LM4F120/TM4C123
// Jonathan Valvano and Daniel Valvano
// This is a starter project for the EE319K Lab 10

// Last Modified: 3/6/2015 
// http://www.spaceinvaders.de/
// sounds at http://www.classicgaming.cc/classics/spaceinvaders/sounds.php
// http://www.classicgaming.cc/classics/spaceinvaders/playguide.php
/* This example accompanies the books
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014

   "Embedded Systems: Introduction to Arm Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2014

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
// ******* Possible Hardware I/O connections*******************
// Slide pot pin 1 connected to ground
// Slide pot pin 2 connected to PE2/AIN1
// Slide pot pin 3 connected to +3.3V 
// fire button connected to PE0
// special weapon fire button connected to PE1
// 8*R resistor DAC bit 0 on PB0 (least significant bit)
// 4*R resistor DAC bit 1 on PB1
// 2*R resistor DAC bit 2 on PB2
// 1*R resistor DAC bit 3 on PB3 (most significant bit)
// LED on PB4
// LED on PB5

// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO), high for data, low for command
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "TExaS.h"
#include "ADC.h"
#include "Game.h"
#include "Menu.h"
#include "Engine.h"
#include "PLL.h"
#include "SysTick.h"
#include "UART.h"


void Delay100ms(uint32_t count); // time delay in 0.1 seconds
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts



// *************************** Capture image dimensions out of BMP**********

int main(void){
 // TExaS_Init();  // set system clock to 80 MHz
 // Random_Init(1);
	
	PLL_Init();
	GameInit();
	EnableInterrupts();
	Engine_Run();

	/*
	while(1)
	{
		if(GPIO_PORTE_DATA_R==0x1)
		{	Send(0xA0000);
		
		
		}
		for(int i=0; i<100000; i++)
		{}
	}*/
	
	
	
	
	//ADC and Button test
	/*
	while(1)
	{
		
			
				ST7735_SetCursor(2,1);
				LCD_OutDec(adcMail[0]);
				ST7735_SetCursor(2,2);
				LCD_OutDec(adcMail[1]);	

			while(adcMail[0]<1700)
			{GPIO_PORTD_DATA_R|=0x2;
			}
			while(adcMail[0]>3000)
			{GPIO_PORTD_DATA_R|=0x8;
			}
			while(adcMail[1]<1700)
			{GPIO_PORTD_DATA_R|=0x1;
		
			}
			while(adcMail[1]>3000)
			{GPIO_PORTD_DATA_R|=0x4;
			}
		
		while((GPIO_PORTE_DATA_R&0x1)==1){
				GPIO_PORTD_DATA_R|=0x1;	}
		while((GPIO_PORTE_DATA_R&0x2)==2){
				GPIO_PORTD_DATA_R|=0x2;	}
		while((GPIO_PORTE_DATA_R&0x4)==4){
				GPIO_PORTD_DATA_R|=0x4;	}
		while((GPIO_PORTE_DATA_R&0x8)==8){
				GPIO_PORTD_DATA_R|=0x08;	}
		
		
		
		
		
			}*/
			
			
			
		}

	

		
		/*

  Delay100ms(50);              // delay 5 sec at 80 MHz


  ST7735_FillScreen(0x0000);            // set screen to black
  ST7735_SetCursor(1, 1);
  ST7735_OutString("GAME OVER");
  ST7735_SetCursor(1, 2);
  ST7735_OutString("Nice try,");
  ST7735_SetCursor(1, 3);
  ST7735_OutString("Earthling!");
  ST7735_SetCursor(2, 4);
  LCD_OutDec(1234);
  while(1){
  }

}


// You can use this timer only if you learn how it works

void Delay100ms(uint32_t count){uint32_t volatile time;
  while(count>0){
    time = 727240;  // 0.1sec at 80 MHz
    while(time){
	  	time--;
    }
    count--;
  }*/
//}
