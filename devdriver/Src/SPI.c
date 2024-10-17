/*
 * SPI.c
 *
 *  Created on: Oct 5, 2024
 *      Author: Metehan
 */


/*
 *
 * @brief SPI_Init,Configures the SPI peripheral
 * @param SPI_Handle = User configuration structure
 *
 *
 * @retval Void
 *
 */

#include "SPI.h"

void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle){

	/*	SPI control register 1 (SPI_CR1)	*/

	uint32_t tempValue = 0;

	tempValue = SPI_Handle->Instance->CR1;

	tempValue |= (SPI_Handle->Init.CPHA)|(SPI_Handle->Init.CPOL)|(SPI_Handle->Init.MSTR)|(SPI_Handle->Init.BR)|\
				 (SPI_Handle->Init.LSB_First)|(SPI_Handle->Init.SSM)|(SPI_Handle->Init.DFF)|\
				 (SPI_Handle->Init.CRCNEXT)|(SPI_Handle->Init.CRCEN)|(SPI_Handle->Init.BUS_CONFIG);

}

/*
 *
 * @brief SPI_Perip_Cmd, Configures the SPI enable or disable
 * @param SPI_Handle = User configuration structure
 *
   @param stateOfSPI = Functional State (ENABLE or DISABLE)values
 *
 *
 * @retval Void
 *
 */


void SPI_Perip_Cmd (SPI_HandleTypeDef_t *SPI_Handle, Functional_State_t stateOfSPI){

	if (stateOfSPI == ENABLE){

		SPI_Handle->Instance->CR1 |= (0x1 << SPI_CR1_SPE);

	}
	else{

		SPI_Handle->Instance->CR1 &= ~(0x1 << SPI_CR1_SPE);

	}

}
