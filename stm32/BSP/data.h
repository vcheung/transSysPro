#ifndef __DATA_H__
#define __DATA_H__

#include "includes.h"

/* ½á¹¹Ìå */
struct carData
{
//	char name[8];
//	char ID[10];
//	char carID[8];

	char name[10];
	char ID[12];
	char carID[10];
	char stWeight;
	char weight;
};

void save_in_buffer(struct carData CAR, char ADweight);
void replyA8(void);

#endif
