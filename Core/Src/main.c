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
#include "LCD_Blio.h"
#include <stdio.h>
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


void SinalSenoidal();
void WatchDogAnalogico();
void SensorDeTemperatura();

void Semaforo();
void InverterLedReg();
void Despertador(GPIO_TypeDef* porta, uint16_t pino);
void AtivarModoPWM(GPIO_TypeDef* porta, uint16_t pino, int velocidade);
void LedEBotao();
void LedEBotaoDec();
void AlternarLedBotao();
void LedBotaoContador();
void ContagemBinaria(int contador);

void DisplaySeteSegHexa();
void DisplaySeteSegHexa2D();
void Genius();
void SensorUltrassonico();
void MotorDC();
void MicroServomotor();

int contador = 0;


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
  USART1_Init();

//  GPIO_Clock_Enable(GPIOA);

//	GPIO_Pin_Mode(GPIOA, PIN_4, ANALOG);
//	GPIO_Pin_Mode(GPIOA, PIN_5, ANALOG);
//
//	ADC_Init(ADC1, SINGLE_CHANNEL, DAC_RES_12BITS);
//	ADC_SingleChannel(ADC1, ADC_IN0);
//
//	DAC_Init(DAC_CHANNEL1);
//	DAC_Init(DAC_CHANNEL2);

//	DAC_Init1(DAC_CHANNEL2);

