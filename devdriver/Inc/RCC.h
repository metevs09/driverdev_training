/*
 * RCC.h
 *
 *  Created on: May 11, 2024
 *      Author: Metehan
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include"stm32f407xx.h"

#define RCC_GPIOA_CLK_ENABLE()	do{ uint32_t tempValue = 0;	\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);	\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);\
									UNUSED(tempValue);\
									}while(0)



#endif /* INC_RCC_H_ */
