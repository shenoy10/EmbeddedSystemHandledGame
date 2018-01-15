//Password Files
#include "tm4c123gh6pm.h"
#include "SysTick.h"
#include "ST7735.h"
#include "random.h"
#include "MorseCode.h"
#include "SysTick.h"
#include "Password.h"
#include "UART.h"
#include <stdint.h>

const unsigned short arrowdown[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF,
 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x23FF, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F,
 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F,
 0x0E5F, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF,
 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};
const unsigned short arrowup[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF, 0x23FF, 0x23FF,
 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F,
 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF,
 0x0E5F, 0x0E5F, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x0E5F, 0x0E5F,
 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0E5F, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};


uint8_t myGuess=7;
uint8_t correctPass;
uint8_t SelectX=0;
uint8_t SelectY=0;
uint8_t daGuess[5];
uint32_t myAnimationCount=0;
uint8_t myWord[]={'T','H','I','N','V'};
uint8_t bom[5][5]=
{
	{'T','H','I','N','K'},
	{'T','H','I','N','G'},
	{'F','O','U','N','D'},
	{'T','H','R','E','E'},
	{'W','A','T','E','R'}};

uint8_t myPasswords[5][6]=
	{{'T','F','W','G','Q','C'},
	{'H','O','A','K','J','P'},
	{'I','U','R','T','L','M'},
	{'N','E','K','G','Z','Y'},
	{'V','B','M','C','M','Q'}};

	void Password_Run(void)
	{
		Random_Init(NVIC_ST_CURRENT_R);
		uint8_t mySpecial=Rando();
		correctPass=0;
		ST7735_FillRect(0,30,128,160,0);
		switch(mySpecial)
		{
		case 0:
				myPasswords[4][2]='K';
				break;
		case 1:
				myPasswords[4][2]='G';
				break;
		case 2:
				myPasswords[4][2]='D';
				break;
		case 3:
				myPasswords[4][2]='E';
				break;
		case 4:
				myPasswords[4][2]='R';
				break;
		
		}
		uint32_t j=0;
		ST7735_FillRect(0,65,128,40,0x07E0);
		ST7735_FillRect(0,60,128,5,0x8673);
		ST7735_FillRect(0,105,128,5,0x8673);
		
		for(int i=3; i<120; i+=25)
		{
		ST7735_DrawCharS(i,70,myPasswords[j][0],0x0,0x7E0,4);
			j++;
		}
		DrawArrows();
		
		do
		{
			myAnimationCount=0;
			
			while(myAnimationCount<2000)
			{
					DrawArrows();
				if(adcMail[1]>3000)
				{
						if(SelectX<4)
						{
							Send(0xC000);
						SelectX++;
						ST7735_FillRect(0,40,128,15,0);
						ST7735_FillRect(0,110,128,15,0);
						DrawArrows();
							for(int i=0; i<3000000; i++){}
						}
				
				}
				else if(adcMail[1]<1700)
				{
						if(SelectX>0)
						{
							Send(0xC000);
						SelectX--;
						ST7735_FillRect(0,40,128,15,0);
						ST7735_FillRect(0,110,128,15,0);
						DrawArrows();
						for(int i=0; i<3000000; i++){}
						}
				}
			
				if(adcMail[0]>3000)
				{
					Send(0xC000);
						SelectY++;
						SelectY=SelectY%6;
						drawLetters();
						for(int i=0; i<3000000; i++){}
						
				
				}
		
					if(adcMail[0]<1700)
				{	Send(0xC000);
					if(SelectY>0)
					{
						SelectY--;
						drawLetters();
						for(int i=0; i<3000000; i++){}
					}
					else
					{
					SelectY=5;
					drawLetters();
						for(int i=0; i<3000000; i++){}
					}
				
				}
					myAnimationCount++;
			
				if((GPIO_PORTE_DATA_R&0xF)!=0)
				{
					if(StrCmp(myWord,bom[mySpecial])==1)
						correctPass=1;
					else
					{AddStrike();
						for(int i=0; i<2000000; i++){}
					}
					
					/*
						switch(mySpecial)
						{
							case 0:
								if(StrCmp(myWord,daGuess[)==1)
									correctPass=1;
								else
									AddStrike();
								break;
							case 1:
								if(StrCmp(myWord,daGuess)==1)
									correctPass=1;
								else
									AddStrike();
								break;
							case 2:
								if(StrCmp(myWord,daGuess)==1)
									correctPass=1;
								else
									AddStrike();
								break;
							case 3:
								if(StrCmp(myWord,daGuess)==1)
									correctPass=1;
								else
									AddStrike();
								break;
									case 4:
								if(StrCmp(myWord,daGuess)==1)
									correctPass=1;
								else
									AddStrike();
								break;
						*/
						
						
						
						
						
						
						
						
						
						
						
				
				
				}
			
			
			
			
			
			
			}
			
			
		
		
		
		}while(correctPass==0);
		
		
		
	
		ST7735_FillRect(0,30,128,160,0);
		ST7735_SetCursor(5,7);
		ST7735_OutString("CORRECT!");
	
	
	}
	
	
	
	
	void drawLetters(void)
	{
				
		
				switch(SelectX)
				{
					case 0:
						ST7735_DrawCharS(3,70,myPasswords[SelectX][SelectY],0x0,0x7E0,4);
						myWord[0]=myPasswords[SelectX][SelectY];
					break;
					case 1:
						ST7735_DrawCharS(28,70,myPasswords[SelectX][SelectY],0x0,0x7E0,4);
						myWord[1]=myPasswords[SelectX][SelectY];
					break;
					case 2:
						ST7735_DrawCharS(53,70,myPasswords[SelectX][SelectY],0x0,0x7E0,4);
						myWord[2]=myPasswords[SelectX][SelectY];
					break;
					case 3:
						ST7735_DrawCharS(78,70,myPasswords[SelectX][SelectY],0x0,0x7E0,4);
						myWord[3]=myPasswords[SelectX][SelectY];
					break;
				case 4:
						ST7735_DrawCharS(103,70,myPasswords[SelectX][SelectY],0x0,0x7E0,4);
				myWord[4]=myPasswords[SelectX][SelectY];
					break;
				
				
				
				}
	
	
	
	
	}	
		
