/**
  ******************************************************************************
  * 描述    ：下位机_
  *         
  * 实验平台：stm32f103c8t6
  * 硬件连接：------------------------
  *          | PA9  - USART1(Tx)      |
  *          | PA10 - USART1(Rx)      |
  *           ------------------------
  * 库版本  ：ST3.5.0
  * 作者    ：zhangwj   
  ******************************************************************************
  *  
  * 在我们的 main.c 文件中要把 stdio.h 这个头文件包含进来，还要在
  * 编译器中设置一个选项 Use MicroLIB (使用微库)，在 Options for target。
  * 这个微库是 keil MDK 为嵌入式应用量身定做的 C 库，我们要先具有库，才能重定向。
  * 勾选使用之后，我们就可以使用 printf() 这个函数了。
  *
  **/	
/* Includes ------------------------------------------------------------------*/
#include "includes.h"

static OS_STK startup_task_stk[STARTUP_TASK_STK_SIZE];	//定义栈

int main(void)
{
	BSP_Init();
	OSInit();
	OSTaskCreate(Task_START,(void *)0,
		&startup_task_stk[STARTUP_TASK_STK_SIZE-1],STARTUP_TASK_PRIO);

	OSStart();
	return 0;
}


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
