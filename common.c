/*
 * common.c
 *
 *  Created on: Feb 15, 2022
 *      Author: pudja
 */
#include "./common.h"

/**
 * @brief Get GPIO pin number index
 * @param GPIO_Pin The GPIO pin
 * @return The GPIO pin number
 */
uint8_t CMN_PinGetNumber(uint16_t GPIO_Pin)
{
  uint8_t i;

  for (i = 0; i < GPIO_PIN_CNT; i++)
    if (GPIO_Pin >> i == 1)
      return i;

  return 0;
}

/**
 * @brief Get related IRQ number based on GPIO pin
 * @param pin_num The GPIO pin number
 * @return The IRQ number
 */
IRQn_Type CMN_PinGetIrqNumber(uint8_t pin_num)
{
  IRQn_Type IRQn;

  /* Select appropriate EXTI pin IRQ number */
  if (pin_num >= 10)
    IRQn = EXTI15_10_IRQn;
  else if (pin_num >= 5)
    IRQn = EXTI9_5_IRQn;
  else if (pin_num == 4)
    IRQn = EXTI4_IRQn;
  else if (pin_num == 3)
    IRQn = EXTI3_IRQn;
  else if (pin_num == 2)
    IRQn = EXTI2_IRQn;
  else if (pin_num == 1)
    IRQn = EXTI1_IRQn;
  else if (pin_num == 0)
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
