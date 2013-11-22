#include "data.h"

u8 *save_in_buffer(struct carData CAR)
{
	u8 *sendData;
	unsigned char count=0;
	sendData[count++]=CAR.name[0];
	sendData[count++]=CAR.name[1];
	sendData[count++]=CAR.name[2];
	sendData[count++]=CAR.name[3];
	sendData[count++]=CAR.name[4];
	sendData[count++]=CAR.name[5];
	sendData[count++]=CAR.name[6];
	sendData[count++]=CAR.name[7];
	
	sendData[count++]=CAR.ID[0];
	sendData[count++]=CAR.ID[1];
	sendData[count++]=CAR.ID[2];
	sendData[count++]=CAR.ID[3];
	sendData[count++]=CAR.ID[4];
	sendData[count++]=CAR.ID[5];
	sendData[count++]=CAR.ID[6];
	sendData[count++]=CAR.ID[7];
	sendData[count++]=CAR.ID[8];
	sendData[count++]=CAR.ID[9];
	
	sendData[count++]=CAR.carID[0];
	sendData[count++]=CAR.carID[1];
	sendData[count++]=CAR.carID[2];
	sendData[count++]=CAR.carID[3];
	sendData[count++]=CAR.carID[4];
	sendData[count++]=CAR.carID[5];
	sendData[count++]=CAR.carID[6];
	sendData[count++]=CAR.carID[7];
	
	sendData[count++]=CAR.stWeight;
	
	sendData[count++]=CAR.weight;

	return sendData;
}
