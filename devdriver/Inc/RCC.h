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
 *  **************************************************  GPIO'S SET AND CLEAR MACROS ************************************************************
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
#define RCC_GPIOA_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN)


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
#define RCC_GPIOB_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN)


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
#define RCC_GPIOC_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN)



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
#define RCC_GPIOD_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN)



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
#define RCC_GPIOE_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN)



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
#define RCC_GPIOF_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN)


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
#define RCC_GPIOG_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN)



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
#define RCC_GPIOH_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOHEN)



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
#define RCC_GPIOI_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOIEN)










/*
 *  ***********************************************  SYSCFG SET AND CLEAR MACROS ***************************************************************
 */





// SYSCFG's set macro
#define RCC_SYSCFG_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN);\
									tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN);\
									UNUSED(tempValue);\
									}while(0)

// SYSCFG's clear macros
#define RCC_SYSCFG_CLK_DISABLE()	CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN)










/*
 *  **************************************************  SPI SET AND CLEAR MACROS ***************************************************************
 */





/*
 * SPI1 SET AND CLEAR MACROS
 */

// SPI1's set macro
#define RCC_SPI1_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1EN);\
									tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1EN);\
									UNUSED(tempValue);\
									}while(0)

// SPI1's clear macros
#define RCC_SPI1_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1EN)





/*
 * SPI2 SET AND CLEAR MACROS
 */


// SPI2's set macro
#define RCC_SPI2_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2EN);\
									tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2EN);\
									UNUSED(tempValue);\
									}while(0)

// SPI2's clear macros
#define RCC_SPI2_CLK_DISABLE()		CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2EN)





/*
 * SPI3 SET AND CLEAR MACROS
 */


// SPI3's set macro
#define RCC_SPI3_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3EN);\
									tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3EN);\
									UNUSED(tempValue);\
									}while(0)

// SPI3's clear macros
#define RCC_SPI3_CLK_DISABLE()		CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3EN)





/*
 * SPI4 SET AND CLEAR MACROS
 */


// SPI4's set macro
#define RCC_SPI4_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4EN);\
									tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4EN);\
									UNUSED(tempValue);\
									}while(0)

// SPI4's clear macros
#define RCC_SPI4_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4EN)





/*
 * SPI5 SET AND CLEAR MACROS
 */


// SPI5's set macro
#define RCC_SPI5_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI5EN);\
									tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI5EN);\
									UNUSED(tempValue);\
									}while(0)

// SPI5's clear macros
#define RCC_SPI5_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI5EN)





/*
 * SPI6 SET AND CLEAR MACROS
 */


// SPI5's set macro
#define RCC_SPI6_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI6EN);\
									tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI6EN);\
									UNUSED(tempValue);\
									}while(0)

// SPI5's clear macros
#define RCC_SPI6_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI6EN)









/*
 *  **************************************************  USART'S SET AND CLEAR MACROS ***********************************************************
 */





/*
 * USART1 SET AND CLEAR MACROS
 */

// USART1's set macro
#define RCC_USART1_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB2ENR,RCC_APB2ENR_USART1EN);\
									tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_USART1EN);\
									UNUSED(tempValue);\
									}while(0)

// USART1's clear macros
#define RCC_UART1_CLK_DISABLE()		CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_USART1EN)




/*
 * USART2 SET AND CLEAR MACROS
 */

// USART2's set macro
#define RCC_USART2_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2EN);\
									tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2EN);\
									UNUSED(tempValue);\
									}while(0)

// USART2's clear macros
#define RCC_USART2_CLK_DISABLE()	CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2EN)




/*
 * USART3 SET AND CLEAR MACROS
 */

// USART3's set macro
#define RCC_USART3_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART3EN);\
									tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1ENR_USART3EN);\
									UNUSED(tempValue);\
									}while(0)

// USART3's clear macros
#define RCC_USART3_CLK_DISABLE()	CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_USART3EN)





/*
 * UART4 SET AND CLEAR MACROS
 */

// UART4's set macro
#define RCC_UART4_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB1ENR,RCC_APB1ENR_UART4EN);\
									tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1ENR_UART4EN);\
									UNUSED(tempValue);\
									}while(0)

// UART4's clear macros
#define RCC_UART4_CLK_DISABLE()	CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_UART4EN)




/*
 * UART5 SET AND CLEAR MACROS
 */

// UART5's set macro
#define RCC_UART5_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB1ENR,RCC_APB1ENR_UART5EN);\
									tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1ENR_UART5EN);\
									UNUSED(tempValue);\
									}while(0)

// UART5's clear macros
#define RCC_UART5_CLK_DISABLE()	CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_UART5EN)





/*
 * USART6 SET AND CLEAR MACROS
 */

// USART6's set macro
#define RCC_USART6_CLK_ENABLE()	do{ uint32_t tempValue = 0;\
									SET_BIT(RCC->APB2ENR,RCC_APB2ENR_USART6EN);\
									tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_USART6EN);\
									UNUSED(tempValue);\
									}while(0)

// USART6's clear macros
#define RCC_USART6_CLK_DISABLE()	CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_USART6EN)




/*
 *  **************************************************  RCC Function Prototype *****************************************************************
 */


uint32_t RCC_GetSystemClock(void);
uint32_t RCC_GetHClock(void);
uint32_t RCC_GetAPB1Clock(void);
uint32_t RCC_GetAPB2Clock(void);


#endif /* INC_RCC_H_ */
