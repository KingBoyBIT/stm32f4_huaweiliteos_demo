#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "los_base.h"
#include "los_task.h"
#include "los_inspect_entry.h"
//#include <rtthread.h>
//ALIENTEK 探索者STM32F407开发板 实验1
//跑马灯实验 -库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

int main(void)
{ 
	UINT32 uwRet = LOS_OK;
	delay_init(168);		  //初始化延时函数
	LED_Init();		        //初始化LED端口
	uart_init(115200);
	printf("uart inited!\r\n");
	if (LOS_OK != LOS_KernelInit())
    {
		printf("los error!\r\n");
        return LOS_NOK;
    }
	printf("LOS_KernelInit!\r\n");
    uwRet = LOS_Inspect_Entry();
	if (LOS_OK != uwRet)
    {
		printf("LOS_Inspect_Entry error!\r\n");
        return LOS_NOK;
    }
	printf("LOS_Inspect_Entry!\r\n");
    uwRet = LOS_Start();
	if (LOS_OK != uwRet)
    {
		printf("LOS_Start error!\r\n");
        return LOS_NOK;
    }
	printf("LOS_Start!\r\n");
	while(1)
	{
		LED0 = 0;
		printf("led 0!\r\n");
		(VOID)LOS_TaskDelay(100);
		LED0 = 1;
		printf("led 1!\r\n");
		(VOID)LOS_TaskDelay(100);
	}
}


/**
*******************下面注释掉的代码是通过 位带 操作实现IO口控制**************************************
	
int main(void)
{ 
 
	delay_init(168);		  //初始化延时函数
	LED_Init();		        //初始化LED端口
  while(1)
	{
     LED0=0;			  //LED0亮
	   LED1=1;				//LED1灭
		 delay_ms(500);
		 LED0=1;				//LED0灭
		 LED1=0;				//LED1亮
		 delay_ms(500);
	 }
}
**************************************************************************************************
 **/	
	
/**
*******************下面注释掉的代码是通过 直接操作寄存器 方式实现IO口控制**************************************
int main(void)
{ 
 
	delay_init(168);		  //初始化延时函数
	LED_Init();		        //初始化LED端口
	while(1)
	{
     GPIOF->BSRRH=GPIO_Pin_9;//LED0亮
	   GPIOF->BSRRL=GPIO_Pin_10;//LED1灭
		 delay_ms(500);
     GPIOF->BSRRL=GPIO_Pin_9;//LED0灭
	   GPIOF->BSRRH=GPIO_Pin_10;//LED1亮
		 delay_ms(500);

	 }
 }	 
**************************************************************************************************
**/	
 



