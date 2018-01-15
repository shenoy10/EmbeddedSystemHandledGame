//Morse Code Header File
//Plays Morse Code with 

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Menu.h"
#include "Engine.h"
#include "Strike.h"
#include "Engine.h"
#include "Random.h"
#include "SimonSays.h"


void MorseCodeEngine(void);
void Dash (void);
void Dot(void);
void Space (void);
void TollIt(void);
void MakeIt(void);
void BowlIt(void);
void FoolIt(void);
void DrawHertz(void);
void FakeIt(void);
uint8_t Rando(void);
void DrawLoad(uint32_t ct);

