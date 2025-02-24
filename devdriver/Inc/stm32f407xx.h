/*
 * stm32f407xx.h
 *
 *  Created on: Apr 27, 2024
 *      Author: Metehan
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <string.h>

/*
 *
 * Microprocessor Defines
 *
 */

#define NVIC_ISER0 				((uint32_t *)(0xE000E100))

#define __IO volatile

#define SET_BIT(REG,BIT)		((REG) |=  (BIT))
#define CLEAR_BIT(REG,BIT)		((REG) &= ~(BIT))
#define READ_BIT(REG,BIT)		((REG)  &  (BIT))

#define UNUSED(x)				(void)x

typedef enum{
	DISABLE = 0x0U,
	ENABLE = !DISABLE

}Functional_State_t;


/*
 * IRQ Numbers of MCU == Vector Table
 *
 */


typedef enum{

	WWDG_IRQNumber =0,
	PVD_IRQNumber =1,
	TAMP_STAMP_IRQNumber =2,
	RTC_WKUP_IRQNumber =3,
	FLASH_IRQNumber = 4,
	RCC_IRQNumber = 5,
	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	EXTI4_IRQNumber = 10,
	DMA1_Stream0_IRQNumber = 11,
	DMA1_Stream1_IRQNumber = 12,
	DMA1_Stream2_IRQNumber = 13,
	DMA1_Stream3_IRQNumber = 14,
	DMA1_Stream4_IRQNumber = 15,
	DMA1_Stream5_IRQNumber = 16,
	DMA1_Stream6_IRQNumber = 17,
	ADC_IRQNumber = 18,
	CAN1_TX_IRQNumber = 19,
	CAN1_RX0_IRQNumber = 20,
	CAN1_RX1_IRQNumber = 21,
	CAN1_SCE_IRQNumber = 22,
	EXTI9_5_IRQNumber = 23,
	TIM1_BRK_TIM9_IRQNumber = 24,
	TIM1_UP_TIM10_IRQNumber = 25,
	TIM1_TRG_COM_TIM11_IRQNumber = 26,
	TIM1_CC_IRQNumber = 27,
	TIM2_IRQNumber = 28,
	TIM3_IRQNumber = 29,
	TIM4_IRQNumber = 30,
	I2C1_EV_IRQNumber = 31,
	I2C1_ER_IRQNumber = 32,
	I2C2_EV_IRQNumber = 33,
	I2C2_ER_IRQNumber = 34,
	SPI1_IRQNumber = 35,
	SPI2_IRQNumber = 36,
	USART1_IRQNumber = 37,
	USART2_IRQNumber = 38,
	USART3_IRQNumber = 39,
	EXTI15_10_IRQNumber = 40,
	RTC_Alarm_IRQNumber = 41,
	OTG_FS_WKUP_IRQNumber = 42,
	TIM8_BRK_TIM12_IRQNumber = 43,
	TIM8_UP_TIM13_IRQNumber = 44,
	TIM8_TRG_COM_TIM14_IRQNumber = 45,
	TIM8_CC_IRQNumber = 46,
	DMA1_Stream7_IRQNumber = 47,
	FSMC_IRQNumber = 48,
	SDIO_IRQNumber = 49,
	TIM5_IRQNumber = 50,
	SPI3_IRQNumber = 51,
	UART4_IRQNumber = 52,
	UART5_IRQNumber = 53,
	TIM6_DAC_IRQNumber = 54,
	TIM7_IRQNumber = 55,
	DMA2_Stream0_IRQNumber = 56,
	DMA2_Stream1_IRQNumber = 57,
	DMA2_Stream2_IRQNumber = 58,
	DMA2_Stream3_IRQNumber = 59,
	DMA2_Stream4_IRQNumber = 60,
	ETH_IRQNumber = 61,
	ETH_WKUP_IRQNumber = 62,
	CAN2_TX_IRQNumber = 63,
	CAN2_RX0_IRQNumber = 64,
	CAN2_RX1_IRQNumber = 65,
	CAN2_SCE_IRQNumber = 66,
	OTG_FS_IRQNumber = 67,
	DMA2_Stream5_IRQNumber = 68,
	DMA2_Stream6_IRQNumber = 69,
	DMA2_Stream7_IRQNumber = 70,
	USART6_IRQNumber = 71,
	I2C3_EV_IRQNumber = 72,
	I2C3_ER_IRQNumber = 73,
	OTG_HS_EP1_OUT_IRQNumber = 74,
	OTG_HS_EP1_IN_IRQNumber = 75,
	OTG_HS_WKUP_IRQNumber = 76,
	OTG_HS_IRQNumber = 77,
	DCMI_IRQNumber = 78,
	CRYP_IRQNumber = 79,
	HASH_RNG_IRQNumber = 80,
	FPU_IRQNumber = 81

}IRQNumber_TypeDef_t;




