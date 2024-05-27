/*
 * GPIO.c
 *
 *  Created on: May 14, 2024
 *      Author: Metehan
 */

#include "GPIO.h"


void GPIO_WritePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState ){

	if( pinState == GPIO_Pin_Set){

		GPIOx->BSRR = pinNumber;

	}
	else{

		GPIOx->BSRR = (pinNumber << 16U);

	}

}
