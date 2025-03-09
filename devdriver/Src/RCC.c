/*
 * RCC.c
 *
 *  Created on: May 11, 2024
 *      Author: Metehan
 */

#ifndef INC_RCC_C_
#define INC_RCC_C_

#include"RCC.h"

const int8_t AHB_Prescaler[15]= { 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const int8_t APB_Prescaler[7]= { 0, 0, 0, 1, 2, 3, 4};

/*
 * @brief RCC_GetSystemClock, Read System Clock Mhz
 * @param void
 *
 * @retval SystemCoreClock
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




/*
 * @brief RCC_GetHClock, Calculate AHB Peripheral Clock prescaler
 * @param void
 *
 * @retval AHB_PeripClock
 *
 */

uint32_t RCC_GetHClock(void){

	uint32_t AHB_PeripClock = 0;
	uint32_t SystemCoreClock = 0;
	uint8_t HPRE_Value = 0;

	SystemCoreClock = RCC_GetSystemClock();

	HPRE_Value = ((RCC->CFGR >> 4U) & (0xFU));

	AHB_PeripClock = (SystemCoreClock >> AHB_Prescaler[HPRE_Value]);


	return AHB_PeripClock;

}



/*
 * @brief RCC_GetAPB1Clock, Calculate AHB1 Peripheral Clock prescaler
 * @param void
 *
 * @retval APB1_PeripClock
 *
 */

uint32_t RCC_GetAPB1Clock(void){

	uint32_t APB1_PeripClock = 0;
	uint32_t AHB_PeripClock = 0;
	uint8_t PPRE1 = 0;

	AHB_PeripClock = RCC_GetHClock();

	PPRE1 = ((RCC->CFGR >> 10U) & (0xFU));

	APB1_PeripClock = (AHB_PeripClock >> APB_Prescaler[PPRE1]);

	return APB1_PeripClock;
}


#endif /* INC_RCC_C_ */