/*
 * Memory Base Address (Address starting hex number on reference manual)
 *
 */

#define FLASH_BASE_ADDR			(0x08000000UL)                          /* Defined FLASH base address(up to 1 MB) */

#define SRAM1_BASE_ADDR			(0x20000000UL)                          /* Defined SRAM1 base address(up to 112 KB) */
#define SRAM2_BASE_ADDR			(0x2001C000UL)                          /* Defined SRAM2 base address(up to 16 KB) */

/*
 * Peripheral Base Addresses (Address starting hex number on reference manual)
 *
 */

#define PERIP_BASE_ADDR			(0x40000000UL)                          /* Defined peripheral base address for all peripheral */

#define APB1_BASE_ADDR			(PERIP_BASE_ADDR + 0x00000000UL)        /* APB1 bus domain base address */
#define APB2_BASE_ADDR			(PERIP_BASE_ADDR + 0x00010000UL)        /* APB2 bus domain base address */
#define AHB1_BASE_ADDR			(PERIP_BASE_ADDR + 0x00020000UL)        /* AHB1 bus domain base address */
#define AHB2_BASE_ADDR			(PERIP_BASE_ADDR + 0x10000000UL)        /* AHB2 bus domain base address */
#define AHB3_BASE_ADDR			(PERIP_BASE_ADDR + 0x60000000UL)        /* AHB3 bus domain base address */


/*
 * APB1 Peripheral Base Addresses (Address starting hex number on reference manual)
 *
 */

#define TIM2_BASE_ADDR			(APB1_BASE_ADDR + 0x00000000UL)         /* Defined TIMER2 base address */
#define TIM3_BASE_ADDR			(APB1_BASE_ADDR + 0x00000400UL)         /* Defined TIMER3 base address */
#define TIM4_BASE_ADDR			(APB1_BASE_ADDR + 0x00000800UL)         /* Defined TIMER4 base address */
#define TIM5_BASE_ADDR			(APB1_BASE_ADDR + 0x00000C00UL)         /* Defined TIMER5 base address */

#define TIM6_BASE_ADDR			(APB1_BASE_ADDR + 0x00001000UL)         /* Defined TIMER6 base address */
#define TIM7_BASE_ADDR			(APB1_BASE_ADDR + 0x00001400UL)         /* Defined TIMER7 base address */

#define TIM12_BASE_ADDR			(APB1_BASE_ADDR + 0x00001800UL)         /* Defined TIMER12 base address */

#define TIM13_BASE_ADDR			(APB1_BASE_ADDR + 0x00001C00UL)         /* Defined TIMER13 base address */
#define TIM14_BASE_ADDR			(APB1_BASE_ADDR + 0x00002000UL)         /* Defined TIMER14 base address */

#define RTC_BKP_REG_BASE_ADDR	(APB1_BASE_ADDR + 0x00002800UL)         /* Defined RTC & BKP Registers base address */

#define WWDG_BASE_ADDR			(APB1_BASE_ADDR + 0x00002C00UL)         /* Defined WWDG base address */

#define IWDG_BASE_ADDR			(APB1_BASE_ADDR + 0x00003000UL)         /* Defined IWDG base address */

