/*
 * RCC.h
 *
 *  Created on: May 11, 2024
 *      Author: Metehan
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include"stm32f407xx.h"

#define RCC_GPIOA_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);\
									UNUSED(tempValue);\
									}while(0)

#define RCC_GPIOB_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);\
									UNUSED(tempValue);\
									}while(0)

#define RCC_GPIOC_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);\
									UNUSED(tempValue);\
									}while(0)

#define RCC_GPIOD_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);\
									UNUSED(tempValue);\
									}while(0)

#define RCC_GPIOE_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);\
									UNUSED(tempValue);\
									}while(0)

#define RCC_GPIOF_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN);\
									UNUSED(tempValue);\
									}while(0)

#define RCC_GPIOG_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN);\
									UNUSED(tempValue);\
									}while(0)

#define RCC_GPIOH_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN);\
									UNUSED(tempValue);\
									}while(0)

#define RCC_GPIOI_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOIEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOIEN);\
									UNUSED(tempValue);\
									}while(0)


#endif /* INC_RCC_H_ */
