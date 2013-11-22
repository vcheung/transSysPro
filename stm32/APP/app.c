#include "includes.h"
#include "myConfig.h"

u8* SENDData;
static OS_STK led_task_stk[LED_TASK_STK_SIZE];	//定义栈
static OS_STK usart1_task_stk[USART1_TASK_STK_SIZE];	
static OS_STK ledDis_task_stk[LEDDIS_TASK_STK_SIZE];
static OS_STK adc1_task_stk[ADC1_TASK_STK_SIZE];
static OS_STK exti_task_stk[EXTI_TASK_STK_SIZE];
static OS_STK calculate_task_stk[CALCULATE_TASK_STK_SIZE];

void Task_START(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	adc_MBOX = OSMboxCreate((void *)0);
	key_SEM = OSSemCreate(0);
	keyDis_SEM = OSSemCreate(0);

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

void Task_USART1(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告
	while(1)
	{	
		unsigned char errkey;
		unsigned char num,err;
		u16 i;

		car1.name= "张三" ;
		car1.ID = "0123456789";
		car1.carID = "粤E12345";
		car1.stWeight = 10;
		car1.weight = 5;

//		SENDData= save_in_buffer(car1);  仍然有问题

		OSSemPend(key_SEM,0,&errkey);
		num = *(unsigned char*)OSMboxPend(adc_MBOX,0,&err);
		printf(" hello: %d",num);
		OSTimeDlyHMSM(0,0,0,500);
		
		/* 读写EEPROM */
	    I2c_Buf_Write = car1.name;
		printf("写入的数据\n\r");
	    for ( i=0; i<=255; i++ ) //填充缓冲
	  	{   
		    printf("%c", I2c_Buf_Write[i]);
	   	}
	
	  	//将I2c_Buf_Write中顺序递增的数据写入EERPOM中 
		I2C_EE_BufferWrite(I2c_Buf_Write, EEP_Firstpage, 256);
			 
		OSTimeDlyHMSM(0,0,0,500);

	  	printf("\n\r读出的数据\n\r");
	  	//将EEPROM读出数据顺序保持到I2c_Buf_Read中 
		I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, 256); 
	
	  	//将I2c_Buf_Read中的数据通过串口打印
		for (i=0; i<256; i++)
		{	
//			if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
//			{
//				printf("0x%02X ", I2c_Buf_Read[i]);
//				printf("错误:I2C EEPROM写入与读出的数据不一致\n\r");
//				return;
//			}
		    printf("%c", I2c_Buf_Read[i]);
	    }
		OSTimeDlyHMSM(0,0,0,500);

		/* 读写EEPROM */
	    I2c_Buf_Write = car1.ID;
		printf("写入的数据\n\r");
	    for ( i=0; i<=255; i++ ) //填充缓冲
	  	{   
		    printf("%c", I2c_Buf_Write[i]);
	   	}
	
	  	//将I2c_Buf_Write中顺序递增的数据写入EERPOM中 
		I2C_EE_BufferWrite(I2c_Buf_Write, EEP_Secondpage, 256);
			 
		OSTimeDlyHMSM(0,0,0,500);

	  	printf("\n\r读出的数据\n\r");
	  	//将EEPROM读出数据顺序保持到I2c_Buf_Read中 
		I2C_EE_BufferRead(I2c_Buf_Read, EEP_Secondpage, 256); 
	
	  	//将I2c_Buf_Read中的数据通过串口打印
		for (i=0; i<256; i++)
		{	
//			if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
//			{
//				printf("0x%02X ", I2c_Buf_Read[i]);
//				printf("错误:I2C EEPROM写入与读出的数据不一致\n\r");
//				return;
//			}
		    printf("%c", I2c_Buf_Read[i]);
	    }
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
//		 OSMboxPost(adc_MBOX,(void *)&ADC_ConvertedValueLocal);
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
		OSMboxPost(adc_MBOX,(void *)&sum);
		OSTimeDlyHMSM(0,0,0,500);
	}
}
