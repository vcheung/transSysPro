#include "includes.h"
/*
 * 函数名：SysTick_Init
 * 描述  ：配置SysTick定时器
 */
void SysTick_Init(void)
{
	SysTick_Config(SystemCoreClock/OS_TICKS_PER_SEC);	//初始化并使能SysTick定时器
}

/*
 * 函数名：BSP
 * 描述  ：时钟初始化、硬件初始化
 */
 void BSP_Init(void)
{
 	SystemInit();					/* 配置系统时钟为72MHz */
	SysTick_Init();					/* 初始化并使能SysTick定时器 */
	LED_GPIO_config();				/* LED端口初始化 */
	USART1_Config();				/* 串口 */
	LEDDIS_GPIO_Configuration();	/* 数码管 */
	ADC1_Init();					/* ADC1 */
}
