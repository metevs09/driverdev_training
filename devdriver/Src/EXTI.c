/*
 * EXTI.c
 *
 *  Created on: Jul 19, 2024
 *      Author: Metehan
 */

#include "EXTI.h"

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

	uint32_t tempValue;

	tempValue = SYSCFG->EXTI_CR[EXTI_LineSource >> 2U];
	tempValue &= ~(0xFU << (EXTI_LineSource & 0x3U) * 4);
	tempValue = (PortSource << (EXTI_LineSource & 0x3U) * 4);
	SYSCFG->EXTI_CR[EXTI_LineSource >> 2U] = tempValue;
}