#define I2S2EX_BASE_ADDR		(APB1_BASE_ADDR + 0x00003400UL)         /* Defined I2S2ext base address */
#define SPI2_BASE_ADDR			(APB1_BASE_ADDR + 0x00003800UL)         /* Defined SPI2 / I2S2 base address */
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR + 0x00003C00UL)         /* Defined SPI3 / I2S3 base address */
#define I2S3EX_BASE_ADDR		(APB1_BASE_ADDR + 0x00004000UL)         /* Defined I2S3ext base address */

#define USART2_BASE_ADDR		(APB1_BASE_ADDR + 0x00004400UL)         /* Defined USART2 base address */
#define USART3_BASE_ADDR		(APB1_BASE_ADDR + 0x00004800UL)         /* Defined USART3 base address */
#define UART4_BASE_ADDR			(APB1_BASE_ADDR + 0x00004C00UL)         /* Defined UART4 base address */
#define UART5_BASE_ADDR			(APB1_BASE_ADDR + 0x00005000UL)         /* Defined UART5 base address */

#define I2C1_BASE_ADDR			(APB1_BASE_ADDR + 0x00005400UL)			/* Defined I2C1 base address */
#define I2C2_BASE_ADDR			(APB1_BASE_ADDR + 0x00005800UL)			/* Defined I2C2 base address */
#define I2C3_BASE_ADDR			(APB1_BASE_ADDR + 0x00005C00UL)			/* Defined I2C3 base address */

#define CAN1_BASE_ADDR			(APB1_BASE_ADDR + 0x00006400UL)			/* Defined CAN1 base address */
#define CAN2_BASE_ADDR			(APB1_BASE_ADDR + 0x00006800UL)			/* Defined CAN2 base address */

#define PWR_BASE_ADDR			(APB1_BASE_ADDR + 0x00007000UL)			/* Defined PWR base address */

#define DAC_BASE_ADDR			(APB1_BASE_ADDR + 0x00007400UL)			/* Defined DAC base address */

#define UART7_BASE_ADDR			(APB1_BASE_ADDR + 0x00007800UL)         /* Defined UART7 base address */
#define UART8_BASE_ADDR			(APB1_BASE_ADDR + 0x00007C00UL)         /* Defined UART8 base address */

/*
 * APB2 Peripheral Base Addresses (Address starting hex number on reference manual)
 *
 */

#define  TIM1_BASE_ADDR			(APB2_BASE_ADDR + 0x00000000UL)			/* Defined TIMER1 base address */
#define  TIM8_BASE_ADDR			(APB2_BASE_ADDR + 0x00000400UL)			/* Defined TIMER8 base address */

#define	 USART1_BASE_ADDR		(APB2_BASE_ADDR + 0x00001000UL)			/* Defined USART1 base address */
#define	 USART6_BASE_ADDR		(APB2_BASE_ADDR + 0x00001400UL)			/* Defined USART6 base address */

#define	 ADC1_2_3_BASE_ADDR		(APB2_BASE_ADDR + 0x00002000UL)			/* Defined ADC1 - ADC2 - ADC3 base address */

#define	 SDIO_BASE_ADDR			(APB2_BASE_ADDR + 0x00002C00UL)			/* Defined SDIO base address */

#define	 SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0x00003000UL)			/* Defined SPI1 base address */

#define  SPI4_BASE_ADDR			(APB2_BASE_ADDR + 0x00003400UL)			/* Defined SPI4 base address */

#define  SYSCFG_BASE_ADDR		(APB2_BASE_ADDR + 0x00003800UL)			/* Defined SYSCFG base address */

#define  EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0x00003C00UL)			/* Defined EXTI base address */

#define  TIM9_BASE_ADDR			(APB2_BASE_ADDR + 0x00004000UL)			/* Defined TIMER9 base address */

#define  TIM10_BASE_ADDR		(APB2_BASE_ADDR + 0x00004400UL)			/* Defined TIMER10 base address */
#define  TIM11_BASE_ADDR		(APB2_BASE_ADDR + 0x00004800UL)			/* Defined TIMER11 base address */

