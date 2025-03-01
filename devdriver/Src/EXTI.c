/*
 * EXTI.c
 *
 *  Created on: Jul 19, 2024
 *      Author: Metehan
 */

#include "EXTI.h"





/*
 *
 * @brief EXTI_Init for valid GPIO port and Line number
 *
 * @param EXTI_InitStruct = User Config Structure
 *
 * @retval Void
 *
 */


void EXTI_Init(EXTI_InitTypeDef_t*EXTI_InitStruct){

	uint32_t tempValue = 0;

	tempValue = (uint32_t)EXTI_BASE_ADDR;

	EXTI->IMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->EMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	if(EXTI_InitStruct->EXTI_LineCmd !=	DISABLE){

		tempValue += EXTI_InitStruct->EXTI_Mode;

		*((__IO uint32_t*)tempValue) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		tempValue = (uint32_t)EXTI_BASE_ADDR;

		EXTI->RTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->FTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

		if((EXTI_InitStruct->TriggerSelection = EXTI_RFTSR)){

			EXTI->RTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		}

		else{
			tempValue += EXTI_InitStruct->TriggerSelection;
			*((__IO uint32_t*)tempValue) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
		}


	}

	else{

		tempValue = (uint32_t)EXTI_BASE_ADDR;
		tempValue += EXTI_InitStruct->EXTI_Mode;
		*((__IO uint32_t*)tempValue) &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	}

}





/*
 *
 * @brief GPIO_LineConfig, Configures the Port and pin for SYSCFG
 * @param PortSource = Port Value (A:I) @def_group PORT_Values
 *
 *
 * @param EXTI_LineSource = Pin numbers & Line numbers(0:15) @def_group LINE_Values
 *
 * @retval Void
 *
 */

void EXTI_LineConfig(uint8_t PortSource, uint8_t EXTI_LineSource){

	uint32_t tempValue = 0;

	tempValue = SYSCFG->EXTI_CR[EXTI_LineSource >> 2U];
	tempValue &= ~(0xFU << (EXTI_LineSource & 0x3U) * 4);
	tempValue = (PortSource << (EXTI_LineSource & 0x3U) * 4);
	SYSCFG->EXTI_CR[EXTI_LineSource >> 2U] = tempValue;
}





/*
 *
 * @brief NVIC_EnableInterrupt
 * @param IRQnumber = IRQnumber of Line
 *
 *
 * @retval Void
 *
 */



void NVIC_EnableInterrupt(IRQNumber_TypeDef_t IRQnumber){

	uint32_t tempValue = 0;

	tempValue = *((IRQnumber >> 5U) + NVIC_ISER0);
	tempValue &= ~(0x1U << (IRQnumber & 0x1FU));
	tempValue |= (0x1U << (IRQnumber & 0x1FU));
	*((IRQnumber >> 5U) + NVIC_ISER0) = tempValue;

}

