//Simon Says Files

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Menu.h"
#include "Engine.h"
#include "Strike.h"
#include "Engine.h"
#include "Random.h"
#include "SimonSays.h"
#include "UART.h"

#define red 0
#define blue 1
#define green 2
#define yellow 3
#define NoStrikeVowel 0
#define OneStrikeVowel 1
#define TwoStrikeVowel 2
#define NoStrike 3
#define OneStrike 4
#define TwoStrike 5
uint8_t Light1;
uint8_t Light2;
uint8_t Light3;
uint8_t Light4;
uint8_t correct=0;
uint32_t count;
uint32_t input;
uint32_t previous;


struct SimonSays
{

	uint8_t LightList[4];

};

typedef const struct SimonSays SimonSays_t;

const SimonSays_t LightMap[6]=
	{{{blue, red, yellow,green}},
	{{yellow, green, blue,red}},
	{{green, red, yellow,blue}},
	{{blue, yellow, green,red}},
	{{red, blue, yellow,green}},
	{{yellow, green, blue,red}}};
	
	void SimonSaysEngine(void)
	{		
			Random_Init(NVIC_ST_CURRENT_R);
		//This game will have 3 rounds
			Round();
			Round();
	}
	
	void Round(void)
	{
			
		do
		{
			//generate random lights and set correct to zero
			correct=0;
			ST7735_FillRect(0,35,128,160,0);
			ST7735_SetCursor(3,3);
			ST7735_OutString("Light Sequence...");
			Light1=RandomGeno();
			Light2=RandomGeno();
			Light3=RandomGeno();
			Light4=RandomGeno();
			//output light
				outLight(Light1);
				outLight(Light2);
				outLight(Light3);
				outLight(Light4);
			
					count=0;
					input=0;
					previous=0;
			
			
			ST7735_FillRect(0,35,128,160,0);
			ST7735_SetCursor(3,3);
			ST7735_OutString("Now Polling...");
			
			PollTheButtons(5000);
		
		
		
		
		
		}while(correct!=4);
		}
	 
	
uint8_t RandomGeno(void){
	
	uint8_t number=((Random())%4);

  return number;  // returns 0,1, 2, 3
	
	
}

void outLight(uint8_t Light)
{
	
	uint8_t output=0;
	
			switch(Light){
				case 0:
					output=1;
				Send(0xA0000);
					break;
				case 1:
					output=2;
				Send(0xB0000);
					break;
				case 3:
					output=4;
				Send(0xC0000);
					break;
				case 2:
					output=8;
				Send(0xD0000);
					break;
			}
		uint32_t out2= GPIO_PORTD_DATA_R;
			out2&=~0xF;
			out2|=output;
			GPIO_PORTD_DATA_R=out2;
			for(int i=0; i<4000000; i++)
			{}
			GPIO_PORTD_DATA_R&=~0xF;
			for(int i=0; i<4000000; i++)
			{}

}

uint8_t ProcessInput (uint8_t Lightin)
{
			uint8_t Param=0;
		
			if(serialVow==1&&strikes==0)
					Param=NoStrikeVowel;
			else if(serialVow==1&&strikes==1)
					Param=OneStrikeVowel;
			else if(serialVow==1&&strikes==2)
					Param=TwoStrikeVowel;
			else if(serialVow==0&&strikes==0)
					Param=NoStrike;
			else if(serialVow==0&&strikes==1)
					Param=OneStrike;
			else if(serialVow==0&&strikes==2)
					Param=TwoStrike;
			
			uint8_t val= LightMap[Param].LightList[Lightin];
			
						if(val==red)
						{
							return 1;
						}
						else if(val==blue)
						{
							return 2;
						}
						else if(val==yellow)
						{
							return 4;
						}
						else if(val==green)
						{
							return 8;
						}
						else
							return 0;


}

void drawLoad(uint32_t county)
{
				ST7735_FillRect(20,140,80-(80*county/5000),10,0x9999);
				ST7735_FillRect(100-(80*county/5000),140,100,10,0x0);
			

}

void PollTheButtons(uint32_t period)
{//Polling State for User Input
		while(count<=period)
		{
					drawLoad(count);
			
				input=GPIO_PORTE_DATA_R&0xF;
				if(input==0)
					previous=0;
				
			if(input!=0 && previous==0){
					if(correct==0 &&	input==ProcessInput(Light1))
						{	
								correct++;
								previous=input;
						}
					else if(correct==1 && input==ProcessInput(Light2))
					{
								correct++;
								previous=input;
					
					}
					else if(correct==2 && input==ProcessInput(Light3))
					{
								correct++;
								previous=input;
					
					}
					else if(correct==3 && input==ProcessInput(Light4))
					{
								correct++;
								previous=input;
					
					}
					else
					{
							AddStrike();
							break;
					}
				}
			
							if(correct==4)
							{
								ST7735_SetCursor(5,5);
								ST7735_OutString("CORRECT");
								for(int i=0; i<10000000; i++){};
								break;
							}
					count++;
		}



}