void DrawArrows(void)
{			
	
	if(myAnimationCount<1000)
	{
		switch(SelectX)
		{
			
			case 0:
		ST7735_DrawBitmap(7,55,arrowup,13,13);
		ST7735_DrawBitmap(7,125,arrowdown,13,13);
			break;
			case 1:
		ST7735_DrawBitmap(32,55,arrowup,13,13);
		ST7735_DrawBitmap(32,125,arrowdown,13,13);
			break;
			case 2:
		ST7735_DrawBitmap(57,55,arrowup,13,13);
		ST7735_DrawBitmap(57,125,arrowdown,13,13);
			break;
			case 3:
		ST7735_DrawBitmap(84,55,arrowup,13,13);
		ST7735_DrawBitmap(84,125,arrowdown,13,13);
			break;
			case 4:
		ST7735_DrawBitmap(108,55,arrowup,13,13);
		ST7735_DrawBitmap(108,125,arrowdown,13,13);
			break;
			
		}
	}else
	{
	switch(SelectX)
		{
			
			case 0:
		ST7735_DrawBitmap(7,54,arrowup,13,13);
		ST7735_DrawBitmap(7,126,arrowdown,13,13);
			break;
			case 1:
		ST7735_DrawBitmap(32,54,arrowup,13,13);
		ST7735_DrawBitmap(32,126,arrowdown,13,13);
			break;
			case 2:
		ST7735_DrawBitmap(57,54,arrowup,13,13);
		ST7735_DrawBitmap(57,126,arrowdown,13,13);
			break;
			case 3:
		ST7735_DrawBitmap(84,54,arrowup,13,13);
		ST7735_DrawBitmap(84,126,arrowdown,13,13);
			break;
			case 4:
		ST7735_DrawBitmap(108,54,arrowup,13,13);
		ST7735_DrawBitmap(108,126,arrowdown,13,13);
			break;
			
		}
	
	
	
	
	
	}
	
	
	
	
}

uint8_t StrCmp(uint8_t arr[], uint8_t arr1[])
{
		for(int i=0; i<5; i++)
	{
			if(arr[i]!=arr1[i])
				return 0;
	
	
	}

		return 1;


}


	

