/*
 * GPIO.c
 *
 *  Created on: May 14, 2024
 *      Author: Metehan
 */

#include "GPIO.h"

/*
 *
 * @brief GPIO_Init,Configures the port and pin
 * @param GPIOx = GPIO Port Base Address
 *
 *
 * @param GPIO_InitTypeDef_t = User Config Structures
 *
 * @retval Void
 *
 */

void GPIO_Init(GPIO_TypeDef_t *GPIOx,GPIO_InitTypeDef_t *GPIO_ConfigStruct){

	uint32_t pos;
	uint32_t fakepos;
	uint32_t lastpos;

	for(pos =0; pos< 16; pos++){

		fakepos = (0x1 << pos);
		lastpos = (GPIO_ConfigStruct->pinNumber)& fakepos;

		if (fakepos == lastpos){

			/* Mode Config  */

			uint32_t tempValue = GPIOx->MODER;

			tempValue &= ~(0x3U <<(pos*2));
			tempValue |= (GPIO_ConfigStruct->Mode <<(pos*2));

			GPIOx->MODER = tempValue;
		}

		if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode == GPIO_MODE_AF){

			/* Output Type Config */
			uint32_t tempValue = GPIOx->OTYPER;
			tempValue &= ~(0x1U <<pos);
			tempValue |= (GPIO_ConfigStruct->Otype << pos);
			GPIOx->OTYPER = tempValue;

			/* Output Speed Config */
			tempValue = GPIOx->OSPEEDR;
			tempValue &= ~(0x3U <<(pos*2));
			tempValue |= (GPIO_ConfigStruct->Speed << (pos*2));
			GPIOx->OSPEEDR = tempValue;
		}

		/* Output Push-Pull Config */
		uint32_t tempValue = GPIOx->PUPDR;
		tempValue &= ~(0x3U << (pos*2));
		tempValue |= (GPIO_ConfigStruct->PuPd <<(pos*2));
		GPIOx->PUPDR = tempValue;

		if(GPIO_ConfigStruct->Mode == GPIO_MODE_AF){

			tempValue = GPIOx->AFR[pos >> 3U];
			tempValue &= ~(0xFU << ((pos & 0x7U)*4));
			tempValue |= (GPIO_ConfigStruct->AF <<((pos & 0x7U)*4));
			GPIOx->AFR[pos >> 3U] = tempValue;
		}

	}

}


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


/*
 *
 * @brief GPIO_Lock_Pin, lock the  pin of GPIOx Port
 * @param GPIOx = GPIO Port Base Address
 *
 * @param pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @retval Void
 *
 */

void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){

	uint32_t tempValue = (0x1U << 16U) | pinNumber;

	GPIOx->LCKR = tempValue;
	GPIOx->LCKR = pinNumber;
	GPIOx->LCKR = tempValue;
	tempValue = GPIOx->LCKR;

}


/*
 *
 * @brief GPIO_TogglePin, toggles the  pin of GPIOx Port
 * @param GPIOx = GPIO Port Base Address
 *
 * @param pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @retval Void
 *
 */

void GPIO_TogglePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){

	uint32_t tempODRRegister = GPIOx->ODR;

	GPIOx->BSRR = ((tempODRRegister & pinNumber) <<16)| (~tempODRRegister & pinNumber);

}
