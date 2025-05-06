/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

#include "Utility.h"

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */


void Semaforo();
void InverterLedReg();
void Despertador(GPIO_TypeDef* porta, uint16_t pino);
void AtivarModoPWM(GPIO_TypeDef* porta, uint16_t pino, int velocidade);
void LedEBotao();
void LedEBotaoDec();
void AlternarLedBotao();
void LedBotaoContador();
void ContagemBinaria(int contador);

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

  // HAL_SYSTICK_Config(SystemCoreClock / 5);
  // HAL_SYSTICK_Config(SystemCoreClock / 5);

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

	Utility_Init();

//	GPIO_Clock_Enable(GPIOE);
	GPIO_Clock_Enable(GPIOE);

//	// Botões
//	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
//	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
//
//	GPIO_Pin_Mode(GPIOA, PIN_0, INPUT);
//	GPIO_Resistor_Enable(GPIOA, PIN_0, PULL_DOWN);

	// Leds
	GPIO_Pin_Mode(GPIOE, PIN_0, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_2, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_3, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_4, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_5, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_7, OUTPUT);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


	while (1) {


//		// Questão 1
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, LOW);
//		Delay_ms(100);
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, HIGH);
//		Delay_ms(100);

////		// Questão 2
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, LOW);
//		Delay_ms(100);
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, HIGH);
//		Delay_ms(1900);

		// Questão 3
//		Delay_ms(1000);
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, HIGH);
//		Delay_ms(250);
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, LOW);
//		Delay_ms(1000);

		// Questão 4
//		for(int i = 0; i < 2000; i += 10) {
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
//			Delay_us(i);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
//			Delay_us(1999 - i);
//		}
//
//		for(int i = 0; i < 2000; i += 10) {
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
//			Delay_us(1999 - i);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
//			Delay_us(i);
//		}

//		// Questão 5
//		for(int i = 0; i < 255; i++) {
//			GPIO_Write_Port(GPIOE, i);
//			Delay_ms(400);
//		}

//		// Questão 6
//		for(int i = 0; i < 8; i++) {
//			GPIOE->ODR = 0;
//			GPIOE->ODR |= 1 << i;
//			Delay_ms(100);
//		}
//		for(int i = 7; i >= 0; i--) {
//			GPIOE->ODR = 0;
//			GPIOE->ODR |= 1 << i;
//			Delay_ms(100);
//		}

		// Questão 7
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
		Delay_ms(5000);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
		Delay_ms(2000);

		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
		Delay_ms(5000);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
		Delay_ms(2000);



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */


void Semaforo() {
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	  HAL_Delay(4000);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
	  HAL_Delay(2000);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);

	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
	  HAL_Delay(4000);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
}

void InverterLedReg() {
	GPIOA->ODR ^= 0b11 << 6;
}

void Despertador(GPIO_TypeDef* porta, uint16_t pino) {
	 HAL_Delay(1000);
	 for(int i = 0; i < 4; i++){
		 HAL_GPIO_WritePin(porta, pino, GPIO_PIN_SET);
	 	 HAL_Delay(100);
	 	 HAL_GPIO_WritePin(porta, pino, GPIO_PIN_RESET);
	 	 HAL_Delay(100);
	 }
}

void AtivarModoPWM(GPIO_TypeDef* porta, uint16_t pino, int velocidade) {
	for(int i = 0; i < 2000; i += velocidade) {
		HAL_GPIO_WritePin(porta, pino, GPIO_PIN_RESET);
		Delay_us(i);
		HAL_GPIO_WritePin(porta, pino, GPIO_PIN_SET);
		Delay_us(1999 - i);
	}

	for(int i = 0; i < 2000; i += velocidade) {
		HAL_GPIO_WritePin(porta, pino, GPIO_PIN_RESET);
		Delay_us(1999 - i);
		HAL_GPIO_WritePin(porta, pino, GPIO_PIN_SET);
		Delay_us(i);
	}
}

void LedEBotao() {
	// Deve ativar os pinos PE3 (botão) e PA6 (led)
	if(!GPIO_Read_Pin(GPIOE, PIN_3)) {
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
	} else {
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	}

	// Deve ativar os pinos PE4 (botão) e PA7 (led)
	if(!GPIO_Read_Pin(GPIOE, PIN_4)) {
		GPIO_Write_Pin(GPIOA, PIN_7, LOW);
	} else {
		GPIO_Write_Pin(GPIOA, PIN_7, HIGH);
	}
}

void LedEBotaoDec(){
	int contador = 150;
	while(!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3)) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
		HAL_Delay(contador);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
		HAL_Delay(contador);

		if(contador > 0)
			contador--;
	}

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
}

void AlternarLedBotao() {
	GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	GPIO_Write_Pin(GPIOA, PIN_7, HIGH);

	while(!GPIO_Read_Pin(GPIOE, PIN_3)) {
		GPIO_Toggle_Pin(GPIOA, PIN_6);
		HAL_Delay(100);
		GPIO_Toggle_Pin(GPIOA, PIN_7);
	}
}

void LedBotaoContador() {
	// Precisa ativar os pinos PA6 e PE4
	GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	int contador = 0;

	while(!GPIO_Read_Pin(GPIOE, PIN_4)) {
		Delay_ms(1);
		contador += 1;
	}

	if(contador > 0){
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		Delay_ms(contador);
		contador = 0;

		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	}
}
void ContagemBinaria(int contador) {
	if(contador == 0) {
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_7, HIGH);
	} else if (contador == 1) {
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_7, LOW);
	} else if (contador == 2) {
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		GPIO_Write_Pin(GPIOA, PIN_7, HIGH);
	} else {
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		GPIO_Write_Pin(GPIOA, PIN_7, LOW);
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
