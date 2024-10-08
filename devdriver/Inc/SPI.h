/*
 * SPI.h
 *
 *  Created on: Oct 5, 2024
 *      Author: Metehan
 */

#ifndef SPI_H_
#define SPI_H_

#include"stm32f407xx.h"

/*
 *
 * @def_group SPI_BaudRates
 *
 *
 */


#define SPI_BAUDRATE_DIV2	((uint32_t)(0x00000000))
#define SPI_BAUDRATE_DIV4	((uint32_t)(0x00000008))
#define SPI_BAUDRATE_DIV8	((uint32_t)(0x00000010))
#define SPI_BAUDRATE_DIV16	((uint32_t)(0x00000018))
#define SPI_BAUDRATE_DIV32	((uint32_t)(0x00000020))
#define SPI_BAUDRATE_DIV64	((uint32_t)(0x00000028))
#define SPI_BAUDRATE_DIV128	((uint32_t)(0x00000030))
#define SPI_BAUDRATE_DIV256	((uint32_t)(0x00000038))




typedef struct {

	uint32_t CPHA;
	uint32_t CPOL;
	uint32_t MSTR;
	uint32_t BR;		// *!> BaudRate value for SPI @def_group SPI_BaudRates
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

void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle);


#endif /* SPI_H_ */
