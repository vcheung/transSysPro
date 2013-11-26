#include "includes.h"
#include "myConfig.h"
#include <string.h>

extern char sendData[50];
char RxBuffer1[10];
char RxCounter1=0;

unsigned char Receiver_Control=0;  //接收控制信号
unsigned char Receiver_Spare=0;    //接收备用 

static OS_STK led_task_stk[LED_TASK_STK_SIZE];	//定义栈
static OS_STK usart1_task_stk[USART1_TASK_STK_SIZE];	
static OS_STK ledDis_task_stk[LEDDIS_TASK_STK_SIZE];
static OS_STK adc1_task_stk[ADC1_TASK_STK_SIZE];
static OS_STK exti_task_stk[EXTI_TASK_STK_SIZE];
static OS_STK calculate_task_stk[CALCULATE_TASK_STK_SIZE];
static OS_STK A8connect_task_stk[A8CONNECT_TASK_STK_SIZE];

void Task_START(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	adc_MBOX = OSMboxCreate((void *)0);
	key_SEM = OSSemCreate(0);
	keyDis_SEM = OSSemCreate(0);
	A8_SEM = OSSemCreate(0);

	OSTaskCreate(Task_LED,(void *)0,
		&led_task_stk[LED_TASK_STK_SIZE-1],LED_TASK_PRIO);

	OSTaskCreate(Task_USART1,(void *)0,
		&usart1_task_stk[USART1_TASK_STK_SIZE-1],USART1_TASK_PRIO);

	OSTaskCreate(Task_LEDDIS,(void *)0,
		&ledDis_task_stk[LEDDIS_TASK_STK_SIZE-1],LEDDIS_TASK_PRIO);

	OSTaskCreate(Task_ADC1,(void *)0,
		&adc1_task_stk[ADC1_TASK_STK_SIZE-1],ADC1_TASK_PRIO);

	OSTaskCreate(Task_EXTI,(void *)0,
		&exti_task_stk[EXTI_TASK_STK_SIZE-1],EXTI_TASK_PRIO);

	OSTaskCreate(Task_CALCULATE,(void *)0,
		&calculate_task_stk[CALCULATE_TASK_STK_SIZE-1],CALCULATE_TASK_PRIO);

	OSTaskCreate(Task_A8CONNECT,(void *)0,
		&A8connect_task_stk[A8CONNECT_TASK_STK_SIZE-1],A8CONNECT_TASK_PRIO);

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

		LED4( ON );
		OSTimeDlyHMSM(0,0,0,500);
		LED4( OFF );
	}
}

/* 按键按下，写入EEPROM */
void Task_USART1(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	while(1)
	{	
		unsigned char errkey, err;
//		u16 i;
		
//		printf("等待A8");

		OSSemPend(key_SEM,0,&errkey);

		//将car1数据保存至buffer并串口输出
		weight = (char*)OSMboxPend(adc_MBOX,0,&err);		
		save_in_buffer(car1,*weight);
		
		/* 读写EEPROM */	
	  	//将I2c_Buf_Write中顺序递增的数据写入EERPOM中 
		I2C_EE_BufferWrite((u8 *)sendData, EEP_Firstpage, 256);
			 
		OSTimeDlyHMSM(0,0,0,500);

//	  	printf("\n\r读出eeprom的数据\n\r");
	  	//将EEPROM读出数据顺序保持到I2c_Buf_Read中 
//		I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, 256); 
	
	  	//将I2c_Buf_Read中的数据通过串口打印
//		for (i=0; i<=50; i++)
//		{	
//		    printf("%c", I2c_Buf_Read[i]);
//	    }
//		OSTimeDlyHMSM(0,0,0,500);
	}
}

/* 与A8通信 */
void Task_A8CONNECT(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告

	while(1)
	{
		unsigned char errA8;
//		unsigned int i=0;
//		printf("A8_wait");
//		for(i=0;i<10;i++)
//		{
//			printf("%c",RxBuffer1[i]);
//		}
		OSSemPend(A8_SEM,0,&errA8);
//		printf("A8_in");
//  		
//   		if(RxBuffer1[0]!=0x01)
//   		{
//   			for(i=0;i<10;i++)
// 				RxBuffer1[i]=0;
//   			RxCounter1=0;
//   		}
		CRC16((unsigned char *)RxBuffer1,5);
			
//		printf("16H:%c,16L:%c",crc16H,crc16L);
//		
//		for(i=0;i<10;i++)
//			printf("%c",RxBuffer1[i]);

		if(crc16L==RxBuffer1[6]&&crc16H==RxBuffer1[5])	  
		{
			//将EEPROM读出数据顺序保持到I2c_Buf_Read中
			I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, 256); 

			Receiver_Control=RxBuffer1[2];
  			Receiver_Spare=RxBuffer1[3];
//			printf("OK!886");
			replyA8();
		}		
		OSTimeDlyHMSM(0,0,0,500);
	}
}

void Task_LEDDIS(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告

	while(1)
	{
		u8 a,b,c,d;						//定义a,b,c,d四个变量用来存放数码管各个位的值

		a = sum /1000;						//千位值存入a
		b = sum % 1000 /100;				//百位值存入b
		c = sum % 1000 % 100 /10;			//十位值存入c
		d = sum % 1000 % 100 % 10;		    //个位值存入d

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
		 OSMboxPost(adc_MBOX,&ADC_ConvertedValueLocal);
		 OSTimeDlyHMSM(0,0,0,500);
	}
}

void Task_EXTI(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	while(1)
	{
		OSTimeDlyHMSM(0,0,0,500);
	}
}

void Task_CALCULATE(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告

	while(1)
	{
		unsigned char errkey;
		OSSemPend(keyDis_SEM,0,&errkey);

		sum=sum+ADC_ConvertedValueLocal;
		OSTimeDlyHMSM(0,0,0,500);
	}
}