//	GPIO_Clock_Enable(GPIOE);
//
//	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
//	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT);
//
//	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
//	GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);
//
//	EXTI_Config(EXTI3, GPIOE, FALLING_EDGE);
//	EXTI_Config(EXTI4, GPIOE, FALLING_EDGE);
//
//	NVIC_EnableIRQ(EXTI3_IRQn);
//	NVIC_EnableIRQ(EXTI4_IRQn);
//
//	NVIC_SetPriority(EXTI3_IRQn, 0);
//	NVIC_SetPriority(EXTI4_IRQn, 1);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


	while (1) {
		//SinalSenoidal();
		//WatchDogAnalogico();

		SensorDeTemperatura();


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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE3 PE4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

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


// INTERRUPÇÕES
void EXTI3_IRQHandler() {
	printf("Interrupção em K1\n");
	Delay_ms(2000);
	printf("Saindo de K1\n");
	EXTI_Clear_Pending(EXTI3);
}
void EXTI4_IRQHandler() {
	printf("Interrupção em K0\n");
	Delay_ms(2000);
	printf("Saindo de K0\n");
	EXTI_Clear_Pending(EXTI4);
}


// QUESTÕES DA ÚLTIMA UNIDADE
void SinalSenoidal() {
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);

	GPIO_Pin_Mode(GPIOA, PIN_5, ANALOG);
	DAC_Init1(DAC_CHANNEL2);

	const uint16_t valores[500] = {	// Valores da senoide
			1860, 1875, 1891, 1906, 1922, 1937, 1953, 1968, 1984, 1999,
			2015, 2030, 2046, 2061, 2077, 2092, 2107, 2122, 2138, 2153,
			2168, 2183, 2198, 2213, 2228, 2243, 2257, 2272, 2287, 2301,
			2316, 2330, 2345, 2359, 2373, 2387, 2402, 2415, 2429, 2443,
			2457, 2470, 2484, 2497, 2511, 2524, 2537, 2550, 2563, 2576,
			2588, 2601, 2613, 2626, 2638, 2650, 2662, 2674, 2685, 2697,
			2708, 2720, 2731, 2742, 2753, 2763, 2774, 2784, 2795, 2805,
			2815, 2825, 2834, 2844, 2853, 2863, 2872, 2881, 2889, 2898,
			2906, 2915, 2923, 2931, 2939, 2946, 2954, 2961, 2968, 2975,
			2981, 2988, 2994, 3001, 3007, 3012, 3018, 3024, 3029, 3034,
			3039, 3044, 3048, 3052, 3057, 3061, 3064, 3068, 3071, 3075,
			3078, 3080, 3083, 3085, 3088, 3090, 3092, 3093, 3095, 3096,
			3097, 3098, 3099, 3099, 3099, 3100, 3099, 3099, 3099, 3098,
			3097, 3096, 3095, 3093, 3092, 3090, 3088, 3085, 3083, 3080,
			3078, 3075, 3071, 3068, 3064, 3061, 3057, 3052, 3048, 3044,
			3039, 3034, 3029, 3024, 3018, 3012, 3007, 3001, 2994, 2988,
			2981, 2975, 2968, 2961, 2954, 2946, 2939, 2931, 2923, 2915,
			2906, 2898, 2889, 2881, 2872, 2863, 2853, 2844, 2834, 2825,
			2815, 2805, 2795, 2784, 2774, 2763, 2753, 2742, 2731, 2720,
			2708, 2697, 2685, 2674, 2662, 2650, 2638, 2626, 2613, 2601,
			2588, 2576, 2563, 2550, 2537, 2524, 2511, 2497, 2484, 2470,
			2457, 2443, 2429, 2415, 2402, 2387, 2373, 2359, 2345, 2330,
			2316, 2301, 2287, 2272, 2257, 2243, 2228, 2213, 2198, 2183,
			2168, 2153, 2138, 2122, 2107, 2092, 2077, 2061, 2046, 2030,
			2015, 1999, 1984, 1968, 1953, 1937, 1922, 1906, 1891, 1875,
			1860, 1844, 1828, 1813, 1797, 1782, 1766, 1751, 1735, 1720,
			1704, 1689, 1673, 1658, 1642, 1627, 1612, 1597, 1581, 1566,
			1551, 1536, 1521, 1506, 1491, 1476, 1462, 1447, 1432, 1418,
			1403, 1389, 1374, 1360, 1346, 1332, 1317, 1304, 1290, 1276,
			1262, 1249, 1235, 1222, 1208, 1195, 1182, 1169, 1156, 1143,
			1131, 1118, 1106, 1093, 1081, 1069, 1057, 1045, 1034, 1022,
			1011, 999, 988, 977, 966, 956, 945, 935, 924, 914,
			904, 894, 885, 875, 866, 856, 847, 838, 830, 821,
			813, 804, 796, 788, 780, 773, 765, 758, 751, 744,
			738, 731, 725, 718, 712, 707, 701, 695, 690, 685,
			680, 675, 671, 667, 662, 658, 655, 651, 648, 644,
			641, 639, 636, 634, 631, 629, 627, 626, 624, 623,
			622, 621, 620, 620, 620, 620, 620, 620, 620, 621,
			622, 623, 624, 626, 627, 629, 631, 634, 636, 639,
			641, 644, 648, 651, 655, 658, 662, 667, 671, 675,
			680, 685, 690, 695, 701, 707, 712, 718, 725, 731,
			738, 744, 751, 758, 765, 773, 780, 788, 796, 804,
			813, 821, 830, 838, 847, 856, 866, 875, 885, 894,
			904, 914, 924, 935, 945, 956, 966, 977, 988, 999,
			1011, 1022, 1034, 1045, 1057, 1069, 1081, 1093, 1106, 1118,
			1131, 1143, 1156, 1169, 1182, 1195, 1208, 1222, 1235, 1249,
			1262, 1276, 1290, 1304, 1317, 1332, 1346, 1360, 1374, 1389,
			1403, 1418, 1432, 1447, 1462, 1476, 1491, 1506, 1521, 1536,
			1551, 1566, 1581, 1597, 1612, 1627, 1642, 1658, 1673, 1689,
			1704, 1720, 1735, 1751, 1766, 1782, 1797, 1813, 1828, 1844
	};

	while (1) {
		for(int i = 0; i < 500; i++) {
			DAC_SetValue(DAC_CHANNEL2, valores[i], DAC_RES_12BITS);
			Delay_us(4);
		}
	}
}
void WatchDogAnalogico() {
	Utility_Init();
	USART1_Init();

	ADC_Init(ADC1, SINGLE_CHANNEL, ADC_RES_12BITS);
	ADC_SingleChannel(ADC1, ADC_IN0);

	ADC1->LTR = 620;
	ADC1->HTR = 2482;
	ADC1->CR1 |= ADC_CR1_AWDSGL;
	ADC1->CR1 &= ~ADC_CR1_AWDCH;
	ADC1->CR1 |= ADC_CR1_AWDEN;


	while (1) {
		ADC1->CR2 |= ADC_CR2_SWSTART;
		while(!(ADC1->SR & ADC_SR_EOC));

		printf("Leitura: %.2f\n", ((float)ADC1->DR *3.3)/4095);

		if(ADC1->SR & ADC_SR_AWD){
			printf("Saida da regiao monitorada!\n");
		}

		ADC1->SR &= ~ADC_SR_AWD;
		Delay_ms(500);
	}
}
void SensorDeTemperatura() {
	Utility_Init();
	USART1_Init();

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;		//liga o clock da interface digital do ADC1
	ADC->CCR |= 0b01 << 16;					//prescaler /4
	ADC1->SQR1 &= ~(0xF << 20);				//conversão de apenas um canal
	ADC1->SQR3 = 16;						//seleção do canal a ser convertido (IN 16)
	ADC1->SMPR1 |= (7 << 18);				//tempo de amostragem igual a 480 ciclos de ADCCLK
	ADC->CCR |= ADC_CCR_TSVREFE;				//liga o sensor de temperatura
	ADC1->CR2 |= ADC_CR2_ADON;				//liga o conversor AD

	uint32_t *p = (uint32_t *) 0x1FFF7A2C;
	uint32_t Word = *p;
	uint16_t TS_CAL1 = (Word & 0x0000FFFF);
	uint16_t TS_CAL2 = (Word & 0xFFFF0000) >> 16;

	while(1) {

		ADC1->CR2 |= ADC_CR2_SWSTART;
		while(!(ADC1->SR & ADC_SR_EOC));
		float temperatura = ((80*(float) (ADC1->DR - TS_CAL1))/(TS_CAL2-TS_CAL1))+30;
		printf("Temperatura = %.2f\n", temperatura);
		Delay_ms(500);
	}
}

