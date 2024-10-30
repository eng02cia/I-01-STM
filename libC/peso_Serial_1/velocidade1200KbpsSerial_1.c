#include "stm32f1xx_hal.h"
extern UART_HandleTypeDef huart2;
void velocidade1200KbpsSerial_1(void)
{
	HAL_UART_Abort_IT(&huart2);
	HAL_UART_DeInit(&huart2);
	huart2.Init.BaudRate = 1200;
	HAL_UART_Init(&huart2);
//	ATOMIC_SET_BIT(huart1->Instance->CR1, USART_CR1_RTOIE);
}

