/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Metehan
 * @brief          : Main program body
 ******************************************************************************
**/

#include "stm32f407xx.h"


static void GPIO_LedConfig();

int main(void)
{

	GPIO_LedConfig();
	GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_Pin_Set);



	for(;;);

}

static void GPIO_LedConfig(){

	RCC_GPIOD_CLK_ENABLE(); // Clock is activetad

	GPIO_InitTypeDef_t GPIO_LedStruct = {0};
	GPIO_LedStruct.pinNumber = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	GPIO_LedStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_LedStruct.Speed = GPIO_SPEED_LOW;
	GPIO_LedStruct.Otype = GPIO_OTYPE_PP;
	GPIO_LedStruct.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOD,&GPIO_LedStruct); // Configuration

}
