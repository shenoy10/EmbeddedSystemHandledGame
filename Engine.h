//Lists header files for the engine
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Menu.h"
#include "Game.h"

extern uint8_t serialVow;
void Engine_Run(void);
void LevelInit(void);
void LevelOneRun (void);
void LevelTwoRun (void);
void LevelThreeRun (void);
void LevelFourRun (void);
void myClock(void);
void Transit(void);
void Win (void);


