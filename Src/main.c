/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Metehan
 * @brief          : Main program body
 ******************************************************************************
**/

#include "stm32f407xx.h"


static void GPIO_ButtonInterruptConfig();
static void GPIO_LedConfig();
void EXTI0_IRQHandler();
void SPI_config();

void EXTI0_IRQHandler(){

	if(EXTI->PR & 0x1){

		EXTI->PR |= (0x1U <<0U);


	}


}

int main(void)
{
	GPIO_LedConfig();
	GPIO_ButtonInterruptConfig();




	for(;;);

}

static void GPIO_LedConfig(){

	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

		RCC_GPIOD_CLK_ENABLE(); // Clock is Active


		GPIO_InitStruct.pinNumber = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
		GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
		GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
		GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;

		GPIO_Init(GPIOD, &GPIO_InitStruct);

		memset(&GPIO_InitStruct,0, sizeof(GPIO_InitStruct));

		GPIO_InitStruct.pinNumber = GPIO_PIN_0;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.PuPd = GPIO_PUPD_PULLDOWN;

		GPIO_Init(GPIOA, &GPIO_InitStruct);
}



static void GPIO_ButtonInterruptConfig(){

		RCC_GPIOA_CLK_ENABLE(); // Clock is Active
		RCC_SYSCFG_CLK_ENABLE();

		EXTI_InitTypeDef_t EXTI_InitStruct= {0};

		EXTI_LineConfig(EXTI_PortSource_GPIOA, EXTI_LineSource_0);

		EXTI_InitStruct.EXTI_LineCmd = ENABLE;
		EXTI_InitStruct.EXTI_LineNumber = EXTI_LineSource_0;
		EXTI_InitStruct.EXTI_Mode = EXTI_MODE_Interrupt;
		EXTI_InitStruct.TriggerSelection =EXTI_RTSR;

		EXTI_Init(&EXTI_InitStruct);

		NVIC_EnableInterrupt(EXTI0_IRQNumber);

	}


void SPI_config(){

		RCC_SPI1_CLK_ENABLE();

		SPI_HandleTypeDef_t SPI_Handle = { 0 };

		SPI_Handle.Instance = SPI1;

		SPI_Handle.Init.BR = SPI_BAUDRATE_DIV8; // 2 MHz
		SPI_Handle.Init.BUS_CONFIG = SPI_FULL_DUPLEX;
		SPI_Handle.Init.CPHA = SPI_CPHA_FIRST;
		SPI_Handle.Init.CPOL = SPI_CPOL_LOW;
		SPI_Handle.Init.DFF = SPI_DFF_8BITS;
		SPI_Handle.Init.LSB_First = SPI_FRAMEFORMAT_MSB;
		SPI_Handle.Init.MSTR = SPI_MSTR_MASTER;
		SPI_Handle.Init.SSM = SPI_SSM_ENABLE;

		SPI_Init(&SPI_Handle);


}

