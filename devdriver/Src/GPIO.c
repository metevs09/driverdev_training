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
