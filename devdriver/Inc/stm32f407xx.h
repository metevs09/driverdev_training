/*
 * stm32f407xx.h
 *
 *  Created on: Apr 27, 2024
 *      Author: Metehan
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

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

#define GPIOJ_BASE_ADDR			(AHB1_BASE_ADDR + 0x00002400UL)			/* Defined GPIOJ base address */
#define GPIOK_BASE_ADDR			(AHB1_BASE_ADDR + 0x00002800UL)			/* Defined GPIOK base address */

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

#endif /* INC_STM32F407XX_H_ */
