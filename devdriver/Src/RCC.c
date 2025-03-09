/*
 * RCC.c
 *
 *  Created on: May 11, 2024
 *      Author: Metehan
 */

#ifndef INC_RCC_C_
#define INC_RCC_C_

#include"RCC.h"




/*
 * @brief RCC_GetSystemClock, Configures the SPI peripheral
 *
 *
 * @retval Void
 *
 */


uint32_t RCC_GetSystemClock(void){

	uint32_t SystemCoreClock = 0;
	uint8_t ClockSource = 0;

	ClockSource = ((RCC->CFGR >> 2U) & 0x3U);

	switch(ClockSource){

			case 0: SystemCoreClock =16000000; break;
			case 1: SystemCoreClock =8000000; break;

			default: SystemCoreClock = 16000000;


	}

	return SystemCoreClock;


}





uint32_t RCC_GetHClock(void){

	uint32_t AHB_PeripClock = 0;
	uint32_t SystemCoreClock = 0;

	SystemCoreClock = RCC_GetSystemClock();


	return AHB_PeripClock;

}


#endif /* INC_RCC_C_ */
