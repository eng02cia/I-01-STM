
#include "stm32f1xx_hal.h"
extern UART_HandleTypeDef huart2;
void velocidade2400KbpsSerial_1(void)
{
	HAL_UART_Abort_IT(&huart2);
	HAL_UART_DeInit(&huart2);
	huart2.Init.BaudRate = 2400;
	HAL_UART_Init(&huart2);
//	HAL_UART_Receive_IT (&huart1,dado_Serial_1,1);
}    
   
