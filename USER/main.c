#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "los_base.h"
#include "los_task.h"
#include "los_inspect_entry.h"
//#include <rtthread.h>
//ALIENTEK ̽����STM32F407������ ʵ��1
//�����ʵ�� -�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

int main(void)
{ 
	UINT32 uwRet = LOS_OK;
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
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
*******************����ע�͵��Ĵ�����ͨ�� λ�� ����ʵ��IO�ڿ���**************************************
	
int main(void)
{ 
 
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
  while(1)
	{
     LED0=0;			  //LED0��
	   LED1=1;				//LED1��
		 delay_ms(500);
		 LED0=1;				//LED0��
		 LED1=0;				//LED1��
		 delay_ms(500);
	 }
}
**************************************************************************************************
 **/	
	
/**
*******************����ע�͵��Ĵ�����ͨ�� ֱ�Ӳ����Ĵ��� ��ʽʵ��IO�ڿ���**************************************
int main(void)
{ 
 
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
	while(1)
	{
     GPIOF->BSRRH=GPIO_Pin_9;//LED0��
	   GPIOF->BSRRL=GPIO_Pin_10;//LED1��
		 delay_ms(500);
     GPIOF->BSRRL=GPIO_Pin_9;//LED0��
	   GPIOF->BSRRH=GPIO_Pin_10;//LED1��
		 delay_ms(500);

	 }
 }	 
**************************************************************************************************
**/	
 



