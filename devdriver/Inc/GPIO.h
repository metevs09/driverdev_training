/*
 * GPIO.h
 *
 *  Created on: May 14, 2024
 *      Author: Metehan
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f407xx.h"


typedef struct{

    uint32_t pinNumber; // Related pin to configuration
    uint32_t MODE;		// Pin Mode Select
    uint32_t OTYPE;		// Output Type configuration (push-pull or  open-drain)
    uint32_t Speed;		// Speed configuration ( Low, Medium,  High, Very high)
    uint32_t PUPD;		// Pull-up or Pull-down configuration
    uint32_t AF;		// Alternate function configuration



}GPIO_InitTypeDef_t;





#endif /* INC_GPIO_H_ */
