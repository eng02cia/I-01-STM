/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CONTROL485_Pin GPIO_PIN_13
#define CONTROL485_GPIO_Port GPIOC
#define pinoDataPs2_Pin GPIO_PIN_0
#define pinoDataPs2_GPIO_Port GPIOC
#define pinoDataPs2_EXTI_IRQn EXTI0_IRQn
#define pinoClockPs2_Pin GPIO_PIN_1
#define pinoClockPs2_GPIO_Port GPIOC
#define pinoClockPs2_EXTI_IRQn EXTI1_IRQn
#define FC1_Pin GPIO_PIN_2
#define FC1_GPIO_Port GPIOC
#define FC2_Pin GPIO_PIN_3
#define FC2_GPIO_Port GPIOC
#define FC3_Pin GPIO_PIN_0
#define FC3_GPIO_Port GPIOA
#define FC4_Pin GPIO_PIN_1
#define FC4_GPIO_Port GPIOA
#define TX2_TTL_Pin GPIO_PIN_2
#define TX2_TTL_GPIO_Port GPIOA
#define RX2_TTL_Pin GPIO_PIN_3
#define RX2_TTL_GPIO_Port GPIOA
#define pinoColuna2_Pin GPIO_PIN_4
#define pinoColuna2_GPIO_Port GPIOA
#define pinoBackLight_Pin GPIO_PIN_5
#define pinoBackLight_GPIO_Port GPIOA
#define adas_Pin GPIO_PIN_6
#define adas_GPIO_Port GPIOA
#define pinoData7_Pin GPIO_PIN_7
#define pinoData7_GPIO_Port GPIOA
#define pinoData6_Pin GPIO_PIN_4
#define pinoData6_GPIO_Port GPIOC
#define pinoData5_Pin GPIO_PIN_5
#define pinoData5_GPIO_Port GPIOC
#define pinoData4_Pin GPIO_PIN_0
#define pinoData4_GPIO_Port GPIOB
#define pinoLinha1_Pin GPIO_PIN_2
#define pinoLinha1_GPIO_Port GPIOB
#define Display_TX_Pin GPIO_PIN_10
#define Display_TX_GPIO_Port GPIOB
#define Display_RX_Pin GPIO_PIN_11
#define Display_RX_GPIO_Port GPIOB
#define pinoEnable_Pin GPIO_PIN_12
#define pinoEnable_GPIO_Port GPIOB
#define pinoSelectRegister_Pin GPIO_PIN_13
#define pinoSelectRegister_GPIO_Port GPIOB
#define rele1_Pin GPIO_PIN_14
#define rele1_GPIO_Port GPIOB
#define rele2_Pin GPIO_PIN_15
#define rele2_GPIO_Port GPIOB
#define pinoColuna3_Pin GPIO_PIN_6
#define pinoColuna3_GPIO_Port GPIOC
#define pinoLinha2_Pin GPIO_PIN_7
#define pinoLinha2_GPIO_Port GPIOC
#define pinoLinha3_Pin GPIO_PIN_8
#define pinoLinha3_GPIO_Port GPIOC
#define rele3_Pin GPIO_PIN_9
#define rele3_GPIO_Port GPIOC
#define led_Zero_Pin GPIO_PIN_8
#define led_Zero_GPIO_Port GPIOA
#define led_Tara_Pin GPIO_PIN_9
#define led_Tara_GPIO_Port GPIOA
#define pinoColuna1_Pin GPIO_PIN_10
#define pinoColuna1_GPIO_Port GPIOA
#define USB__Pin GPIO_PIN_12
#define USB__GPIO_Port GPIOA
#define rele4_Pin GPIO_PIN_15
#define rele4_GPIO_Port GPIOA
#define Bluetooh_TX_Pin GPIO_PIN_10
#define Bluetooh_TX_GPIO_Port GPIOC
#define Bluetooh_RX_Pin GPIO_PIN_11
#define Bluetooh_RX_GPIO_Port GPIOC
#define CONTROL_MD_Pin GPIO_PIN_3
#define CONTROL_MD_GPIO_Port GPIOB
#define pinoClockHx711_Pin GPIO_PIN_4
#define pinoClockHx711_GPIO_Port GPIOB
#define pinoDataHx711_Pin GPIO_PIN_5
#define pinoDataHx711_GPIO_Port GPIOB
#define TX1_TTL_Pin GPIO_PIN_6
#define TX1_TTL_GPIO_Port GPIOB
#define RX1_TTL_Pin GPIO_PIN_7
#define RX1_TTL_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
