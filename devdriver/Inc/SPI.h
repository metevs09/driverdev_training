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


/*
 *
 * @def_group SPI_CPHA
 *
 */

#define SPI_CPHA_FIRST		((uint32_t)(0x00000000))
#define SPI_CPHA_SECOND		((uint32_t)(0x00000001))


/*
 *
 * @def_group SPI_CPOL
 *
 */

#define SPI_CPOL_LOW		((uint32_t)(0x00000000))
#define SPI_CPOL_HIGH		((uint32_t)(0x00000002))


/*
 *
 * @def_group SPI_DFF
 *
 */

#define SPI_DFF_8BITS		((uint32_t)(0x00000000))
#define SPI_DFF_16BITS		((uint32_t)(0x00000800))


/*
 *
 * @def_group SPI_MSTR
 *
 */

#define SPI_MSTR_MASTER		((uint32_t)(0x00000004))
#define SPI_MSTR_SLAVE		((uint32_t)(0x00000000))


/*
 *
 * @def_group SPI_LSB_First
 *
 */

#define SPI_FRAMEFORMAT_MSB		((uint32_t)(0x00000000))
#define SPI_FRAMEFORMAT_LSB		((uint32_t)(0x00000080))


/*
 *
 * @def_group SPI_BUS_CONFIG
 *
 */

#define SPI_FULL_DUPLEX		((uint32_t)(0x00000000))
#define SPI_RECEIVE_ONLY	((uint32_t)(0x00000400))

#define SPI_HALF_DUPLEX_T	((uint32_t)(0x0000C000))
#define SPI_HALF_DUPLEX_R	((uint32_t)(0x00008000))



typedef struct {

	uint32_t CPHA;		// *!> Clock Phase value for SPI @def_group SPI_CPHA
	uint32_t CPOL;		// *!> Clock Polarity value for SPI @def_group SPI_CPOL
	uint32_t MSTR;		// *!> Master Mode value for SPI @def_group SPI_MSTR
	uint32_t BR;		// *!> BaudRate value for SPI @def_group SPI_BaudRates
	uint32_t SPE;
	uint32_t LSB_First;	// *!>  Frame format value for SPI @def_group SPI_LSB_First
	uint32_t SSI;
	uint32_t SSM;
	uint32_t BUS_CONFIG;// *!> RX_Only value for SPI @def_group SPI_BUS_CONFIG
	uint32_t DFF;		// *!> Data Frame Format value for SPI @def_group SPI_DFF
	uint32_t CRCNEXT;
	uint32_t CRCEN;



}SPI_InitTypeDef_t;

typedef struct {

	SPI_TypeDef_t* Instance;
	SPI_InitTypeDef_t Init;

}SPI_HandleTypeDef_t;

void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle);


#endif /* SPI_H_ */
