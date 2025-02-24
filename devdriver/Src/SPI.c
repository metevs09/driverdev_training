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

static void SPI_Close_ISR_TX(SPI_HandleTypeDef_t *SPI_Handle){

	SPI_Handle->Instance->CR2 &= ~~(0x1U << SPI_CR2_TXEIE);
	SPI_Handle->TxDataSize = 0;
	SPI_Handle->pTxBufferAddr = NULL;
	SPI_Handle->Bus_StateTX = SPI_BUS_FREE;
}

static void SPI_Transmit_16Bits(SPI_HandleTypeDef_t *SPI_Handle){

	SPI_Handle->Instance->DR = *((uint16_t*)(SPI_Handle->pTxBufferAddr));
	SPI_Handle->pTxBufferAddr += sizeof(uint16_t);
	SPI_Handle->TxDataSize -= 2;

}

static void SPI_Transmit_8Bits(SPI_HandleTypeDef_t *SPI_Handle){

	SPI_Handle->Instance->DR = *((uint8_t*)(SPI_Handle->pTxBufferAddr));
		SPI_Handle->pTxBufferAddr += sizeof(uint8_t);
		SPI_Handle->TxDataSize --;

		if(SPI_Handle->TxDataSize ==0){

			SPI_Close_ISR_TX(SPI_Handle);
		}
}

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
 * @brief SPI_ReceiveData, Receive Data from the Slave
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

void SPI_TransmitData_Interrupt(SPI_HandleTypeDef_t *SPI_Handle,uint8_t *pData, uint16_t sizeOfData){

	SPI_BusStatus_t busState = SPI_Handle->Bus_StateTX;

	if(busState != SPI_BUS_BUSY_TX){

	SPI_Handle->pTxBufferAddr = (uint8_t*)pData;
	SPI_Handle->TxDataSize = (uint16_t)sizeOfData;
	SPI_Handle->Bus_StateTX = SPI_BUS_BUSY_TX;

	if(SPI_Handle->Instance->CR1 & (0x1U << SPI_CR1_DFF)){

		SPI_Handle->TxISRFunction = SPI_Transmit_16Bits;

	}
	else {

		SPI_Handle->TxISRFunction = SPI_Transmit_8Bits;

	}

	SPI_Handle->Instance->CR2 |= (0x1 << SPI_CR2_TXEIE);
	}


}

void SPI_Interrupt_Handler(SPI_HandleTypeDef_t *SPI_Handle){

	uint8_t interruptSource = 0;
	uint8_t interruptFlag = 0;

	interruptSource = SPI_Handle->Instance->CR2 & (0x1U << SPI_CR2_TXEIE);
	interruptFlag   = SPI_Handle->Instance->SR  & (0x1U << SPI_TxE);

	if((interruptSource != 0)&&(interruptFlag != 0)){

		SPI_Handle->TxISRFunction(SPI_Handle);
	}

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
