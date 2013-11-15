#include "includes.h"

static OS_STK led_task_stk[LED_TASK_STK_SIZE];	//定义栈
static OS_STK usart1_task_stk[USART1_TASK_STK_SIZE];	//定义栈

void Task_START(void *p_arg)
{
	(void)p_arg;	//'p_arg'没有用到，防止编译器警告

	OSTaskCreate(Task_LED,(void *)0,
		&led_task_stk[LED_TASK_STK_SIZE-1],LED_TASK_PRIO);

	OSTaskCreate(Task_USART1,(void *)0,
		&usart1_task_stk[USART1_TASK_STK_SIZE-1],USART1_TASK_PRIO);

	while(1)
	{
		OSTimeDlyHMSM(0,0,0,500);
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
		 printf(" hello ");
		 OSTimeDlyHMSM(0,0,0,500);
	}
}
