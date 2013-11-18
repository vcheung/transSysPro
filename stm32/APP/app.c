#include "includes.h"

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

static OS_STK led_task_stk[LED_TASK_STK_SIZE];	//定义栈
static OS_STK usart1_task_stk[USART1_TASK_STK_SIZE];	
static OS_STK ledDis_task_stk[LEDDIS_TASK_STK_SIZE];
static OS_STK adc1_task_stk[ADC1_TASK_STK_SIZE];

void Task_START(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	adc_MBOX = OSMboxCreate((void *)0);

	OSTaskCreate(Task_LED,(void *)0,
		&led_task_stk[LED_TASK_STK_SIZE-1],LED_TASK_PRIO);

	OSTaskCreate(Task_USART1,(void *)0,
		&usart1_task_stk[USART1_TASK_STK_SIZE-1],USART1_TASK_PRIO);

	OSTaskCreate(Task_LEDDIS,(void *)0,
		&ledDis_task_stk[LEDDIS_TASK_STK_SIZE-1],LEDDIS_TASK_PRIO);

	OSTaskCreate(Task_ADC1,(void *)0,
		&adc1_task_stk[ADC1_TASK_STK_SIZE-1],ADC1_TASK_PRIO);

	while(1)
	{
		OSTimeDlyHMSM(0,0,0,10);
	}
}

void Task_LED(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	while(1)
	{
		LED1( ON );
		OSTimeDlyHMSM(0,0,0,500);
		LED1( OFF );

		LED2( ON );
		OSTimeDlyHMSM(0,0,0,500);
		LED2( OFF );

		LED3( ON );
		OSTimeDlyHMSM(0,0,0,500);
		LED3( OFF );
	}
}

void Task_USART1(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	
	while(1)
	{
		unsigned char num,err;
		num = *(unsigned char*)OSMboxPend(adc_MBOX,0,&err);
		printf(" hello: %d",num);
		OSTimeDlyHMSM(0,0,0,500);
	}
}

void Task_LEDDIS(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	while(1)
	{
		u8 a,b,c,d;						//定义a,b,c,d四个变量用来存放数码管各个位的值
	
		a = ADC_ConvertedValueLocal /1000;						//千位值存入a
		b = ADC_ConvertedValueLocal % 1000 /100;				//百位值存入b
		c = ADC_ConvertedValueLocal % 1000 % 100 /10;			//十位值存入c
		d = ADC_ConvertedValueLocal % 1000 % 100 % 10;		    //个位值存入d

		GPIO_SetBits(GPIOB , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);     
//		Refresh_LED(1234);
		GPIO_ResetBits(GPIOB , GPIO_Pin_12);			//数码管0位位选脚相连引脚置低，使能位0
		data_shift(LEDData[d]);			//将个位数值对应的编码送入数码管数据管脚
		OSTimeDlyHMSM(0,0,0,3);

		GPIO_SetBits(GPIOB , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);     
//		Refresh_LED(1234);
		GPIO_ResetBits(GPIOB , GPIO_Pin_13);			//数码管0位位选脚相连引脚置低，使能位0
		data_shift(LEDData[c]);			//将个位数值对应的编码送入数码管数据管脚
		OSTimeDlyHMSM(0,0,0,3);

		GPIO_SetBits(GPIOB , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);     
//		Refresh_LED(1234);
		GPIO_ResetBits(GPIOB , GPIO_Pin_14);			//数码管0位位选脚相连引脚置低，使能位0
		data_shift(LEDData[b]);			//将个位数值对应的编码送入数码管数据管脚
		OSTimeDlyHMSM(0,0,0,3);

		GPIO_SetBits(GPIOB , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);     
//		Refresh_LED(1234);
		GPIO_ResetBits(GPIOB , GPIO_Pin_15);			//数码管0位位选脚相连引脚置低，使能位0
		data_shift(LEDData[a]);			//将个位数值对应的编码送入数码管数据管脚
		OSTimeDlyHMSM(0,0,0,3);
	}
}

void Task_ADC1(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	while(1)
	{
		 ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*10;
		 OSMboxPost(adc_MBOX,(void *)&ADC_ConvertedValueLocal);
		 OSTimeDlyHMSM(0,0,0,500);
	}
}
