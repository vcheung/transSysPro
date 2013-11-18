#ifndef __LEDDIS_H__
#define __LEDDIS_H__

#include "stm32f10x.h"

void LEDDIS_GPIO_Configuration(void);
void Refresh_LED(u16 dat);

void data_shift(u8 dat);

#endif /* __LEDDIS_H__ */