// QUESTÕES DA PRIMEIRA UNIDADE
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
		Delay_us(1999 - i);
		HAL_GPIO_WritePin(porta, pino, GPIO_PIN_SET);
		Delay_us(i);
	}
	for(int i = 0; i < 2000; i += velocidade) {
		HAL_GPIO_WritePin(porta, pino, GPIO_PIN_RESET);
		Delay_us(i);
		HAL_GPIO_WritePin(porta, pino, GPIO_PIN_SET);
		Delay_us(1999 - i);
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
void DisplaySeteSegHexa() {

	Utility_Init();
	GPIO_Clock_Enable(GPIOE);

	GPIO_Pin_Mode(GPIOE, PIN_0, OUTPUT);	// LED A
	GPIO_Pin_Mode(GPIOE, PIN_1, OUTPUT);	// LED B
	GPIO_Pin_Mode(GPIOE, PIN_2, OUTPUT);	// LED C
	GPIO_Pin_Mode(GPIOE, PIN_3, OUTPUT);	// LED D
	GPIO_Pin_Mode(GPIOE, PIN_4, OUTPUT);	// LED E
	GPIO_Pin_Mode(GPIOE, PIN_5, OUTPUT);	// LED F
	GPIO_Pin_Mode(GPIOE, PIN_6, OUTPUT);	// LED G
	GPIO_Pin_Mode(GPIOE, PIN_7, OUTPUT);	// On/Off

	const uint8_t digitos[16] = {
	  0b00111111, // 0
	  0b00000110, // 1
	  0b01011011, // 2
	  0b01001111, // 3
	  0b01100110, // 4
	  0b01101101, // 5
	  0b01111101, // 6
	  0b00000111, // 7
	  0b01111111, // 8
	  0b01101111, // 9
	  0b01110111, // A
	  0b01111100, // b
	  0b00111001, // C
	  0b01011110, // d
	  0b01111001, // E
	  0b01110001  // F
	};

	while(1) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
		for(int i = 0; i < 16; i++) {
			GPIOE->ODR = digitos[i];
			Delay_ms(500);
		}
	}
}
void DisplaySeteSegHexa2D() {

	Utility_Init();
	GPIO_Clock_Enable(GPIOE);

	GPIO_Pin_Mode(GPIOE, PIN_0, OUTPUT);	// LED A
	GPIO_Pin_Mode(GPIOE, PIN_1, OUTPUT);	// LED B
	GPIO_Pin_Mode(GPIOE, PIN_2, OUTPUT);	// LED C
	GPIO_Pin_Mode(GPIOE, PIN_3, OUTPUT);	// LED D
	GPIO_Pin_Mode(GPIOE, PIN_4, OUTPUT);	// LED E
	GPIO_Pin_Mode(GPIOE, PIN_5, OUTPUT);	// LED F
	GPIO_Pin_Mode(GPIOE, PIN_6, OUTPUT);	// LED G
	GPIO_Pin_Mode(GPIOE, PIN_7, OUTPUT);	// On/Off Digito 1
	GPIO_Pin_Mode(GPIOE, PIN_8, OUTPUT);	// On/Off Digito 2

	const uint8_t digitos[16] = {
	  0b00111111, // 0
	  0b00000110, // 1
	  0b01011011, // 2
	  0b01001111, // 3
	  0b01100110, // 4
	  0b01101101, // 5
	  0b01111101, // 6
	  0b00000111, // 7
	  0b01111111, // 8
	  0b01101111, // 9
	  0b01110111, // A
	  0b01111100, // b
	  0b00111001, // C
	  0b01011110, // d
	  0b01111001, // E
	  0b01110001  // F
	};

	while(1) {

		for(int i = 0; i < 16; i++) {
			for(int j = 0; j < 16; j++) {
				int contador = 0;
				while(contador < 50) {
					GPIOE->ODR = digitos[i];
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
					Delay_ms(1);

					GPIOE->ODR = digitos[j];
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
					Delay_ms(1);

					contador++;
				}
			}
		}
		for(int i = 15; i >= 0; i--) {
			for(int j = 15; j >= 0; j--) {
				int contador = 0;
				while(contador < 50) {
					GPIOE->ODR = digitos[i];
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
					Delay_ms(1);

					GPIOE->ODR = digitos[j];
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
					Delay_ms(1);

					contador++;

				}
			}
		}
	}
}
void Genius() {
	GPIO_Clock_Enable(GPIOE);

	// botões
	GPIO_Pin_Mode(GPIOE, PIN_0, INPUT);
	GPIO_Pin_Mode(GPIOE, PIN_1, INPUT);
	GPIO_Pin_Mode(GPIOE, PIN_2, INPUT);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);

	GPIO_Resistor_Enable(GPIOE, PIN_0, PULL_UP);
	GPIO_Resistor_Enable(GPIOE, PIN_1, PULL_UP);
	GPIO_Resistor_Enable(GPIOE, PIN_2, PULL_UP);
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);

	// leds
	GPIO_Pin_Mode(GPIOE, PIN_4, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_5, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_7, OUTPUT);

	int tamanho = 0;
	int entrada = 0;
	uint16_t sequencia[20];
	uint16_t numero;

	while (1) {

		for(int i = 0; i < 4; i++) {
			GPIO_Write_Pin(GPIOE, PIN_4, HIGH);
			GPIO_Write_Pin(GPIOE, PIN_5, HIGH);
			GPIO_Write_Pin(GPIOE, PIN_6, LOW);
			GPIO_Write_Pin(GPIOE, PIN_7, LOW);
			Delay_ms(150);
			GPIO_Write_Pin(GPIOE, PIN_4, LOW);
			GPIO_Write_Pin(GPIOE, PIN_5, LOW);
			GPIO_Write_Pin(GPIOE, PIN_6, HIGH);
			GPIO_Write_Pin(GPIOE, PIN_7, HIGH);
			Delay_ms(150);
		}
		GPIO_Write_Pin(GPIOE, PIN_6, LOW);
		GPIO_Write_Pin(GPIOE, PIN_7, LOW);

		Delay_ms(1000);

		do {
		    numero = Random_Number();
		} while (numero != PIN_4 &&
		         numero != PIN_5 &&
		         numero != PIN_6 &&
		         numero != PIN_7);
		sequencia[tamanho] = numero;
		tamanho++;


		for(int i = 0; i < tamanho; i++) {
			Delay_ms(350);
			GPIO_Write_Pin(GPIOE, sequencia[i], HIGH);
			Delay_ms(350);
			GPIO_Write_Pin(GPIOE, sequencia[i], LOW);
		}


		while(1) {

			// Chegou ao fim
			if(entrada == tamanho) {
				entrada = 0;
				break;
			}

			if(!GPIO_Read_Pin(GPIOE, PIN_0)) {
				GPIO_Write_Pin(GPIOE, PIN_4, HIGH);
				Delay_ms(300);
				GPIO_Write_Pin(GPIOE, PIN_4, LOW);

					entrada = tamanho = 0;
				} else {
					entrada++;
				}
			}


			if(!GPIO_Read_Pin(GPIOE, PIN_1)) {
				GPIO_Write_Pin(GPIOE, PIN_5, HIGH);
				Delay_ms(300);
				GPIO_Write_Pin(GPIOE, PIN_5, LOW);
				if(sequencia[entrada] != PIN_5) {
					for(int i = 0; i < 6; i++) {
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_5);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_6);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_7);
						Delay_ms(500);
					}
					entrada = tamanho = 0;
				} else {
					entrada++;
				}
			}


			if(!GPIO_Read_Pin(GPIOE, PIN_2)) {
				GPIO_Write_Pin(GPIOE, PIN_6, HIGH);
				Delay_ms(300);
				GPIO_Write_Pin(GPIOE, PIN_6, LOW);
				if(sequencia[entrada] != PIN_6) {
					for(int i = 0; i < 6; i++) {
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_5);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_6);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_7);
						Delay_ms(500);
					}
					entrada = tamanho = 0;
				} else {
					entrada++;
				}
			}


			if(!GPIO_Read_Pin(GPIOE, PIN_3)) {
				GPIO_Write_Pin(GPIOE, PIN_7, HIGH);
				Delay_ms(300);
				GPIO_Write_Pin(GPIOE, PIN_7, LOW);
				if(sequencia[entrada] != PIN_7) {
					for(int i = 0; i < 6; i++) {
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_5);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_6);
						HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_7);
						Delay_ms(500);
					}
					entrada = tamanho = 0;
				} else {
					entrada++;
				}
			}
		}
	}
