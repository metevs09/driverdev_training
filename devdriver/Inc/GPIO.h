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

    uint32_t pinNumber;
    uint32_t MODE;
    uint32_t OTYPE;
    uint32_t Speed;
    uint32_t PUPD;
    uint32_t AF;



}GPIO_InitTypeDef_t;





#endif /* INC_GPIO_H_ */
