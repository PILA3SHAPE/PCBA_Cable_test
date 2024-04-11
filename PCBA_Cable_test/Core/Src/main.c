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

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

static uint8_t init[9] = {0x80, 0x28, 0x80, 0x0C, 0x80, 0x01, 0x02}; // init
static uint8_t pin[6] = {0x80, 0x06, 0x62, 0x50, 0x49, 0x4E}; //pin

  uint8_t lineone[2] = {0x80, 0x06};
  uint8_t linetwo[2] = {0x80, 0xC0};
  uint8_t S_1[2] = {0x40, 0x31};
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
  static int count;






/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
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
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */


  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &init, 7, 100);

  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &pin, 6, 100);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	    //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	    //HAL_Delay(200);

	  	  switch (count)
	  	  {



	  	  	  case 0:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_RESET); //address 0
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_RESET);
						  HAL_Delay(100);
						  count++;

						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET || HAL_GPIO_ReadPin(GPIOA, Input2_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
							  {
								  //HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
								  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_1, 2, 100);  // pin 1
							  }

							  if (HAL_GPIO_ReadPin(GPIOA, Input2_Pin)==GPIO_PIN_SET)
							  {
								  //HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
								  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_17, 3, 100);  // pin 1
							  }
						  }

						  //HAL_Delay(100);
						  break;
					  }

	  	  	  case 1:
	  				  {
	  					  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_SET); //address 1
	  					  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_RESET);
	  					  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_RESET);
	  					  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_RESET);
	  					  count++;
	  					  HAL_Delay(100);
	  					  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
	  					  {
	  						  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
	  						  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_2, 2, 100);  // pin 2
	  					  }

	  					  break;
	  				  }

	  	  	  case 2:
	  	  		  	  {
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_RESET); //address 2
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_SET);
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_RESET);
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_RESET);
	  	  		  		  count++;
	  	  		  		  HAL_Delay(100);
	  	  		  		  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
	  	  		  		  {
	  	  		  			  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
	  	  		  		  	  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_3, 2, 100);  // pin 3
	  	  		  		  }

	  	  		  		  break;
	  	  		  	  }
	  	  	  case 3:
	  	  		  	  {
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_SET); //address 2
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_SET);
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_RESET);
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_RESET);
	  	  		  		  count++;
	  	  		  		  HAL_Delay(100);
	  	  		  		  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
	  	  		  		  {
	  	  		  			  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
	  	  		  		  	  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_4, 2, 100);  // pin 4
	  	  		  		  }

	  	  		  		  break;
	  	  		  	  }

	  	  	  case 4:
	  	  		  	  {
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_RESET); //address 2
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_RESET);
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_SET);
	  	  		  		  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_RESET);
	  	  		  		  count++;
	  	  		  		  HAL_Delay(100);
	  	  		  		  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
	  	  		  		  {
	  	  		  			  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
	  	  		  		  	  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_5, 2, 100);  // pin 5
	  	  		  		  }

	  	  		  		  break;
	  	  		  	  }
	  	  	  case 5:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_SET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_RESET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_6, 2, 100);  // pin 6
						  }

						  break;
					  }


	  	  	  case 6:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_RESET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_RESET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_7, 2, 100);  // pin 7
						  }

						  break;
					  }


	  	  	  case 7:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_SET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_RESET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_8, 2, 100);  // pin 8
						  }

						  break;
					  }
	  	  	  case 8:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_RESET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_SET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_9, 2, 100);  // pin 9
						  }

						  break;
					  }


	  	  	  case 9:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_SET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_SET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_10, 3, 100);  // pin 10
						  }

						  break;
					  }

	  	  	  case 10:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_RESET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_SET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_11, 3, 100);  // pin 11
						  }

						  break;
					  }

	  	  	  case 11:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_SET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_SET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_12, 3, 100);  // pin 12
						  }

						  break;
					  }
	  	  	  case 12:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_RESET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_SET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_13, 3, 100);  // pin 13
						  }

						  break;
					  }

	  	  	  case 13:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_SET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_SET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
						  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_14, 3, 100);  // pin 14
						  }

						  break;
					  }

	  	  	  case 14:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_RESET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_SET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_15, 3, 100);  // pin 15
						  }

						  break;
					  }

	  	  	  case 15:
					  {
						  HAL_GPIO_WritePin(GPIOC, ADDR0_Pin, GPIO_PIN_SET); //address 2
						  HAL_GPIO_WritePin(GPIOC, ADDR1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(GPIOC, ADDR3_Pin, GPIO_PIN_SET);
						  count++;
						  HAL_Delay(100);
						  if (HAL_GPIO_ReadPin(GPIOA, Input1_Pin)==GPIO_PIN_SET)
						  {
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100); // zmień linię na 2
							  HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &S_16, 3, 100);  // pin 16
						  }

						  break;
					  }

	  	  	  default:
					  {
						 HAL_Delay(1000);
						 HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &linetwo, 2, 100);
						 HAL_I2C_Master_Transmit(&hi2c1, 0x7C, &space, 3, 100);
						 //HAL_Delay(10);
						 HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
						 count = 0;

					  }



	  	  }



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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
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

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
