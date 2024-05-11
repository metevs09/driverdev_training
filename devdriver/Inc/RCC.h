/*
 * RCC.h
 *
 *  Created on: May 11, 2024
 *      Author: Metehan
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include"stm32f407xx.h"

/*
 *  SET AND CLEAR MACROS FOR GPIOS'S PORTS
 */



/*
 * GPIOA SET AND CLEAR MACROS
 */

// GPIOA's set macros
#define RCC_GPIOA_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOA's clear macros
#define RCC_GPIOA_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);\
									UNUSED(tempValue);\
									}while(0)


/*
 * GPIOB SET AND CLEAR MACROS
 */

// GPIOB's set macros
#define RCC_GPIOB_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOB's clear macros
#define RCC_GPIOB_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);\
									UNUSED(tempValue);\
									}while(0)


/*
 * GPIOC SET AND CLEAR MACROS
 */

// GPIOC's set macros
#define RCC_GPIOC_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOC's clear macros
#define RCC_GPIOC_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);\
									UNUSED(tempValue);\
									}while(0)


/*
 * GPIOD SET AND CLEAR MACROS
 */

// GPIOD's set macros
#define RCC_GPIOD_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOD's clear macros
#define RCC_GPIOD_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);\
									UNUSED(tempValue);\
									}while(0)


/*
 * GPIOE SET AND CLEAR MACROS
 */

// GPIOE's set macros
#define RCC_GPIOE_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOE's clear macros
#define RCC_GPIOE_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN);\
									UNUSED(tempValue);\
									}while(0)


/*
 * GPIOF SET AND CLEAR MACROS
 */

// GPIOF's set macros
#define RCC_GPIOF_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOF's clear macros
#define RCC_GPIOF_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN);\
									UNUSED(tempValue);\
									}while(0)


/*
 * GPIOG SET AND CLEAR MACROS
 */

// GPIOG's set macros
#define RCC_GPIOG_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOG's clear macros
#define RCC_GPIOG_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN);\
									UNUSED(tempValue);\
									}while(0)


/*
 * GPIOH SET AND CLEAR MACROS
 */

// GPIOH's set macro
#define RCC_GPIOH_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOH's clear macros
#define RCC_GPIOH_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN);\
									UNUSED(tempValue);\
									}while(0)


/*
 * GPIOI SET AND CLEAR MACROS
 */

// GPIOI's set macro
#define RCC_GPIOI_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOIEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOIEN);\
									UNUSED(tempValue);\
									}while(0)

// GPIOI's clear macros
#define RCC_GPIOI_CLK_DISABLE()	do{ uint32_t tempValue = 0;\
									CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOIEN);\
									tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOIEN);\
									UNUSED(tempValue);\
									}while(0)




#endif /* INC_RCC_H_ */
