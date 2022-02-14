/*
 * common.c
 *
 *  Created on: Feb 15, 2022
 *      Author: pudja
 */
#include "./common.h"

/**
 * @brief Get related IRQ number based on GPIO pin
 * @param pin The GPIO pin
 * @return The IRQ number
 */
IRQn_Type CMN_PinGetIrqNumber(uint16_t pin)
{
  IRQn_Type IRQn;

  /* Select appropriate EXTI pin IRQ number */
  if (pin >= GPIO_PIN_10)
    IRQn = EXTI15_10_IRQn;
  else if (pin >= GPIO_PIN_5)
    IRQn = EXTI9_5_IRQn;
  else if (pin == GPIO_PIN_4)
    IRQn = EXTI4_IRQn;
  else if (pin == GPIO_PIN_3)
    IRQn = EXTI3_IRQn;
  else if (pin == GPIO_PIN_2)
    IRQn = EXTI2_IRQn;
  else if (pin == GPIO_PIN_1)
    IRQn = EXTI1_IRQn;
  else if (pin == GPIO_PIN_0)
    IRQn = EXTI0_IRQn;

  return (IRQn);
}

/**
 * @brief Enable GPIO clock
 * @param port Port to be enabled
 */
void CMN_PortEnableClock(GPIO_TypeDef *port)
{
  assert_param(IS_GPIO_ALL_INSTANCE(port));

  /* Enable appropriate GPIO clock */
  if (port == GPIOH)
    __HAL_RCC_GPIOH_CLK_ENABLE();
  else if (port == GPIOG)
    __HAL_RCC_GPIOG_CLK_ENABLE();
  else if (port == GPIOF)
    __HAL_RCC_GPIOF_CLK_ENABLE();
  else if (port == GPIOE)
    __HAL_RCC_GPIOE_CLK_ENABLE();
  else if (port == GPIOD)
    __HAL_RCC_GPIOD_CLK_ENABLE();
  else if (port == GPIOC)
    __HAL_RCC_GPIOC_CLK_ENABLE();
  else if (port == GPIOB)
    __HAL_RCC_GPIOB_CLK_ENABLE();
  else if (port == GPIOA)
    __HAL_RCC_GPIOA_CLK_ENABLE();
}

/**
 * @brief Dsiable GPIO clock
 * @param port Port to be disabled
 */
void CMN_PortDisableClock(GPIO_TypeDef *port)
{
  assert_param(IS_GPIO_ALL_INSTANCE(port));

  /* Disable appropriate GPIO clock */
  if (port == GPIOH)
    __HAL_RCC_GPIOH_CLK_DISABLE();
  else if (port == GPIOG)
    __HAL_RCC_GPIOG_CLK_DISABLE();
  else if (port == GPIOF)
    __HAL_RCC_GPIOF_CLK_DISABLE();
  else if (port == GPIOE)
    __HAL_RCC_GPIOE_CLK_DISABLE();
  else if (port == GPIOD)
    __HAL_RCC_GPIOD_CLK_DISABLE();
  else if (port == GPIOC)
    __HAL_RCC_GPIOC_CLK_DISABLE();
  else if (port == GPIOB)
    __HAL_RCC_GPIOB_CLK_DISABLE();
  else if (port == GPIOA)
    __HAL_RCC_GPIOA_CLK_DISABLE();
}

