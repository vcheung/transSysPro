#ifndef __DATA_H__
#define __DATA_H__

#include "includes.h"

/* ½á¹¹Ìå */
struct carData
{
//	char name[8];
//	char ID[10];
//	char carID[8];

	u8 *name;
	u8 *ID;
	u8 *carID;
	u8 stWeight;
	u8 weight;
};

u8 *save_in_buffer(struct carData CAR);

#endif