#define  SPI5_BASE_ADDR			(APB2_BASE_ADDR + 0x00005000UL)			/* Defined SPI5 base address */
#define  SPI6_BASE_ADDR			(APB2_BASE_ADDR + 0x00005400UL)			/* Defined SPI6 base address */

#define  SAI1_BASE_ADDR			(APB2_BASE_ADDR + 0x00005800UL)			/* Defined SAI1 base address */
#define  LCD_TFT_BASE_ADDR		(APB2_BASE_ADDR + 0x00006800UL)			/* Defined LCD-TFT base address */

/*
 * AHB1 Peripheral Base Addresses (Address starting hex number on reference manual)
 *
 */

#define GPIOA_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000000UL)			/* Defined GPIOA base address */
#define GPIOB_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000400UL)			/* Defined GPIOB base address */
#define GPIOC_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000800UL)			/* Defined GPIOC base address */
#define GPIOD_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000C00UL)			/* Defined GPIOD base address */
#define GPIOE_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001000UL)			/* Defined GPIOE base address */
#define GPIOF_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001400UL)			/* Defined GPIOF base address */
#define GPIOG_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001800UL)			/* Defined GPIOG base address */
#define GPIOH_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001C00UL)			/* Defined GPIOH base address */
#define GPIOI_BASE_ADDR			(AHB1_BASE_ADDR + 0x00002000UL)			/* Defined GPIOI base address */
/*
#define GPIOJ_BASE_ADDR			(AHB1_BASE_ADDR + 0x00002400UL)			 Not available for stm32f407xx series but added memory map
#define GPIOK_BASE_ADDR			(AHB1_BASE_ADDR + 0x00002800UL)			 Not available for stm32f407xx series but added memory map */

#define CRC_BASE_ADDR			(AHB1_BASE_ADDR + 0x00003000UL)			/* Defined CRC base address */

#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + 0x00003800UL)			/* Defined RCC base address */

#define FIR_BASE_ADDR			(AHB1_BASE_ADDR + 0x00003C00UL)			/* Defined FIR (Flash interface register) base address */

#define BKPSRAM_BASE_ADDR		(AHB1_BASE_ADDR + 0x00004000UL)			/* Defined BKPSRAM base address */

#define DMA1_BASE_ADDR			(AHB1_BASE_ADDR + 0x00006000UL)			/* Defined DMA1 base address */
#define DMA2_BASE_ADDR			(AHB1_BASE_ADDR + 0x00006400UL)			/* Defined DMA2 base address */

#define ETH_MAC_BASE_ADDR		(AHB1_BASE_ADDR + 0x00008000UL)			/* Defined ETHERNET MAC base address */

#define DMA2D_BASE_ADDR			(AHB1_BASE_ADDR + 0x0000B000UL)			/* Defined DMA2D base address */

#define USB_OTG_HS_BASE_ADDR	(AHB1_BASE_ADDR + 0x00020000UL)			/* Defined USB OTG HS base address */

/*
 * AHB2 Peripheral Base Addresses (Address starting hex number on reference manual)
 *
 */

#define USB_OTG_FS_BASE_ADDR	(AHB2_BASE_ADDR + 0x00000000UL)			/* Defined USB OTG FS base address */

#define DCMI_BASE_ADDR			(AHB2_BASE_ADDR + 0x00050000UL)			/* Defined DCMI base address */

#define CRYP_BASE_ADDR			(AHB2_BASE_ADDR + 0x00060000UL)			/* Defined CRYP base address */

#define HASH_BASE_ADDR			(AHB2_BASE_ADDR + 0x00060400UL)			/* Defined HASH base address */

#define RNG_BASE_ADDR			(AHB2_BASE_ADDR + 0x00060800UL)			/* Defined RNG base address */

/*
 * AHB3 Peripheral Base Addresses (Address starting hex number on reference manual)
 *
 */

#define FSMC_CONT_REG_BASE_ADDR	(AHB3_BASE_ADDR + 0x00000000UL)			/* Defined FSMC control register base address */


