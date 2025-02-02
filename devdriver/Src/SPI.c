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

	SPI_Handle->Instance->CR1 = tempValue;
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


/*
 *
 * @brief SPI_ReceiveData, Receive Data on the SPI
 * @param SPI_Handle = User configuration structure
 *
 * @param pBuffer = Buffer address of data to receive
 *
 * @param sizeOfData = Length of your data in bytes
 *
 * @retval Void
 *
 */

void SPI_ReceiveData(SPI_HandleTypeDef_t *SPI_Handle,uint8_t *pBuffer, uint16_t sizeOfData){

	if(SPI_Handle->Init.DFF == SPI_DFF_16BITS){

		while(sizeOfData > 0){

			if(SPI_GetFlagStatus(SPI_Handle, SPI_RxNE_Flag)){

				*( (uint16_t*)pBuffer ) = (uint16_t)SPI_Handle->Instance->DR;
				pBuffer += sizeof(uint16_t);
				sizeOfData -= 2;
			}

		}


	}
	else{

		while(sizeOfData > 0){

			if(SPI_GetFlagStatus(SPI_Handle, SPI_RxNE_Flag)){

				*(pBuffer) = *((__IO uint8_t*)&SPI_Handle->Instance->DR);
					pBuffer += sizeof(uint8_t);
					sizeOfData --;

			}

		}

	}
}


/*
 *
 * @brief SPI_TransmitData, Transmit Data on the SPI
 * @param SPI_Handle = User configuration structure
 *
 * @param pData = Address of data to sent
 *
 * @param sizeOfData = Length of your data in bytes
 *
 * @retval Void
 *
 */


void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle,uint8_t *pData, uint16_t sizeOfData ){

	if(SPI_Handle->Init.DFF == SPI_DFF_16BITS){

		while(sizeOfData >0){

			if(SPI_GetFlagStatus(SPI_Handle,SPI_TxE_FLAG )){

				SPI_Handle->Instance->DR = *((uint16_t*)pData);
				pData += sizeof(uint16_t);
				sizeOfData -= 2;

			}
		}

	}
	else{

		while(sizeOfData >0){

			if((SPI_Handle->Instance->SR >> 1U) & 0x1U){

				SPI_Handle->Instance->DR = *pData;
				pData +=sizeof(uint8_t);
				sizeOfData--;

			}

		 }

	}

	while(SPI_GetFlagStatus(SPI_Handle,SPI_TxE_FLAG )); // Wait for Busy Flag

}

/*
 *
 * @brief SPI_GetFlagStatus, Return the flag of SR register
 * @param SPI_Handle = User configuration structure
 *
 * @param SPI_Flag = Flag name of SR register
 *
 * @retval SPI_FlagStatus_t
 *
 */


SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypeDef_t *SPI_Handle,uint16_t SPI_Flag){

	return(SPI_Handle->Instance->SR & SPI_Flag) ? SPI_FLAG_SET : SPI_FLAG_RESET ;

}
