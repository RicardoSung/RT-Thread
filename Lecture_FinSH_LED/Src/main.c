/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <rtthread.h>
static struct rt_thread led1_thread;  
static struct rt_thread led2_thread;       //定义线程控制块
ALIGN(RT_ALIGN_SIZE)
static rt_uint8_t led1_thread_stack[256];
static rt_uint8_t led2_thread_stack[256];  //定义线程栈
void led1_thread_entry(void *parameter);
void led2_thread_entry(void *parameter);
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

rt_uint8_t  flag1;
rt_uint8_t  flag2;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//	char ch;
//	rt_uint8_t count;

//    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);  

//    for(count = 0 ; count < 10 ;count++)
//    {       
//        rt_pin_write(LED_PIN, PIN_HIGH);
//        rt_kprintf("led on, count : %d\r\n", count);
//        rt_thread_mdelay(500);

//        rt_pin_write(LED_PIN, PIN_LOW);
//        rt_kprintf("led off\r\n");
//        rt_thread_mdelay(500);
//    }
//    return 0;
//}
//MSH_CMD_EXPORT(led, RT-Thread first led sample);

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  
//    rt_err_t led1;
   rt_thread_init(&led1_thread,
				  "led1",
				  led1_thread_entry,
				  RT_NULL,
				  &led1_thread_stack[0],
				  sizeof(led1_thread_stack),
				  3,
				  20);
						  
//  if(led1 == RT_EOK)
//  {
	  rt_thread_startup(&led1_thread);
//  }
				  
	rt_thread_init(&led2_thread,
				  "led2",
				  led2_thread_entry,
				  RT_NULL,
				  &led2_thread_stack[0],
				  sizeof(led2_thread_stack),
				  4,
				  100);
		rt_thread_startup(&led2_thread);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  while (1)
//  {
//    /* USER CODE END WHILE */
//	  rt_kprintf("hello world");
////	  HAL_Delay(100);
////	  ch = getchar();
//    /* USER CODE BEGIN 3 */
//  } 

  /* USER CODE END 3 */
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

//INIT_BOARD_EXPORT(MX_USART1_UART_Init);

/* USER CODE BEGIN 4 */

static void led1_thread_entry(void *parameter)
{
	while(1)
	{
		LED1_ON;
		flag1 = 1;
		rt_kprintf("led1 on\n");
//		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
		rt_thread_mdelay(1000);
		LED1_OFF;
		flag1 = 0;
		rt_kprintf("led1 off\n");
//		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
		rt_thread_mdelay(1000);
	}
}

static void led2_thread_entry(void *parameter)
{
	while(1)
	{
		LED2(ON);
		flag2 = 1;
		rt_kprintf("led2 on\n");
		rt_thread_mdelay(500);
		LED2(OFF);
		flag2 = 0;
		rt_kprintf("led2 off\n");
		rt_thread_mdelay(500);
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