/*
 * Peripheral Structure Definitions (For more information check reference manual GPIO register map)
 *
 */

typedef struct {

	__IO uint32_t MODER;		/*!< GPIO port mode register 					Address offset = 0x0000 */
	__IO uint32_t OTYPER;		/*!< GPIO port output type register 			Address offset = 0x0004 */
	__IO uint32_t OSPEEDR;		/*!< GPIO port output speed register 			Address offset = 0x0008 */
	__IO uint32_t PUPDR;		/*!< GPIO port pull-up/pull-down register 		Address offset = 0x000C */
	__IO uint32_t IDR;			/*!< GPIO port input data register 				Address offset = 0x0010 */
	__IO uint32_t ODR;			/*!< GPIO port output data register 			Address offset = 0x0014 */
	__IO uint32_t BSRR;			/*!< GPIO port bit set/reset register 			Address offset = 0x0018 */
	__IO uint32_t LCKR;			/*!< GPIO port configuration lock register 		Address offset = 0x001C */
	__IO uint32_t AFR[2];		/*!< GPIO alternate function low register 		Address offset for AFRL = 0x0020, AFRH = 0x0024 */

}GPIO_TypeDef_t;


typedef struct {

	// per.=peripheral, lpm= low power mode, spec.= spectrum

	__IO uint32_t CR;			/*!< RCC clock control register  				Address offset = 0x0000 */
	__IO uint32_t PLLCFGR;		/*!< RCC PLL configuration register  			Address offset = 0x0004 */
	__IO uint32_t CFGR;			/*!< RCC clock configuration register  			Address offset = 0x0008 */
	__IO uint32_t CIR;			/*!< RCC clock interrupt register  				Address offset = 0x000C */
	__IO uint32_t AHB1RSTR;		/*!< RCC AHB1 peripheral reset register  		Address offset = 0x0010 */
	__IO uint32_t AHB2RSTR;		/*!< RCC AHB2 peripheral reset register  		Address offset = 0x0014 */
	__IO uint32_t AHB3RSTR;		/*!< RCC AHB3 peripheral reset register  		Address offset = 0x0018 */
	__IO uint32_t RESERVED0;	/*!< RESERVED AREA do not any manipulation!!!	Address offset = 0x001C	*/
	__IO uint32_t APB1RSTR;		/*!< RCC APB1 peripheral reset register 		Address offset = 0x0020 */
	__IO uint32_t APB2RSTR;		/*!< RCC APB2 peripheral reset register  		Address offset = 0x0024 */
	__IO uint32_t RESERVED1[2];	/*!< RESERVED AREA do not any manipulation!!!	Address offset = 0x0028	*/
	__IO uint32_t AHB1ENR;		/*!< RCC AHB1 per.clock enable register			Address offset = 0x0030 */
	__IO uint32_t AHB2ENR;		/*!< RCC AHB2 per.clock enable register   		Address offset = 0x0034 */
	__IO uint32_t AHB3ENR;		/*!< RCC AHB3 per.clock enable register  		Address offset = 0x0038 */
	__IO uint32_t RESERVED2;	/*!< RESERVED AREA do not any manipulation!!!	Address offset = 0x003C	*/
	__IO uint32_t APB1ENR;		/*!< RCC APB1 per.clock enable register  		Address offset = 0x0040 */
	__IO uint32_t APB2ENR;		/*!< RCC APB2 per.clock enable register  		Address offset = 0x0044 */
	__IO uint32_t RESERVED3[2];	/*!< RESERVED AREA do not any manipulation!!!	Address offset = 0x0048	*/
	__IO uint32_t AHB1LPENR;	/*!< RCC AHB1 per.clock enable in lpm register  Address offset = 0x0050 */
	__IO uint32_t AHB2LPENR;	/*!< RCC AHB2 per.clock enable in lpm register  Address offset = 0x0054 */
	__IO uint32_t AHB3LPENR;	/*!< RCC AHB3 per.clock enable in lpm register  Address offset = 0x0058 */
	__IO uint32_t RESERVED4;	/*!< RESERVED AREA do not any manipulation!!!	Address offset = 0x005C	*/
	__IO uint32_t APB1LPENR;	/*!< RCC APB1 per.clock enable in lpm register  Address offset = 0x0060 */
	__IO uint32_t APB2LPENR;	/*!< RCC APB2 per.clock enabled in lpm  		Address offset = 0x0064 */
	__IO uint32_t RESERVED5[2];	/*!< RESERVED AREA do not any manipulation!!!	Address offset = 0x0068	*/
	__IO uint32_t BDCR;			/*!< RCC Backup domain control register  		Address offset = 0x0070 */
	__IO uint32_t CSR;			/*!< RCC clock control & status register  		Address offset = 0x0074 */
	__IO uint32_t RESERVED6[2];	/*!< RESERVED AREA do not any manipulation!!!	Address offset = 0x0078	*/
	__IO uint32_t SSCGR;		/*!< RCC spread spec.clock generation register	Address offset = 0x0080 */
	__IO uint32_t PLLI2SCFGR;	/*!< RCC PLLI2S configuration register 			Address offset = 0x0084 */


}RCC_TypeDef_t;

