//Game File 
//Initializes all apsects of the Game
//Prepares the following:
//PE0, PE1, PE2, PE3 for input buttons
//PD0 PD1 PD2 PD7 for output LED
//PD6 for Morse Code Light
//PA2 and PA7 for LCD
//PE4 and PE5 for Joystick ADC
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "ADC.h"
#include "SysTick.h"
#include "UART.h"
#include "Random.h"

void GameInit(void)
{
	SYSCTL_RCGCGPIO_R|=0x1F;
	uint32_t delay=SYSCTL_RCGCGPIO_R;
	for(int i=0; i<1000; i++);

		//Initialize Simon Says Buttons
	GPIO_PORTE_DIR_R&=~0xF;
	GPIO_PORTE_DEN_R|=0xF;
		//Initialize Simon Says LED
	GPIO_PORTD_DIR_R|=0x4F;
	GPIO_PORTD_DEN_R|=0x4F;
	GPIO_PORTB_DIR_R|=0x81;
	GPIO_PORTB_DEN_R|=0x81;
	GPIO_PORTB_AFSEL_R&=~0x81;
	GPIO_PORTB_DATA_R|=0x1;
	GPIO_PORTD_DATA_R|=0x40;
	//GPIO_PORTB_DATA_R|=0x80;
	
		//Initialize LCD
	 ST7735_InitR(INITR_REDTAB);    
		//Initialize ADC
	//ERROR NO READ WRITE PERMISSIONS ON NEXT 2 Lines
		ADC_Init();
		//Initialize UART
			UART_Init();
		//Initialize Clocks
		SysTick_Init(2000000);		//initialize systick
		EdgeCounter_Init();
		Init_Tranfer();
		Random_Init(NVIC_ST_CURRENT_R);
	//Other Timers HERE

//	ST7735_FillScreen(0x0000); 

}

