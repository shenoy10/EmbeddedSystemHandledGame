//Password Files
#include "tm4c123gh6pm.h"
#include "SysTick.h"
#include "ST7735.h"
#include "random.h"
#include "MorseCode.h"
#include <stdint.h>
void Password_Run(void);
void drawLetters(void);
void DrawArrows(void);
uint8_t StrCmp(uint8_t arr[], uint8_t arr1[]);