/*
 * System configuration Structure Definitions (For more information check reference manual SYSCFG register map)
 *
 */

typedef struct{

	__IO uint32_t MEMRMP;		/*!< SYSCFG memory remap register 				Address offset = 0x0000 */
	__IO uint32_t PMC;			/*!< SYSCFG perip. mode config. register  		Address offset = 0x0004 */
	__IO uint32_t EXTI_CR[4];	/*!< SYSCFG ext. interrupt config. reg.[4:1] 	Address offset for EXTI_CR1 = 0x0008, EXTI_CR2 = 0x000C, EXTI_CR3 = 0x0010C, EXTI_CR4 = 0x0014C */
	__IO uint32_t CMPCR;		/*!< Compensation cell control register 		Address offset = 0x0020 */

}SYSCFG_TypeDef_t;

/*
 *   External interrupt/event controller Structure Definitions (For more information check reference manual SYSCFG register map)
 *
 */

typedef struct{

	__IO uint32_t IMR;			/*!< Interrupt mask register  				Address offset = 0x0000 */
	__IO uint32_t EMR;			/*!< Event mask register  					Address offset = 0x0004 */
	__IO uint32_t RTSR;			/*!< Rising trigger selection register 		Address offset = 0x0008 */
	__IO uint32_t FTSR;			/*!< Falling trigger selection register		Address offset = 0x000C */
	__IO uint32_t SWIER;		/*!< Software interrupt event register  	Address offset = 0x0010 */
	__IO uint32_t PR;			/*!< Pending register						Address offset = 0x0014 */

}EXTI_TypeDef_t;


typedef struct{

	__IO uint32_t CR1;			/*!< SPI control register 1 				Address offset = 0x0000 */
	__IO uint32_t CR2;			/*!< SPI control register 2  				Address offset = 0x0004 */
	__IO uint32_t SR;			/*!< SPI status register   					Address offset = 0x0008 */
	__IO uint32_t DR;			/*!< SPI data register  					Address offset = 0x000C */
	__IO uint32_t CRCPR;		/*!< SPI CRC polynomial register  			Address offset = 0x0010 */
	__IO uint32_t RXCRCR;		/*!< SPI RX CRC register 					Address offset = 0x0014 */
	__IO uint32_t TXCRCR;		/*!< SPI TX CRC register  					Address offset = 0x0018 */
	__IO uint32_t I2SCFGR;		/*!< SPI_I2S configuration register 		Address offset = 0x001C */
	__IO uint32_t I2SPR;		/*!< SPI_I2S prescaler register				Address offset = 0x0020 */


}SPI_TypeDef_t;

/*   Base address definitions for port */

