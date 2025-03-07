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

	tempReg = USART_Handle->Instance->CR1;

	tempReg |= (USART_Handle->Init.OverSampling)|(USART_Handle->Advance_Init.USART_EN)|(USART_Handle->Init.Wordlength)|\
			(USART_Handle->Advance_Init.WAKE)|(USART_Handle->Init.Parity)|(USART_Handle->Init.Mode)|\
			(USART_Handle->Advance_Init.RWU)|(USART_Handle->Advance_Init.SENDBRK);

	USART_Handle->Instance->CR1 = tempReg;




/*
*
*********************************************  Control Register 2 Configuration ******************************************
*
*/

	tempReg = USART_Handle->Instance->CR2;
	tempReg &= ~(0x3 << USART_CR2_STOP);

	tempReg |= (USART_Handle->Advance_Init.LIN_MODE)|(USART_Handle->Init.StopBits)|(USART_Handle->Advance_Init.CLK_EN)|\
			(USART_Handle->Advance_Init.CPOL)|(USART_Handle->Advance_Init.CPHA)|(USART_Handle->Advance_Init.LBCL);

	USART_Handle->Instance->CR2 = tempReg;




/*
*
**********************************************  Control Register 3 Configuration *****************************************
*
*/

	tempReg = USART_Handle->Instance->CR3;

	tempReg |= (USART_Handle->Advance_Init.ONEBIT)|(USART_Handle->Init.HwFlowCtl)|(USART_Handle->Advance_Init.DMA)|\
			(USART_Handle->Advance_Init.SC_MOD)|(USART_Handle->Advance_Init.HDSEL)|(USART_Handle->Advance_Init.IRDA_MODE);

	USART_Handle->Instance->CR3 = tempReg;



}





void USART_TransmitData(USART_Handle_Typedef *USART_Handle, uint8_t *pData,uint16_t dataSize){

	uint16_t *data16Bits;

	if((USART_Handle->Init.Wordlength == USART_WORDLENGTH_9Bits) && (USART_Handle->Init.Parity == USART_PARITY_NONE)){

		data16Bits = (uint16_t*)pData;

	}

	else{

		data16Bits = NULL;

	}


	while(dataSize > 0){

		while(!(USART_GetFlagStatus(USART_Handle,USART_SR_TxE)));

		if(data16Bits == NULL ){

			USART_Handle->Instance->DR = (uint8_t)(*pData & 0xFFU);
			pData++;
			dataSize--;
		}

		else{

			USART_Handle->Instance->DR = (uint16_t)(*data16Bits & (0x01FFU));
			data16Bits++;
			dataSize -= 2;
		}

	}

	while(! (USART_GetFlagStatus(USART_Handle,USART_TC_FLAG)));
}





USART_FlagStatus_t USART_GetFlagStatus(USART_Handle_Typedef *USART_Handle, uint16_t flagName){


	return((USART_Handle->Instance->SR & flagName)? USART_FLAG_SET : USART_FLAG_SET);
}
