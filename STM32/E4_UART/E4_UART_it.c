/*
 * EXAMPLE 4
 * ONLY INTERRUPTS UART
 */

/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */


/* USER CODE BEGIN 0 */
uint8_t UART1_rxBuffer[DATA_SIZE] = {0};

// MESSAGE HANDLER
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Receive_IT(&huart1, UART1_rxBuffer, DATA_SIZE);
    for (int i=0; i<DATA_SIZE; i++)
    {
        printf("%c", (char) UART1_rxBuffer[i]);
    }
    printf("\r\n");
}

// ERROR HANDLER
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	uint32_t error = huart->ErrorCode;
}

/* USER CODE END 0 */


int main(void)
{
    /* USER CODE BEGIN 2 */
    HAL_UART_Receive_IT(&huart1, UART1_rxBuffer, DATA_SIZE);
    /* USER CODE END 2 */

    while (1)
    {

    }
}



/* USER CODE BEGIN 4 */
int _write ( int file, char *ptr, int len )
{
  int i = 0;
  for ( i = 0; i < len; i++ )
    ITM_SendChar ( (*ptr++ ) );
  return len;
}
/* USER CODE END 4 */
