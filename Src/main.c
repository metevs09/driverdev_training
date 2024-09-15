/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Metehan
 * @brief          : Main program body
 ******************************************************************************
**/

#include "stm32f407xx.h"


static void GPIO_ButtonInterruptConfig();


void EXTI0_IRQHandler(){

	if(EXTI->PR & 0x1){

		EXTI->PR |= (0x1U <<0U);

		GPIO_WritePin(GPIOD, GPIO_PIN_ALL,GPIO_Pin_Set );

	}


}

int main(void)
{
	RCC_GPIOC_CLK_ENABLE();

	GPIO_ButtonInterruptConfig();


	for(;;);

}



static void GPIO_ButtonInterruptConfig(){

		RCC_SYSCFG_CLK_ENABLE();

		EXTI_InitTypeDef_t EXTI_InitStruct= {0};

		EXTI_LineConfig(EXTI_PortSource_GPIOC, EXTI_LineSource_10);

		EXTI_InitStruct.EXTI_LineCmd = ENABLE;
		EXTI_InitStruct.EXTI_LineNumber = EXTI_LineSource_10;
		EXTI_InitStruct.EXTI_Mode = EXTI_MODE_Interrupt;
		EXTI_InitStruct.TriggerSelection =EXTI_RTSR;

		EXTI_Init(&EXTI_InitStruct);

		NVIC_EnableInterrupt(EXTI0_IRQNumber);

	}

