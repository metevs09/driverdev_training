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

	// Code Testing block for RCC_GPIO Enable and DISABLE macros
	RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOA_CLK_DISABLE();

	RCC_GPIOB_CLK_ENABLE();
	RCC_GPIOB_CLK_DISABLE();

	RCC_GPIOC_CLK_ENABLE();
	RCC_GPIOC_CLK_DISABLE();

	RCC_GPIOD_CLK_ENABLE();
	RCC_GPIOD_CLK_DISABLE();

	RCC_GPIOE_CLK_ENABLE();
	RCC_GPIOE_CLK_DISABLE();

	RCC_GPIOF_CLK_ENABLE();
	RCC_GPIOF_CLK_DISABLE();

	RCC_GPIOG_CLK_ENABLE();
	RCC_GPIOG_CLK_DISABLE();

	RCC_GPIOH_CLK_ENABLE();
	RCC_GPIOH_CLK_DISABLE();

	RCC_GPIOI_CLK_ENABLE();
	RCC_GPIOI_CLK_DISABLE();

	for(;;);


}
