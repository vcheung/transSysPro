#ifndef __Verify_H__
#define __Verify_H__


extern unsigned char  crc16L,crc16H;

void CRC16(unsigned char *MSG,unsigned short usDataLen);     //CRC计算
unsigned char Verify_DATA(unsigned char *str,unsigned short strlen);	//数据异或校验
unsigned char SUM_verify(unsigned char *buf,unsigned char leng); //和校验接收数据
#endif  
