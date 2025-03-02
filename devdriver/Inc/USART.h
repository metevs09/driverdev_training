/*
 * USART.h
 *
 *  Created on: Mar 1, 2025
 *      Author: Metehan
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include "stm32f407xx.h"


/*
 * @def_group Mode_Types
 *
 */

#define USART_MODE_Tx			((uint32_t)(0x00000008))
#define USART_MODE_Rx			((uint32_t)(0x00000004))
#define USART_MODE_Tx_Rx		((uint32_t)(0x0000000C))





/*
 * @def_group USART_EN_Types
 *
 */

#define USART_ENABLE			((uint32_t)(0x00002000))
#define USART_DISABLE			((uint32_t)(0x00000000))





/*
 * @def_group CLK_EN_Types
 *
 */

// This bit is not available for UART4 & UART5

#define CLK_ENABLE			((uint32_t)(0x00000800))
#define CLK_DISABLE			((uint32_t)(0x00000000))




/*
 * @def_group CPOL_Types
 *
 */

// This bit is not available for UART4 & UART5

#define CPOL_STDY_LOW		((uint32_t)(0x00000000))
#define CPOL_STDY_HIGH		((uint32_t)(0x00000400))





/*
 * @def_group Wordlength_Types
 *
 */

#define USART_WORDLENGTH_8Bits	((uint32_t)(0x00000000))
#define USART_WORDLENGTH_9Bits	((uint32_t)(0x00001000))





/*
 * @def_group Parity_Types
 *
 */

#define USART_PARITY_NONE	((uint32_t)(0x00000000))
#define USART_PARITY_EVEN	((uint32_t)(0x00000400))
#define USART_PARITY_ODD	((uint32_t)(0x00000600))





/*
 * @def_group StopBits_Types
 *
 */

// Note: The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
// p = .
#define USART_STOPBITS_0p5	((uint32_t)(0x00001000))
#define USART_STOPBITS_1	((uint32_t)(0x00000000))
#define USART_STOPBITS_1p5	((uint32_t)(0x00003000))
#define USART_STOPBITS_2	((uint32_t)(0x00002000))





/*
 * @def_group OverSampling_Types
 *
 */

#define USART_OVERSAMPL_8	((uint32_t)(0x00008000))
#define USART_OVERSAMPL_16	((uint32_t)(0x00000000))





/*
 * @def_group Hardware Flow Control Modes _Types
 *
 */

#define USART_HW_NONE		((uint32_t)(0x00000000))
#define USART_HW_CTSE		((uint32_t)(0x00000200))
#define USART_HW_RTSE		((uint32_t)(0x00000100))
#define USART_HW_CTSE_RTSE	((uint32_t)(0x00000300))




/*
 * @def_group Hardware Flow Control Modes _Types
 *
 */

#define USART_DMA_NONE		((uint32_t)(0x00000000))
#define USART_DMA_EN_Tx		((uint32_t)(0x00000080))
#define USART_DMA_EN_Rx		((uint32_t)(0x00000040))
#define USART_DMA_EN_Tx_Rx	((uint32_t)(0x000000C0))





/*
 * USART Basic Initialize Struct
 *
 */

typedef struct {

	uint32_t BaudRate;		/*!<  BaudRate Modes @def_group BaudRate_Types */
	uint32_t Mode;			/*!<  Transmission and Reception Modes @def_group Mode_Types */
	uint32_t OverSampling;	/*!<  OverSampling Modes @def_group OverSampling_Types */
	uint32_t Wordlength;	/*!<  8 bits and 9 bits  @def_group Wordlength_Types */
	uint32_t Parity;		/*!<  Even and Odd Parity Modes @def_group Parity_Types */
	uint32_t StopBits;		/*!<  Stop Bits Modes @def_group StopBits_Types */
	uint32_t HwFlowCtl;		/*!<  Hardaware FLow Control Modes @def_group HwFlowCtl_Types */

}USART_Basic_Init_Typedef;





/*
 * USART Advance Initialize Struct
 *
 */

typedef struct {

		uint32_t USART_EN;		/*!<  USART Enable Modes @def_group USART_EN_Types */
		uint32_t CLK_EN;		/*!<  Clock Enable Modes @def_group CLK_EN_Types */
		uint32_t CPOL;			/*!<  Clock polarity Modes @def_group CPOL_Types */
		uint32_t CPHA;			/*!<  Clock phase Modes @def_group CPHA_Types */
		uint32_t DMA;			/*!<  Direct Memory Access Modes @def_group DMA_Types */

}USART_Advance_Init_Typedef;

typedef struct {

	USART_TypeDef_t *Instance;
	USART_Basic_Init_Typedef Init;
	USART_Advance_Init_Typedef Advance_Init;

}USART_Handle_Typedef;

#endif /* INC_USART_H_ */
