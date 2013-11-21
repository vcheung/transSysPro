#ifndef __FLASH_H
#define __FLASH_H

#include "stm32f10x.h"

void Flash_config(void);
int ReadHalfWord(unsigned long dwiAddr);

#endif	/* __FLASH_H */
