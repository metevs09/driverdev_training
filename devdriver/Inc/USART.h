/*
 * USART.h
 *
 *  Created on: Mar 1, 2025
 *      Author: Metehan
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include "stm32f407xx.h"

typedef struct {

	uint32_t BaudRate;
	uint32_t OverSampling;
	uint32_t Wordlength;
	uint32_t Parity;
	uint32_t Mode;
	uint32_t StopBits;
	uint32_t HardwareFlowControl;
	uint32_t DMA;
}USART_Init_Typedef;

typedef struct {

	USART_TypeDef_t *Instance;
	USART_Init_Typedef Init;

}USART_Handle_Typedef;

#endif /* INC_USART_H_ */
