//Files for the Maze game
//Method Declarations below
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Menu.h"
#include "Engine.h"
#include "Strike.h"
#include "Engine.h"
#include "Random.h"
#include "SimonSays.h"


void Maze_Run(void);
void drawMaze(int8_t arr[6][6]);
void MoveUp(int8_t arr[6][6]);
void MoveDown(int8_t arr[6][6]);
void MoveLeft(int8_t arr[6][6]);
void MoveRight(int8_t arr[6][6]);
void CopyMaze(int8_t arr[6][6], int8_t arr1[6][6]);


