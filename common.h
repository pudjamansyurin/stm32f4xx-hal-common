/*
 * common.h
 *
 *  Created on: Feb 15, 2022
 *      Author: pudja
 */

#ifndef STM32F4XX_HAL_COMMON_COMMON_H_
#define STM32F4XX_HAL_COMMON_COMMON_H_

#include "stm32f4xx_hal.h"

/* Public function declarations */
IRQn_Type CMN_PinGetIrqNumber(uint16_t pin);
void CMN_PortEnableClock(GPIO_TypeDef *port);
void CMN_PortDisableClock(GPIO_TypeDef *port);

#endif /* STM32F4XX_HAL_COMMON_COMMON_H_ */