#define GPIOA			((GPIO_TypeDef_t *)(GPIOA_BASE_ADDR)  )
#define GPIOB			((GPIO_TypeDef_t *)(GPIOB_BASE_ADDR)  )
#define GPIOC			((GPIO_TypeDef_t *)(GPIOC_BASE_ADDR)  )
#define GPIOD			((GPIO_TypeDef_t *)(GPIOD_BASE_ADDR)  )
#define GPIOE			((GPIO_TypeDef_t *)(GPIOE_BASE_ADDR)  )
#define GPIOF			((GPIO_TypeDef_t *)(GPIOF_BASE_ADDR)  )
#define GPIOG			((GPIO_TypeDef_t *)(GPIOG_BASE_ADDR)  )
#define GPIOH			((GPIO_TypeDef_t *)(GPIOH_BASE_ADDR)  )
#define GPIOI			((GPIO_TypeDef_t *)(GPIOI_BASE_ADDR)  )

#define RCC				((RCC_TypeDef_t*)(RCC_BASE_ADDR)	  )

#define SYSCFG			((SYSCFG_TypeDef_t*)(SYSCFG_BASE_ADDR))

#define EXTI			((EXTI_TypeDef_t*)(EXTI_BASE_ADDR)	  )


#define SPI1			((SPI_TypeDef_t*)(SPI1_BASE_ADDR)	  )
#define SPI2			((SPI_TypeDef_t*)(SPI2_BASE_ADDR)	  )
#define SPI3			((SPI_TypeDef_t*)(SPI3_BASE_ADDR)	  )
#define SPI4			((SPI_TypeDef_t*)(SPI4_BASE_ADDR)	  )
#define SPI5			((SPI_TypeDef_t*)(SPI5_BASE_ADDR)	  )
#define SPI6			((SPI_TypeDef_t*)(SPI6_BASE_ADDR)	  )



/*
 *
 * Bit Definition's for GPIO ports
 *
 */

#define RCC_AHB1ENR_GPIOAEN_Pos		(0U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIOAEN_Msk		(0x1 << RCC_AHB1ENR_GPIOAEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIOAEN			RCC_AHB1ENR_GPIOAEN_Msk // defined macros for masking

#define RCC_AHB1ENR_GPIOBEN_Pos		(1U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIOBEN_Msk		(0x1 << RCC_AHB1ENR_GPIOBEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIOBEN			RCC_AHB1ENR_GPIOBEN_Msk // defined macros for masking

#define RCC_AHB1ENR_GPIOCEN_Pos		(2U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIOCEN_Msk		(0x1 << RCC_AHB1ENR_GPIOCEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIOCEN			RCC_AHB1ENR_GPIOCEN_Msk // defined macros for masking

#define RCC_AHB1ENR_GPIODEN_Pos		(3U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIODEN_Msk		(0x1 << RCC_AHB1ENR_GPIODEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIODEN			RCC_AHB1ENR_GPIODEN_Msk // defined macros for masking

#define RCC_AHB1ENR_GPIOEEN_Pos		(4U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIOEEN_Msk		(0x1 << RCC_AHB1ENR_GPIOEEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIOEEN			RCC_AHB1ENR_GPIOEEN_Msk // defined macros for masking

#define RCC_AHB1ENR_GPIOFEN_Pos		(5U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIOFEN_Msk		(0x1 << RCC_AHB1ENR_GPIOFEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIOFEN			RCC_AHB1ENR_GPIOFEN_Msk // defined macros for masking

#define RCC_AHB1ENR_GPIOGEN_Pos		(6U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIOGEN_Msk		(0x1 << RCC_AHB1ENR_GPIOGEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIOGEN			RCC_AHB1ENR_GPIOGEN_Msk // defined macros for masking

#define RCC_AHB1ENR_GPIOHEN_Pos		(7U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIOHEN_Msk		(0x1 << RCC_AHB1ENR_GPIOHEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIOHEN			RCC_AHB1ENR_GPIOHEN_Msk // defined macros for masking

