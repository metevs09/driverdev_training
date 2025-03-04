/*
 * USART.c
 *
 *  Created on: Mar 1, 2025
 *      Author: Metehan
 */

#include "USART.h"

void USART_Init(USART_Handle_Typedef *USART_Handle){

	uint32_t tempReg = 0;

	tempReg = USART_Handle->Instance->USART_CR1;

	tempReg |= (USART_Handle->Init.OverSampling)|(USART_Handle->Advance_Init.USART_EN)|(USART_Handle->Init.Wordlength)|\
			(USART_Handle->Advance_Init.WAKE)|(USART_Handle->Init.Parity)|(USART_Handle->Init.Mode)|\
			(USART_Handle->Advance_Init.RWU)|(USART_Handle->Advance_Init.SENDBRK);
}

