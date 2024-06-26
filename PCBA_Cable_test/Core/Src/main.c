/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */

static uint8_t init[9] = {0x80, 0x28, 0x80, 0x0C, 0x80, 0x01, 0x02}; // init
static uint8_t pin[6] = {0x80, 0x06, 0x62, 0x50, 0x49, 0x4E}; //pin

  uint8_t lineone[2] = {0x80, 0x06};
  uint8_t linetwo_0[2] = {0x80, 0xC0};
  uint8_t linetwo_3[2] = {0x80, 0xC3};
  //uint8_t S_1[2] = {0x40, 0x31};
  uint8_t S_1[3] = {0x40, 0x31, 0x20};
  //uint8_t S_1[2] = {64, 49};
  uint8_t S_2[2] = {0x40, 0x32};
  uint8_t S_3[2] = {0x40, 0x33};
  uint8_t S_4[2] = {0x40, 0x34};
  uint8_t S_5[2] = {0x40, 0x35};
  uint8_t S_6[2] = {0x40, 0x36};
  uint8_t S_7[2] = {0x40, 0x37};
  uint8_t S_8[2] = {0x40, 0x38};
  uint8_t S_9[2] = {0x40, 0x39};
  uint8_t S_10[3] = {0x40, 0x31, 0x30};
  uint8_t S_11[3] = {0x40, 0x31, 0x31};
  uint8_t S_12[3] = {0x40, 0x31, 0x32};
  uint8_t S_13[3] = {0x40, 0x31, 0x33};
  uint8_t S_14[3] = {0x40, 0x31, 0x34};
  uint8_t S_15[3] = {0x40, 0x31, 0x35};
  uint8_t S_16[3] = {0x40, 0x31, 0x36};
  uint8_t S_17[3] = {0x40, 0x31, 0x37};
  uint8_t S_18[3] = {0x40, 0x31, 0x38};
  uint8_t S_19[3] = {0x40, 0x31, 0x39};


  uint8_t space [3] = {0x40, 0x20, 0x20};


  int binary_array[4];
  int temp=0;
  int n;
  const int size = 4;
  int send_ready=0;

  //const int size = 4;
  // Define a structure to hold binary values


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

struct STR{
   unsigned int A : 1;
   unsigned int B : 1;
   unsigned int C : 1;
   unsigned int D : 1;
   unsigned int rest : 4;
};

union u_STR_S {
    struct STR member1;
    unsigned int member2;
};

union u_STR_S u_STR;
struct STR STR_test;
unsigned int a = 2;



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

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
  MX_I2C1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_Base_Start_IT(&htim3);

  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &init, 7, 100);

  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &pin, 6, 100);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


		if(send_ready == 1)
		{
			HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo_0, 2, 100); // zmień linię na 2
			HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_1, 3, 100);  // pin 1
			HAL_Delay(1000);
			send_ready = 0;

		}else if (temp == 0)
		{

			HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo_0, 2, 100);
			HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &space, 3, 100);
			HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo_3, 2, 100);
			HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &space, 3, 100);
		}


	  /*

    for (int count = 0; count <= 15; count++) {
//adresowanie multiplekserów od 0 to 15

        //int temp = count; // temp staje się globalny

    	temp = count;
        int n;
				//for (int i = size - 1; i >= 0; i--)
				for (int i = 0; i < size; i++)
				{

					n = power (2, i);
					binary_array[i] = temp % 2;
					if (binary_array[i] == 1)
						{
							HAL_GPIO_WritePin(GPIOC, n, GPIO_PIN_SET);
							HAL_Delay(20);
						}
					else if(binary_array[i] == 0)
						{
							HAL_GPIO_WritePin(GPIOC, n, GPIO_PIN_RESET);
							HAL_Delay(20);
						}

					temp /= 2;
//					HAL_Delay(50);

				}

/*				if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)

					{
						if (count <=9)
						{
							S_1[1] = 48 + count;
							S_1[2] = 32;
						}
							else
						{
							S_1[1] = 49;
							S_1[2] = 48 + count-10;
						}
						HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo_0, 2, 100); // zmień linię na 2
						HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_1, 3, 100);  // pin 1
//						HAL_Delay(150);
					}

				if (HAL_GPIO_ReadPin(GPIOA, Input2_Pin)==GPIO_PIN_SET)
					{
					  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo_3, 2, 100); // zmień linię na 2
					  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_17, 3, 100);  // pin 1
					}



    }
*/

  }
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x200009FE;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 47;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 49999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin|ADDR1_Pin|ADDR2_Pin|ADDR3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ADDR0_Pin ADDR1_Pin ADDR2_Pin ADDR3_Pin */
  GPIO_InitStruct.Pin = ADDR0_Pin|ADDR1_Pin|ADDR2_Pin|ADDR3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Input1_Pin Input2_Pin */
  GPIO_InitStruct.Pin = Input1_Pin|Input2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Input3_Pin Input4_Pin */
  GPIO_InitStruct.Pin = Input3_Pin|Input4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == GPIO_PIN_13) {

	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

	  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo_3, 2, 100); // zmień linię na 2
	  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_17, 3, 100);  // pin 1
  }
/*
  else if (GPIO_Pin == Input3_Pin) {

//	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);



  }
  else if (GPIO_Pin == Input4_Pin) {

//	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

  }
*/
  else {

      __NOP();
  }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{

	if(temp <= 15)
	{
		  u_STR.member2=temp;

		  binary_array[0] = u_STR.member1.A;
		  binary_array[1] = u_STR.member1.B;
		  binary_array[2] = u_STR.member1.C;
		  binary_array[3] = u_STR.member1.D;

		  for (int i = 0; i < size; i++)
		  {
			n = pow(2, i);
			if (binary_array[i] == 1)
			{
				HAL_GPIO_WritePin(GPIOC, n, GPIO_PIN_SET);
			}
			else
			{
				HAL_GPIO_WritePin(GPIOC, n, GPIO_PIN_RESET);
			}
		  }
		  if (HAL_GPIO_ReadPin(GPIOC, Input3_Pin)==GPIO_PIN_SET)
		  {
				HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
				if (temp <=9)
				{
					S_1[1] = 48 + temp;
					S_1[2] = 32;
				}
					else
				{
					S_1[1] = 49;
					S_1[2] = 48 + temp-10;
				}
				send_ready = 1;

		  }

		  temp++;

	}	else
	{

		temp = 0;
	}

//	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	/*
	HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo_0, 2, 100);
	HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &space, 3, 100);
	HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo_3, 2, 100);
	HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &space, 3, 100);
*/
}


/*
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc) {
  RTC_AlarmTypeDef sAlarm;
  HAL_RTC_GetAlarm(hrtc,&sAlarm,RTC_ALARM_A,FORMAT_BIN);
  if(sAlarm.AlarmTime.Seconds>58) {
    sAlarm.AlarmTime.Seconds=0;
  }else{
    sAlarm.AlarmTime.Seconds=sAlarm.AlarmTime.Seconds+1;
  }
    while(HAL_RTC_SetAlarm_IT(hrtc, &sAlarm, FORMAT_BIN)!=HAL_OK){}
  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  //HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}*/
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
