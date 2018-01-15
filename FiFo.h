//FiFo Declarations
//Listed Below
#include <stdint.h>

void FiFo_Init(void);

uint32_t FiFo_Put(char data);

uint32_t FiFo_Get(char *datapt);