void SensorUltrassonico() {
	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_0, INPUT);		// ECHO
	GPIO_Pin_Mode(GPIOE, PIN_1, OUTPUT);	// TRIG
	GPIO_Write_Pin(GPIOE, PIN_1, LOW);
	GPIO_Pin_Mode(GPIOE, PIN_2, OUTPUT);	// BUZZER

	unsigned int distancia = 0;
	int tempo = 0;

	while (1) {

		// Enviando pulso
		Delay_ms(10);
		GPIO_Write_Pin(GPIOE, PIN_1, HIGH);
		Delay_us(10);
		GPIO_Write_Pin(GPIOE, PIN_1, LOW);

		// Iniciando contagem
		while(!GPIO_Read_Pin(GPIOE, PIN_0));
		tempo = 0;
		while(GPIO_Read_Pin(GPIOE, PIN_0)) {
			Delay_us(1);
			tempo++;
		}

		// Calculando distância
		distancia = tempo/58;

		// Acionando LED
		if(distancia > 50) {
			GPIO_Write_Pin(GPIOE, PIN_2, LOW);
		} else if(distancia > 40) {
			GPIO_Write_Pin(GPIOE, PIN_2, HIGH);
			Delay_ms(500);
			GPIO_Write_Pin(GPIOE, PIN_2, LOW);
			Delay_ms(500);
		} else if(distancia > 30) {
			GPIO_Write_Pin(GPIOE, PIN_2, HIGH);
			Delay_ms(300);
			GPIO_Write_Pin(GPIOE, PIN_2, LOW);
			Delay_ms(300);
		} else if(distancia > 20) {
			GPIO_Write_Pin(GPIOE, PIN_2, HIGH);
			Delay_ms(100);
			GPIO_Write_Pin(GPIOE, PIN_2, LOW);
			Delay_ms(100);
		} else if(distancia > 7) {
			GPIO_Write_Pin(GPIOE, PIN_2, HIGH);
			Delay_ms(50);
			GPIO_Write_Pin(GPIOE, PIN_2, LOW);
			Delay_ms(50);
		} else {
			GPIO_Write_Pin(GPIOE, PIN_2, HIGH);
		}
	}
}
void MotorDC() {
	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_0, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOE, PIN_2, OUTPUT);

	Delay_ms(1000);

	while (1) {
		// Mudando sentido e ativando PWM
		GPIO_Write_Pin(GPIOE, PIN_0, LOW);
		GPIO_Write_Pin(GPIOE, PIN_1, HIGH);
		AtivarModoPWM(GPIOE, GPIO_PIN_2, 2);

		// Mudando sentido e ativando PWM
		GPIO_Write_Pin(GPIOE, PIN_0, HIGH);
		GPIO_Write_Pin(GPIOE, PIN_1, LOW);
		AtivarModoPWM(GPIOE, GPIO_PIN_2, 2);
	}
}
void MicroServomotor() {
	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_0, OUTPUT);			// Pino do motor
	GPIO_Pin_Mode(GPIOE, PIN_2, INPUT);				// Botão
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);				// Botão
	GPIO_Resistor_Enable(GPIOE, PIN_2, PULL_UP);
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);

	contador = 500;
	while (1) {

		if(!GPIO_Read_Pin(GPIOE, PIN_3)) {
			GPIO_Write_Pin(GPIOE, PIN_0, HIGH);
			Delay_us(contador);
			GPIO_Write_Pin(GPIOE, PIN_0, LOW);
			Delay_us(20000 - contador);
			if(contador < 2500) {
				contador += 10;
			}
		}

		if(!GPIO_Read_Pin(GPIOE, PIN_2)) {
			GPIO_Write_Pin(GPIOE, PIN_0, HIGH);
			Delay_us(contador);
			GPIO_Write_Pin(GPIOE, PIN_0, LOW);
			Delay_us(20000 - contador);
			if(contador > 500) {
				contador -= 10;
			}
		}
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
