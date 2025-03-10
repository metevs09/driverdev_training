/*
 * USART.c
 *
 *  Created on: Mar 1, 2025
 *      Author: Metehan
 */

#include "USART.h"





/*
 *
 * @brief USART_Init, Configures the SPI peripheral
 * @param USART_Handle = User configuration structure
 *
 *
 * @retval Void
 *
 */

void USART_Init(USART_Handle_Typedef *USART_Handle){

	uint32_t tempReg = 0;

	CLEAR_BIT(USART_Handle->Instance->SR,USART_TC_FLAG);


/*
*
********************************************** Baud rate register Configuration ******************************************
*
*/
	uint32_t periphClock;
	uint32_t MantissaPart = 0;
	uint32_t fractionPart = 0;
	uint32_t USART_BRR = 0;
	double USART_DIV_Value = 0;

	if(USART_Handle->Instance == USART1 || USART_Handle->Instance == USART6 ){

		periphClock =  RCC_GetAPB2Clock();
	}

	else{

		periphClock =  RCC_GetAPB1Clock();
	}

	if(USART_Handle->Init.OverSampling == USART_OVERSAMPL_16 ){

		USART_Handle->Instance->BRR &= ~(0xFFFFU);

		USART_DIV_Value = __USART_DIV_VALUE_16(periphClock, USART_Handle->Init.BaudRate);
		MantissaPart = (uint32_t)(USART_DIV_Value);
		fractionPart = ((uint32_t)round((USART_DIV_Value - MantissaPart) * (16U))& 0x0FU);

	}

	else{

		USART_Handle->Instance->BRR &= ~(0xFFFFU);

		USART_DIV_Value = __USART_DIV_VALUE_8(periphClock, USART_Handle->Init.BaudRate);
		MantissaPart = (uint32_t)(USART_DIV_Value);
		fractionPart = ((uint32_t)round((USART_DIV_Value - MantissaPart) * (8U))& 0x07U);

	}

	USART_BRR |= (MantissaPart << 4U);
	USART_BRR |= (fractionPart << 0U);

	USART_Handle->Instance->BRR = USART_BRR;
/*
*
**********************************************  Control Register 1 Configuration *****************************************
*
*/

	tempReg = USART_Handle->Instance->CR1;

	tempReg |= (USART_Handle->Init.OverSampling)|(USART_Handle->Init.Wordlength)|\
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




/*
 *
 * @brief USART_TransmitData, Transmit data function on the SPI
 * @param USART_Handle = User configuration structure
 * @param pData =  Pointer to USART Tx transfer buffer
 * @param dataSize = Length of your data in bytes
 *
 * @retval Void
 *
 */

void USART_TransmitData(USART_Handle_Typedef *USART_Handle, uint8_t *pData,uint16_t dataSize){

	uint16_t *data16Bits;

	if((USART_Handle->Init.Wordlength == USART_WORDLENGTH_9Bits) && (USART_Handle->Init.Parity == USART_PARITY_NONE)){

		data16Bits = (uint16_t*)pData;

	}

	else{

		data16Bits = NULL;

	}


	while(dataSize > 0){

		while(!(USART_GetFlagStatus(USART_Handle,USART_TxE_FLAG)));

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

	while(!(USART_GetFlagStatus(USART_Handle,USART_TC_FLAG)));
}




/*
 *
 * @brief USART_PeripCmd, Configures the USART enable or disable
 * @param SPI_Handle = User configuration structure
 *
   @param stateOfUSART = Functional State (ENABLE or DISABLE)values
 *
 *
 * @retval Void
 *
 */

void USART_PeripCmd(USART_Handle_Typedef *USART_Handle,Functional_State_t stateOfUSART){

	if (stateOfUSART == ENABLE){

		USART_Handle->Instance->CR1 |= (0x1 << USART_CR1_UE);

		}
		else{

			USART_Handle->Instance->CR1 &= ~(0x1 << USART_CR1_UE);

		}
}



/*
 *
 * @brief USART_GetFlagStatus, Flag status about related flag
 * @param USART_Handle = User configuration structure
 * @param flagName = Flag name of SR register
 *
 * @retval USART_FlagStatus_t
 *
 */

USART_FlagStatus_t USART_GetFlagStatus(USART_Handle_Typedef *USART_Handle, uint16_t flagName){


	return(READ_BIT(USART_Handle->Instance->SR, flagName)? USART_FLAG_SET : USART_FLAG_RESET);
}
