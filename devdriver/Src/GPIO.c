/*
 * GPIO.c
 *
 *  Created on: May 14, 2024
 *      Author: Metehan
 */

#include "GPIO.h"


/*
 *
 * @brief GPIO_Write_Pin, makes pin High or Low
 * @param GPIOx = GPIO Port Base Address
 *
 * @param pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @param pinState = GPIO_Pin_Set OR GPIO_Pin_Reset
 *
 * @retval Void
 *
 */

void GPIO_WritePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState ){

	if( pinState == GPIO_Pin_Set){

		GPIOx->BSRR = pinNumber;

	}
	else{

		GPIOx->BSRR = (pinNumber << 16U);

	}

}

/*
 *
 * @brief GPIO_Read_Pin, read pin value
 * @param GPIOx = GPIO Port Base Address
 *
 * @param pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @retval GPIO_PinState_t
 *
 */

GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){

	GPIO_PinState_t bitStatus = GPIO_Pin_Reset;

	if((GPIOx->IDR & pinNumber) != GPIO_Pin_Reset){

		bitStatus = GPIO_Pin_Set;
	}

	return bitStatus;

}
