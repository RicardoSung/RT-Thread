/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

#define LED1_ON   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET)
#define LED1_OFF  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET)


///** 控制LED灯亮灭的宏，
//	* LED低电平亮，设置ON=0，OFF=1
//	* 若LED高电平亮，把宏设置成ON=1 ，OFF=0 即可
//	*/
#define ON  GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

/* 带参宏，可以像内联函数一样使用 */

#define LED2(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,a)

#define LED2_GPIO_PORT   GPIOD
#define LED2_PIN     GPIO_PIN_2

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
