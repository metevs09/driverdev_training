/*
 * SPI.c
 *
 *  Created on: Oct 5, 2024
 *      Author: Metehan
 */

#include "SPI.h"

void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle){


	uint32_t tempValue = 0;

	tempValue = SPI_Handle->Instance->CR1;

	tempValue |= (SPI_Handle->Init.CPHA)|(SPI_Handle->Init.CPOL)|(SPI_Handle->Init.MSTR)|(SPI_Handle->Init.BR)|(SPI_Handle->Init.SPE)|(SPI_Handle->Init.LSB_First)|(SPI_Handle->Init.SSI)|(SPI_Handle->Init.SSM)|(SPI_Handle->Init.RX_Only)|(SPI_Handle->Init.DFF)|(SPI_Handle->Init.CRCNEXT)|(SPI_Handle->Init.CRCEN)|(SPI_Handle->Init.BIDIOE)|(SPI_Handle->Init.BIDIMODE);


}
