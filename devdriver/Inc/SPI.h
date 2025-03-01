/*
 * SPI.h
 *
 *  Created on: Oct 5, 2024
 *      Author: Metehan
 */

#ifndef SPI_H_
#define SPI_H_

#include"stm32f407xx.h"

typedef enum{

	SPI_BUS_FREE	= 0x0U,
	SPI_BUS_BUSY_TX = 0x1U,
	SPI_BUS_BUSY_RX = 0x2U

}SPI_BusStatus_t;

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
 * @def_group SPI_MSTR
 *
 */

#define SPI_MSTR_MASTER		((uint32_t)(0x00000004))
#define SPI_MSTR_SLAVE		((uint32_t)(0x00000000))


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
 * @def_group SPI_LSB_First
 *
 */

#define SPI_FRAMEFORMAT_MSB		((uint32_t)(0x00000000))
#define SPI_FRAMEFORMAT_LSB		((uint32_t)(0x00000080))


/*
 *
 * @def_group SPI_SSM
 *
 */

#define SPI_SSM_DISABLE		((uint32_t)(0x00000000))
#define SPI_SSM_ENABLE		((uint32_t)(0x00000300))


typedef enum {

	SPI_FLAG_RESET = 0x0U,
	SPI_FLAG_SET = !SPI_FLAG_RESET


}SPI_FlagStatus_t;

/*
 *
 * @def_group SPI_BUS_CONFIG
 *
 */

#define SPI_FULL_DUPLEX		((uint32_t)(0x00000000))
#define SPI_RECEIVE_ONLY	((uint32_t)(0x00000400))

#define SPI_HALF_DUPLEX_T	((uint32_t)(0x0000C000))
#define SPI_HALF_DUPLEX_R	((uint32_t)(0x00008000))


/*
 *
 * @def_group SPI_DFF
 *
 */

#define SPI_DFF_8BITS		((uint32_t)(0x00000000))
#define SPI_DFF_16BITS		((uint32_t)(0x00000800))


/*
 *
 * @def_group SPI_CRCNEXT
 *
 */

#define SPI_CRCNEXT_DISABLE	((uint32_t)(0x00000000))
#define SPI_CRCNEXT_ENABLE	((uint32_t)(0x00001000))


/*
 *
 * @def_group SPI_CRCEN
 *
 */

#define SPI_CRCEN_DISABLE	((uint32_t)(0x00000000))
#define SPI_CRCEN_ENABLE	((uint32_t)(0x00002000))






typedef struct {

	uint32_t CPHA;		// *!> Clock Phase value for SPI @def_group SPI_CPHA
	uint32_t CPOL;		// *!> Clock Polarity value for SPI @def_group SPI_CPOL
	uint32_t MSTR;		// *!> Master Mode value for SPI @def_group SPI_MSTR
	uint32_t BR;		// *!> BaudRate value for SPI @def_group SPI_BaudRates
	uint32_t LSB_First;	// *!> Frame(Less or Most significant bit) format value for SPI @def_group SPI_LSB_First
	uint32_t SSM;		// *!> Software slave management value for SPI @def_group SPI_SSM
	uint32_t BUS_CONFIG;// *!> Bus Configuration value for SPI @def_group SPI_BUS_CONFIG
	uint32_t DFF;		// *!> Data Frame Format value for SPI @def_group SPI_DFF
	uint32_t CRCNEXT;	// *!> CRC transfer next value for SPI @def_group SPI_CRCNEXT
	uint32_t CRCEN;		// *!> Hardware CRC calculation enable value for SPI @def_group SPI_CRCEN



}SPI_InitTypeDef_t;

typedef struct __SPI_HandleTypeDef_t {

	SPI_TypeDef_t* Instance;
	SPI_InitTypeDef_t Init;
	uint8_t  *pTxBufferAddr;
	uint16_t TxDataSize;
	uint8_t  Bus_StateTX;
	void(*TxISRFunction)(struct __SPI_HandleTypeDef_t *SPI_Handle);
	uint8_t  *pRxBufferAddr;
	uint16_t RxDataSize;
	uint8_t  Bus_StateRX;
	void(*RxISRFunction)(struct __SPI_HandleTypeDef_t *SPI_Handle);

}SPI_HandleTypeDef_t;

void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle);
void SPI_Perip_Cmd (SPI_HandleTypeDef_t *SPI_Handle, Functional_State_t stateOfSPI);
void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle,uint8_t *pData, uint16_t sizeOfData);
void SPI_TransmitData_Interrupt(SPI_HandleTypeDef_t *SPI_Handle,uint8_t *pData, uint16_t sizeOfData);
void SPI_ReceiveData(SPI_HandleTypeDef_t *SPI_Handle,uint8_t *pBuffer, uint16_t sizeOfData);
void SPI_ReceiveData_Interrupt(SPI_HandleTypeDef_t *SPI_Handle,uint8_t *pBuffer, uint16_t sizeOfData);
void SPI_Interrupt_Handler(SPI_HandleTypeDef_t *SPI_Handle);

SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypeDef_t *SPI_Handle,uint16_t SPI_Flag);

#endif /* SPI_H_ */
