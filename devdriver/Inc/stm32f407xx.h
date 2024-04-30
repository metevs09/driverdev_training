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

#define FLASH_BASE_ADDR  (0x08000000UL) /* Defined FLASH base address(up to 1 MB)  */

#define SRAM1_BASE_ADDR  (0x20000000UL) /* Defined SRAM1 base address(up to 112 KB)*/
#define SRAM2_BASE_ADDR  (0x2001C000UL) /* Defined SRAM2 base address(up to 16 KB) */

/*
 * Peripheral Base Addresses (Address starting hex number on reference manual)
 *
 */

#define PERIP_BASE_ADDR (0x40000000UL)                 /* Defined peripheral base address for all peripheral */

#define APB1_BASE_ADDR  PERIP_BASE_ADDR                /*APB1 bus domain base address*/
#define APB2_BASE_ADDR (PERIP_BASE_ADDR + 0x10000UL)   /*APB2 bus domain base address*/
#define AHB1_BASE_ADDR (PERIP_BASE_ADDR + 0x20000UL)   /*AHB1 bus domain base address*/
#define AHB2_BASE_ADDR (PERIP_BASE_ADDR + 0x10000000UL)/*AHB2 bus domain base address*/

#endif /* INC_STM32F407XX_H_ */