#define RCC_AHB1ENR_GPIOIEN_Pos		(8U) // GPIO's bit position(address on RCC_AHB1ENR)
#define RCC_AHB1ENR_GPIOIEN_Msk		(0x1 << RCC_AHB1ENR_GPIOIEN_Pos) // Bit manipulation masking for related position
#define RCC_AHB1ENR_GPIOIEN			RCC_AHB1ENR_GPIOIEN_Msk // defined macros for masking

#define RCC_APB2ENR_SYSCFGEN_Pos	(14U)// SYSCFG's bit position(address on RCC_APB2ENR)
#define RCC_APB2ENR_SYSCFGEN_Msk	(0x1 << RCC_APB2ENR_SYSCFGEN_Pos)// Bit manipulation masking for related position
#define RCC_APB2ENR_SYSCFGEN		RCC_APB2ENR_SYSCFGEN_Msk //defined macros for masking

#define RCC_APB2ENR_SPI1EN_Pos		(12U)// SPI1's bit position(address on RCC_APB2ENR)
#define RCC_APB2ENR_SPI1EN_Msk		(0x1 << RCC_APB2ENR_SPI1EN_Pos)// Bit manipulation masking for related position
#define RCC_APB2ENR_SPI1EN			RCC_APB2ENR_SPI1EN_Msk //defined macros for masking

#define RCC_APB1ENR_SPI2EN_Pos		(14U)// SPI2's bit position(address on RCC_APB1ENR)
#define RCC_APB1ENR_SPI2EN_Msk		(0x1 << RCC_APB1ENR_SPI2EN_Pos)// Bit manipulation masking for related position
#define RCC_APB1ENR_SPI2EN			RCC_APB1ENR_SPI2EN_Msk //defined macros for masking

#define RCC_APB1ENR_SPI3EN_Pos		(15U)// SPI3's bit position(address on RCC_APB1ENR)
#define RCC_APB1ENR_SPI3EN_Msk		(0x1 << RCC_APB1ENR_SPI3EN_Pos)// Bit manipulation masking for related position
#define RCC_APB1ENR_SPI3EN			RCC_APB1ENR_SPI3EN_Msk //defined macros for masking

#define RCC_APB2ENR_SPI4EN_Pos		(13U)// SPI4's bit position(address on RCC_APB1ENR)
#define RCC_APB2ENR_SPI4EN_Msk		(0x1 << RCC_APB2ENR_SPI4EN_Pos)// Bit manipulation masking for related position
#define RCC_APB2ENR_SPI4EN			RCC_APB2ENR_SPI4EN_Msk //defined macros for masking

#define RCC_APB2ENR_SPI5EN_Pos		(20U)// SPI5's bit position(address on RCC_APB1ENR)
#define RCC_APB2ENR_SPI5EN_Msk		(0x1 << RCC_APB2ENR_SPI5EN_Pos)// Bit manipulation masking for related position
#define RCC_APB2ENR_SPI5EN			RCC_APB2ENR_SPI5EN_Msk //defined macros for masking

#define RCC_APB2ENR_SPI6EN_Pos		(21U)// SPI6's bit position(address on RCC_APB1ENR)
#define RCC_APB2ENR_SPI6EN_Msk		(0x1 << RCC_APB2ENR_SPI6EN_Pos)// Bit manipulation masking for related position
#define RCC_APB2ENR_SPI6EN			RCC_APB2ENR_SPI6EN_Msk //defined macros for masking

#define SPI_TxE						(1U)// SPI_TxE bit
#define SPI_Busy					(7U)// SPI_Busy bit
#define SPI_RxNE					(0U)// SPI_RxNE bit

#define SPI_CR1_SPE					(6U)// SPI_CR1_SPE bit

#define SPI_CR2_TXEIE				(7U)// SPI_CR2_TXEIE bit

/*
 * Flag Definitions
 *
 *
 */

#define SPI_RxNE_Flag				(0x1U << SPI_RxNE)
#define SPI_TxE_FLAG 				(0x1U << SPI_TxE)
#define SPI_Busy_FLAG 				(0x1U << SPI_Busy)


#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"


#endif /* INC_STM32F407XX_H_ */
