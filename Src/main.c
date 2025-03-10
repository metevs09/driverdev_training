/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Metehan
 * @brief          : Main program body
 ******************************************************************************
**/

#include "stm32f407xx.h"

/*

static void GPIO_ButtonInterruptConfig(void);
static void GPIO_LedConfig(void);
void EXTI0_IRQHandler();
void SPI1_IRQHandler();
void SPI_GPIO_Config(void);
void SPI_config(void);

SPI_HandleTypeDef_t SPI_Handle;

void EXTI0_IRQHandler(){

	static char msgToSent[] = "Hesaplamalarima gore cok tatlisin";


	if(EXTI->PR & 0x1){

		EXTI->PR = (0x1U <<0U);

		SPI_TransmitData_Interrupt(&SPI_Handle, (uint8_t*)msgToSent, strlen(msgToSent));

	}


}

void SPI1_IRQHandler(){

	SPI_Interrupt_Handler(&SPI_Handle);

}

*/

static void USART_Config(void);
static void GPIO_config(void);

USART_Handle_Typedef USART_Handle;

int main(void){

    /*

	GPIO_LedConfig();
	GPIO_ButtonInterruptConfig();

	SPI_GPIO_Config();
	SPI_config();

    */

	USART_Config();
	GPIO_config();

	static char msgToSent[] = "Hello";

	USART_TransmitData(&USART_Handle, (uint8_t*)msgToSent, strlen(msgToSent));

	for(;;){}


}

static void USART_Config(void){

	RCC_USART2_CLK_ENABLE();

	USART_Handle.Instance = USART2;
	USART_Handle.Init.BaudRate = 9600;
	USART_Handle.Init.HwFlowCtl = USART_HW_NONE;
	USART_Handle.Init.Mode = USART_MODE_Tx;
	USART_Handle.Init.OverSampling = USART_OVERSAMPL_16;
	USART_Handle.Init.Parity = USART_PARITY_NONE;
	USART_Handle.Init.StopBits = USART_STOPBITS_1;
	USART_Handle.Init.Wordlength = USART_WORDLENGTH_8Bits;

	USART_Init(&USART_Handle);
	USART_PeripCmd(&USART_Handle, ENABLE);

}



static void GPIO_config(void){

	RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	GPIO_InitStruct.pinNumber = GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_AF;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
	GPIO_InitStruct.AF = GPIO_AF7;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/*

static void GPIO_LedConfig(void){

	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

		RCC_GPIOD_CLK_ENABLE(); // Clock is Active
		RCC_GPIOA_CLK_ENABLE(); // Clock is Active



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



static void GPIO_ButtonInterruptConfig(void){

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


void SPI_config(void){

		RCC_SPI1_CLK_ENABLE();

		SPI_Handle.Instance = SPI1;

		SPI_Handle.Init.BR = SPI_BAUDRATE_DIV8; // 4 MHz
		SPI_Handle.Init.BUS_CONFIG = SPI_FULL_DUPLEX;
		SPI_Handle.Init.CPHA = SPI_CPHA_FIRST;
		SPI_Handle.Init.CPOL = SPI_CPOL_LOW;
		SPI_Handle.Init.DFF = SPI_DFF_8BITS;
		SPI_Handle.Init.LSB_First = SPI_FRAMEFORMAT_MSB;
		SPI_Handle.Init.MSTR = SPI_MSTR_MASTER;
		SPI_Handle.Init.SSM = SPI_SSM_ENABLE;

		SPI_Init(&SPI_Handle);

		SPI_Perip_Cmd(&SPI_Handle, ENABLE);

}


void SPI_GPIO_Config(void){

		GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

		GPIO_InitStruct.pinNumber = GPIO_PIN_5 | GPIO_PIN_7 ; // PA5 = SCK, PA7 = MOSI
		GPIO_InitStruct.Mode = GPIO_MODE_AF;
		GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
		GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
		GPIO_InitStruct.AF = GPIO_AF5;

		NVIC_EnableInterrupt(SPI1_IRQNumber);

		GPIO_Init(GPIOA, &GPIO_InitStruct);

}

*/

