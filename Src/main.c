/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Metehan
 * @brief          : Main program body
 ******************************************************************************
**/

#include "stm32f407xx.h"




int main(void)
{
	RCC_GPIOC_CLK_ENABLE();
	RCC_SYSCFG_CLK_ENABLE();


	EXTI_LineConfig(EXTI_PortSource_GPIOC,EXTI_LineSource_7);

	for(;;);

}


