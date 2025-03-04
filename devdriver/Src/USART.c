/*
 * USART.c
 *
 *  Created on: Mar 1, 2025
 *      Author: Metehan
 */

#include "USART.h"

void USART_Init(USART_Handle_Typedef *USART_Handle){

	uint32_t tempReg = 0;




/*
*
**********************************************  Control Register 1 Configuration *****************************************
*
*/

	tempReg = USART_Handle->Instance->USART_CR1;

	tempReg |= (USART_Handle->Init.OverSampling)|(USART_Handle->Advance_Init.USART_EN)|(USART_Handle->Init.Wordlength)|\
			(USART_Handle->Advance_Init.WAKE)|(USART_Handle->Init.Parity)|(USART_Handle->Init.Mode)|\
			(USART_Handle->Advance_Init.RWU)|(USART_Handle->Advance_Init.SENDBRK);

	USART_Handle->Instance->USART_CR1 = tempReg;




/*
*
*********************************************  Control Register 2 Configuration ******************************************
*
*/

	tempReg = USART_Handle->Instance->USART_CR2;
	tempReg &= ~(0x3 << USART_CR2_STOP);

	tempReg |= (USART_Handle->Advance_Init.LIN_MODE)|(USART_Handle->Init.StopBits)|(USART_Handle->Advance_Init.CLK_EN)|\
			(USART_Handle->Advance_Init.CPOL)|(USART_Handle->Advance_Init.CPHA)|(USART_Handle->Advance_Init.LBCL);

	USART_Handle->Instance->USART_CR2 = tempReg;




/*
*
**********************************************  Control Register 3 Configuration *****************************************
*
*/

	tempReg = USART_Handle->Instance->USART_CR3;

	tempReg |= (USART_Handle->Advance_Init.ONEBIT)|(USART_Handle->Init.HwFlowCtl)|(USART_Handle->Advance_Init.DMA)|\
			(USART_Handle->Advance_Init.SC_MOD)|(USART_Handle->Advance_Init.HDSEL)|(USART_Handle->Advance_Init.IRDA_MODE);

	USART_Handle->Instance->USART_CR3 = tempReg;



}

