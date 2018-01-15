//Header Files for the Memory Game
//Function Declarations below
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Menu.h"
#include "Engine.h"
#include "Strike.h"
#include "Engine.h"
#include "Random.h"
#include "SimonSays.h"
#include "MorseCode.h"

void MemoryEngine (void);
void MemoryGame_Run(void);
void ProcessStage(uint8_t stagenum);
void DrawBig(uint8_t display);




