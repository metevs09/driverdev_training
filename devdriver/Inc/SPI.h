/*
 * SPI.h
 *
 *  Created on: Oct 5, 2024
 *      Author: Metehan
 */

#ifndef SPI_H_
#define SPI_H_

#include"stm32f407xx.h"

typedef struct {

	uint32_t CPHA;
	uint32_t CPOL;
	uint32_t MSTR;
	uint32_t BR;
	uint32_t SPE;
	uint32_t LSB_First;
	uint32_t SSI;
	uint32_t SSM;
	uint32_t RX_Only;
	uint32_t DFF;
	uint32_t CRCNEXT;
	uint32_t CRCEN;
	uint32_t BIDIOE;
	uint32_t BIDIMODE;


}SPI_InitTypeDef_t;

typedef struct {

	SPI_TypeDef_t* Instance;
	SPI_InitTypeDef_t Init;

}SPI_HandleTypeDef_t;

#endif /* SPI_H_ */
