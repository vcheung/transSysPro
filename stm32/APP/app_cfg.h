#ifndef __APP_CFG_H__
#define __APP_CFG_H__

/*******	设置任务优先级	*******/
#define	STARTUP_TASK_PRIO		4
#define	LED_TASK_PRIO			5
#define	USART1_TASK_PRIO		6
#define	LEDDIS_TASK_PRIO		7
#define	ADC1_TASK_PRIO			8
#define	EXTI_TASK_PRIO			3
#define	CALCULATE_TASK_PRIO		9

/*******	设置栈大小（单位：OS_STK）	*******/
#define STARTUP_TASK_STK_SIZE	80
#define LED_TASK_STK_SIZE		80
#define USART1_TASK_STK_SIZE	80
#define LEDDIS_TASK_STK_SIZE	80
#define ADC1_TASK_STK_SIZE		80
#define EXTI_TASK_STK_SIZE		80
#define CALCULATE_TASK_STK_SIZE	80

#endif // __APP_CFG_H__
