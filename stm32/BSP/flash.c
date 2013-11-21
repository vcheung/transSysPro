#include "flash.h"

void Flash_config(void)
{
	/* ¿ªÆô HSI */
	RCC_HSICmd(ENABLE);
}

int ReadHalfWord(unsigned long dwiAddr)
{
	unsigned short data;
	unsigned short *ptrFlash;

	ptrFlash=(unsigned short *)(dwiAddr);
	data=*ptrFlash;
	return (int)(unsigned int)data;
}
