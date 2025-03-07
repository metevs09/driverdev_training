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
 ************************************************** USART Fundemental Definitons ***************************************************************
 *
 */



/*
 * @def_group Mode_Types
 *
 */

#define USART_MODE_Tx			((uint32_t)(0x00000008))
#define USART_MODE_Rx			((uint32_t)(0x00000004))
#define USART_MODE_Tx_Rx		((uint32_t)(0x0000000C))





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
 * USART Fundemental Initialize Struct
 *
 */

typedef struct {

	uint32_t BaudRate;			/*!<  BaudRate Modes @def_group BaudRate_Types */
	uint32_t Mode;				/*!<  Transmission and Reception Modes @def_group Mode_Types */
	uint32_t OverSampling;		/*!<  OverSampling Modes @def_group OverSampling_Types */
	uint32_t Wordlength;		/*!<  8 bits and 9 bits  @def_group Wordlength_Types */
	uint32_t Parity;			/*!<  Even and Odd Parity Modes @def_group Parity_Types */
	uint32_t StopBits;			/*!<  Stop Bits Modes @def_group StopBits_Types */
	uint32_t HwFlowCtl;			/*!<  Hardaware FLow Control Modes @def_group HwFlowCtl_Types */

}USART_Init_Typedef;





/*
 ****************************************************** USART Advance Definitons ***************************************************************
 *
 */



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

#define CLK_ENABLE				((uint32_t)(0x00000800))
#define CLK_DISABLE				((uint32_t)(0x00000000))





/*
 * @def_group CPOL_Types
 *
 */

// This bit is not available for UART4 & UART5

#define CPOL_STDY_LOW			((uint32_t)(0x00000000))
#define CPOL_STDY_HIGH			((uint32_t)(0x00000400))





/*
 * @def_group CPHA_Types
 *
 */

// This bit is not available for UART4 & UART5

#define CPHA_FIRST_CLOCK 		((uint32_t)(0x00000000))
#define CPHA_SECOND_CLOCK		((uint32_t)(0x00000200))





/*
 * @def_group DMA_Types
 *
 */

#define USART_DMA_NON			((uint32_t)(0x00000000))
#define USART_DMA_Tx_EN			((uint32_t)(0x00000080))
#define USART_DMA_Rx_EN			((uint32_t)(0x00000040))
#define USART_DMA_Tx_Rx_EN		((uint32_t)(0x000000C0))





/*
 * @def_group SC_MODE_Types
 *
 */

// This bit is not available for UART4 & UART5

#define USART_SC_NON 			((uint32_t)(0x00000000))
#define USART_SC_EN				((uint32_t)(0x00000020))
#define USART_SC_NACK_EN		((uint32_t)(0x00000030))





/*
 * @def_group HDSEL_Types
 *
 */

#define USART_HDSEL_NON			((uint32_t)(0x00000000))
#define USART_HDSEL_EN			((uint32_t)(0x00000008))





/*
 * @def_group IRDA_MODE_Types
 *
 */

#define USART_IrDA_NON			((uint32_t)(0x00000000))
#define USART_IrDA_EN			((uint32_t)(0x00000000))
#define USART_IrDA_LPWR_EN		((uint32_t)(0x00000000))





/*
 * @def_group ONEBIT_Types
 *
 */

#define USART_ONEBIT_EN			((uint32_t)(0x00000800))
#define USART_TREEBIT_EN		((uint32_t)(0x00000000))





/*
 * @def_group LIN_MODE_Types
 *
 */

#define USART_LIN_NON			((uint32_t)(0x00000000))
#define USART_LIN_10_BIT_DTC_EN	((uint32_t)(0x00004000))
#define USART_LIN_11_BIT_DTC_EN	((uint32_t)(0x00004020))





/*
 * @def_group LBCL_MODE_Types
 *
 */

// This bit is not available for UART4 & UART5
// The last bit is the 8th or 9th data bit transmitted depending on the 8 or 9 bit format selected by the M bit in the USART_CR1 register.

#define USART_LBCL_NON			((uint32_t)(0x00000000))
#define USART_LBCL_EN			((uint32_t)(0x00000100))





/*
 * @def_group WAKE_Types
 *
 */

#define USART_WAKE_IDLE			((uint32_t)(0x00000000))
#define USART_WAKE_ADDR_MARK	((uint32_t)(0x00000800))




/*
 * @def_group RWU_MODE_Types
 *
 */

// Before selecting Mute mode (by setting the RWU bit) the USART must first receive a data byte, otherwise it cannot function in Mute mode with wakeup by Idle line detection.
// In Address Mark Detection wakeup configuration (WAKE bit=1) the RWU bit cannot be modified by software while the RXNE bit is set.

#define USART_RWU_ACTIVE		((uint32_t)(0x00000000))
#define USART_RWU_MUTE			((uint32_t)(0x00000002))





/*
 * @def_group SENDBRK_MODE_Types
 *
 */

#define USART_SENDBRK_NON		((uint32_t)(0x00000000))
#define USART_SENDBRK_EN		((uint32_t)(0x00000001))





/*
 * USART FLAG enum
 *
 */

typedef enum{
	USART_FLAG_RESET = 0x0U,
	USART_FLAG_SET = !USART_FLAG_RESET

}USART_FlagStatus_t;





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
		uint32_t SC_MOD;		/*!<  Smartcard  Modes @def_group SC_MOD_Types */
		uint32_t HDSEL;			/*!<  Half-duplex selection Modes @def_group HDSEL_Types */
		uint32_t IRDA_MODE;		/*!<  IrDA enable and low power configuration Modes @def_group IRDA_MODE_Types */
		uint32_t ONEBIT;		/*!<  One sample bit method enable Modes @def_group ONEBIT_Types */
		uint32_t LIN_MODE;		/*!<  LIN enable  break detection length Modes @def_group LIN_MODE_Types */
		uint32_t LBCL;			/*!<  Last bit clock pulse Modes @def_group LBCL_MODE_Types */
		uint32_t WAKE;			/*!<  Wakeup method Modes @def_group WAKE_Types */
		uint32_t RWU;			/*!<  Receiver wakeup method Modes @def_group RWU_MODE_Types */
		uint32_t SENDBRK;		/*!<  Send break method Modes @def_group SENDBRK_MODE_Types */

}USART_Advance_Init_Typedef;





/*
 * USART Handle Struct
 *
 */


typedef struct {

	USART_TypeDef_t *Instance;
	USART_Init_Typedef Init;
	USART_Advance_Init_Typedef Advance_Init;

}USART_Handle_Typedef;





/*
 *
 * Prototypes of USART Functions
 *
 */

void USART_Init(USART_Handle_Typedef *USART_Handle);
void USART_TransmitData(USART_Handle_Typedef *USART_Handle, uint8_t *pData,uint16_t dataSize);
USART_FlagStatus_t USART_GetFlagStatus(USART_Handle_Typedef *USART_Handle, uint16_t flagName);


#endif /* INC_USART_H_ */
