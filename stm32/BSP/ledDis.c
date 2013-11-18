/**************************************************************************
 * 文件名  ：ledDis.c
 * 描述    ：。         
 * 实验平台：stm32f103c8t6
 * 硬件连接：------------------------
 *          | PB10 - DATA	         |
 *          | PB11 - CLK	         |
 *          | PB12 - LED EN0	     |
 *          | PB13 - LED EN1         |
 *          | PB14 - LED EN2         |
 *          | PB15 - LED EN3         |
 *           ------------------------
 * 库版本  ：ST3.5.0
 * 作者    ：zhangwj 
**********************************************************************************/
#include "ledDis.h"

/*******************************************************************************
* 函数名  		: GPIO_Configuration
* 函数描述    	: 设置各GPIO端口功能
* 输入参数      : 无
* 输出结果      : 无
* 返回值        : 无
*******************************************************************************/

void LEDDIS_GPIO_Configuration(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
	/* 打开APB2总线上的GPIOB时钟*/
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  	GPIO_Init(GPIOB , &GPIO_InitStructure);

    GPIO_SetBits(GPIOB , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
}

/*
**********************************************************************************
                               data_shift函数

函数功能：通过8次循环，将一个8位数据移位到数据移位器（数据移位器的数据输出脚连接数
          码管的数据引脚）74HC164是出入并出的数据移位器

入口参数：dat  需要移位的数据的编码 
返回值  ：无
备注    ：无
**********************************************************************************
*/
void data_shift(u8 dat)				
{										
	u8 i;							//定义局部变量i，用作循环计数 
	for(i=0; i<8; i++)					//循环8次
	{
		GPIO_ResetBits(GPIOB , GPIO_Pin_11);				//移位器CLK引脚置低

		if(dat & 0x01){					//如果dat的末位为1
			GPIO_ResetBits(GPIOB , GPIO_Pin_10);			//移位器DATA引脚置低{共阳数码管，低电平有效}
		}
		else{							//如果dat的末位为0
			GPIO_SetBits(GPIOB , GPIO_Pin_10);		    //移位器DATA引脚置高
		}
		
		GPIO_SetBits(GPIOB , GPIO_Pin_11);				//移位器CLK引脚置高，dat的一位被移位成功至对应数据脚
			
		dat >>= 1;						//dat右移一位，为移位临位做准备
	}	
}	

/*
**********************************************************************************
                               Refresh_LED函数

函数功能：刷新数码管的显示数字，每次执行该函数，点亮数码管的其中的一位
      
入口参数：dat 数码管要显示的数值 
返回值  ：无
备注    ：无
**********************************************************************************
*/
//void Refresh_LED(u16 dat)
//{
//	static u8 i = 0;					//定义局部静态变量i，
//	u8 a,b,c,d;						//定义a,b,c,d四个变量用来存放数码管各个位的值
//
//	a = dat /1000;						//千位值存入a
//	b = dat % 1000 /100;				//百位值存入b
//	c = dat % 1000 % 100 /10;			//十位值存入c
//	d = dat % 1000 % 100 % 10;		    //个位值存入d
//	
//
//	switch(i)							
//	{									
//		case 0:							//i=0
//		i++;							//i加1，i=0
//		GPIO_ResetBits(GPIOB , GPIO_Pin_12);			//数码管0位位选脚相连引脚置低，使能位0
//		data_shift(LEDData[d]);			//将个位数值对应的编码送入数码管数据管脚
//		break;
//			
//		case 1:						   	//i=1
//		i++;							//i加1，i=1
//		GPIO_ResetBits(GPIOB , GPIO_Pin_13);				//数码管1位位选脚相连引脚置低，使能位1
//		data_shift(LEDData[c]);			//将十位数值对应的编码送入数码管数据管脚
//		break;
//			
//		case 2:							   //i=2
//		i++;							   //i加1，i=2
//		GPIO_ResetBits(GPIOB , GPIO_Pin_14);			       //数码管2位位选脚相连引脚置低，使能位2
//		data_shift(LEDData[b]);			//将百位数值对应的编码送入数码管数据管脚
//		break;
//										
//		case 3:						   	//i=3
//		i = 0;							//i归0，准备下次扫描位0 
//		GPIO_ResetBits(GPIOB , GPIO_Pin_15);				//数码管3位位选脚相连引脚置低，使能位3
//		data_shift(LEDData[a]);			//将千位数值对应的编码送入数码管数据管脚
//		break;
//	}
//}


/*
**********************************************************************************
                               Test_LED函数

函数功能：数码管的每一段包括小数点都亮，测试数码管的每一段是否有损坏
      
入口参数：无 
返回值  ：无
备注    ：无
**********************************************************************************
*/
//void Test_LED(void)
//{
//	static u8 i = 0;					//定义局部静态变量i，
//	u8 a,b,c,d;						//定义a,b,c,d四个变量用来存放数码管各个位的值
//
//	a = 8;						//千位值存入a
//	b = 8;				//百位值存入b
//	c = 8;			//十位值存入c
//	d = 8;		    //个位值存入d
//	
//
//	switch(i)							
//	{									
//		case 0:							//i=0
//		i++;							//i加1，i=0
//		GPIO_ResetBits(GPIOB , GPIO_Pin_12);			//数码管0位位选脚相连引脚置低，使能位0
//		data_shift(LEDData[d] | SH);			//将个位数值对应的编码加上小数点送入数码管数据管脚
//		break;
//			
//		case 1:						   	//i=1
//		i++;							//i加1，i=1
//		GPIO_ResetBits(GPIOB , GPIO_Pin_13);				//数码管1位位选脚相连引脚置低，使能位1
//		data_shift(LEDData[c] | SH);			//将十位数值对应的编码加上小数点送入数码管数据管脚
//		break;
//			
//		case 2:							   //i=2
//		i++;							   //i加1，i=2
//		GPIO_ResetBits(GPIOB , GPIO_Pin_14);			       //数码管2位位选脚相连引脚置低，使能位2
//		data_shift(LEDData[b] | SH);			//将百位数值对应的编码加上小数点送入数码管数据管脚
//		break;
//										
//		case 3:						   	//i=3
//		i = 0;							//i归0，准备下次扫描位0 
//		GPIO_ResetBits(GPIOB , GPIO_Pin_15);				//数码管3位位选脚相连引脚置低，使能位3
//		data_shift(LEDData[a] | SH);			//将千位数值对应的编码加上小数点送入数码管数据管脚
//		break;
//	}
//}
