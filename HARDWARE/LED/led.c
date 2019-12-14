/**
 * @file led.c
 * @author ZhouShibo (zhoushiboBIT@163.com)
 * @brief 
 * @version 0.0.1.0
 * @date 2019-12-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "led.h"

//初始化PF9和PF10为输出口.并使能这两个口的时钟
//LED IO初始化
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); //使能GPIOF时钟

	//GPIOF9,F10初始化设置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	  //普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	   //上拉
	GPIO_Init(GPIOE, &GPIO_InitStructure);			   //初始化

	GPIO_SetBits(GPIOE, GPIO_Pin_3 | GPIO_Pin_4); //GPIOE3,E4设置高，灯灭

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE); //使能GPIOF时钟

	//GPIOF9,F10初始化设置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	  //普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	   //上拉
	GPIO_Init(GPIOG, &GPIO_InitStructure);			   //初始化

	GPIO_SetBits(GPIOG, GPIO_Pin_9); //GPIOE3,E4设置高，灯灭
}
