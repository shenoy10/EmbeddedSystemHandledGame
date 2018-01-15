//Simon Says headers
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Menu.h"
#include "Engine.h"
#include "Strike.h"
#include "Engine.h"
#include "Random.h"

void SimonSaysEngine(void);
void Round(void);
uint8_t RandomGeno(void);
void outLight(uint8_t Light);
uint8_t ProcessInput(uint8_t Lightin);
void drawLoad(uint32_t county);
void PollTheButtons(uint32_t period);
