#include "data.h"
unsigned char sendData[50];
extern u8 I2c_Buf_Read[256];

void save_in_buffer(struct carData CAR, char ADweight)
{
//	u16 i;
	unsigned char count=0;

	sendData[count++]=0x01;	//从位机
	sendData[count++]=0x01;	//保留，功能位

	sendData[count++]=CAR.name[0];
	sendData[count++]=CAR.name[1];
	sendData[count++]=CAR.name[2];
	sendData[count++]=CAR.name[3];
	sendData[count++]=CAR.name[4];
	sendData[count++]=CAR.name[5];
	sendData[count++]=CAR.name[6];
	sendData[count++]=CAR.name[7];
	sendData[count++]=CAR.name[8];
	sendData[count++]=CAR.name[9];
	
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
	sendData[count++]=CAR.ID[10];
	sendData[count++]=CAR.ID[11];
	
	sendData[count++]=CAR.carID[0];
	sendData[count++]=CAR.carID[1];
	sendData[count++]=CAR.carID[2];
	sendData[count++]=CAR.carID[3];
	sendData[count++]=CAR.carID[4];
	sendData[count++]=CAR.carID[5];
	sendData[count++]=CAR.carID[6];
	sendData[count++]=CAR.carID[7];
	sendData[count++]=CAR.carID[8];
	sendData[count++]=CAR.carID[9];
	
	sendData[count++]=CAR.stWeight;
	
	sendData[count++]=ADweight;

	CRC16(sendData,count);

	sendData[count++]=crc16H;						
	sendData[count++]=crc16L;

//	printf("写入buffer的数据\n\r");
//    for ( i=0; i<=50; i++ ) //填充缓冲
//  	{   
//		printf("%c", sendData[i]);
//   	}
}

void replyA8(void)
{
	u16 i;
	for(i=0;i<50;i++)
		printf("%c",I2c_Buf_Read[i]);
}
