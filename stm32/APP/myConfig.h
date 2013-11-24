#ifndef __MYCONFIG_H__
#define __MYCONFIG_H__

/* 数码管 */
#define	SH		(0x01 << 0)					   //数码管小数点的编码
#define	SG		(0x01 << 1)					   //数码管G段的编码
#define	SF		(0x01 << 2)					   //数码管F段的编码
#define	SE		(0x01 << 3)					   //数码管E段的编码
#define	SD		(0x01 << 4)					   //数码管D段的编码
#define	SC		(0x01 << 5)					   //数码管C段的编码
#define	SB		(0x01 << 6)					   //数码管B段的编码
#define	SA		(0x01 << 7)					   //数码管A段的编码

const u8 LEDData[] =
{
	SA |SB |SC | SD |SE |SF,		    // 0的编码
	SB | SC,						    //01的编码
	SA |SB |SG | SE | SD,			    //02的编码
	SA |SB |SC | SD | SG,			    //03的编码
	SB |SF | SG | SC,				    //04的编码
	SA |SF |SG |SC  | SD,			    //05的编码
	SA |SC | SD | SE | SG | SF,	        //06的编码
	SA | SB| SC,					    //07的编码
	SA |SB |SC | SD | SE | SF | SG,     //08的编码
	SA |SB |SC|SD | SF | SG	,	        //09的编码	
};

/* ADC */
u8 ADC_ConvertedValueLocal;        
extern __IO uint16_t ADC_ConvertedValue;
extern OS_EVENT* adc_MBOX;

/* 按键 */
extern OS_EVENT* key_SEM;
extern OS_EVENT* keyDis_SEM;

/* eeprom */
#define  EEP_Firstpage      0x00
#define  EEP_Secondpage     0x01
//u8 I2c_Buf_Write[256];
u8 I2c_Buf_Read[256];
u8 I2c_Buf_Write[256];
//u8 *I2c_Buf_Read;

/* 全局变量 */
unsigned int sum=0;
struct carData car1={ "张三" , "0123456789" , "粤E12345" , 10 };

#endif
