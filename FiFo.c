// FiFo.c
// Runs on LM4F120/TM4C123
// Provide functions that implement the Software FiFo Buffer
// Last Modified: 4/10/2017 
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
#include "FiFo.h"
// --UUU-- Declare state variables for FiFo
//        size, buffer, put and get indexes
// *********** FiFo_Init**********
// Initializes a software FIFO of a
// fixed size and sets up indexes for
// put and get operations
int putInd;
int getInd;
int size;
char buffer[16]; // change to 16

// *********** FiFo_Init**********
// Initializes a software FIFO of a
// fixed size and sets up indexes for
// put and get operations
void FiFo_Init() {
// --UUU-- Complete this
	putInd=15;
	getInd=15;
	size= 15;
	//FIFOmail = 0;
}

// *********** FiFo_Put**********
// Adds an element to the FIFO
// Input: Character to be inserted
// Output: 1 for success and 0 for failure
//         failure is when the buffer is full
uint32_t FiFo_Put(char data) {
	if ( ((putInd-1)==getInd) || (putInd==0&&getInd==15) ){return(0);}
	if(putInd==0){putInd=16;}
   buffer[putInd-1] = data;
   putInd = (putInd-1);
	if(putInd ==0) {putInd=16;}
   return(1);

}

// *********** FiFo_Get**********
// Gets an element from the FIFO
// Input: Pointer to a character that will get the character read from the buffer
// Output: 1 for success and 0 for failure
//         failure is when the buffer is empty
uint32_t FiFo_Get(char *datapt){
	if (getInd == putInd) {
          return(0);
   }
   *datapt = buffer[getInd];
   getInd = (getInd-1);
	 if(getInd==-1)getInd=15;
   return(1);

}
