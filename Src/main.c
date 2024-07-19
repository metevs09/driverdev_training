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



	for(;;){


		if(GPIO_ReadPin(GPIOA, GPIO_PIN_0)== GPIO_Pin_Set){

			GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_Pin_Set);
		}
		else{

			GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_Pin_Reset);

		}

	}

}

static void GPIO_LedConfig(){

	RCC_GPIOD_CLK_ENABLE(); // Clock is activetad
	RCC_GPIOA_CLK_ENABLE(); // Clock is activetad

	GPIO_InitTypeDef_t GPIO_LedStruct = {0};
	GPIO_LedStruct.pinNumber = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	GPIO_LedStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_LedStruct.Speed = GPIO_SPEED_LOW;
	GPIO_LedStruct.Otype = GPIO_OTYPE_PP;
	GPIO_LedStruct.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOD,&GPIO_LedStruct); // Configuration

	memset(&GPIO_LedStruct,0,sizeof(GPIO_LedStruct));


	GPIO_LedStruct.pinNumber = GPIO_PIN_0;
	GPIO_LedStruct.Mode = GPIO_MODE_INPUT;
	GPIO_LedStruct.PuPd = GPIO_PUPD_PULLDOWN;

	GPIO_Init(GPIOA, &GPIO_LedStruct );
}
