/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>
#include "settings.h"
/* USER CODE END Includes */


  /* USER CODE BEGIN 0 */
CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;

uint8_t RxData[8];
uint32_t TxMailBox;
uint32_t T;

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData);
	printf("Received data: ");
	for (int j = 0; j<RxHeader.DLC; j++) {
		printf("0x%x  ", RxData[j]);
	}
	printf("\n");

}
/* USER CODE END 0 */
  
  
ing main (void)
{
    /* USER CODE BEGIN 2 */
    HAL_CAN_Start(&hcan1);
    HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
    TxHeader.IDE = CAN_ID_STD;
    TxHeader.RTR = CAN_RTR_DATA;
    TxHeader.StdId = DEVICE_ID;

    T = HAL_GetTick();
    /* USER CODE END 2 */

    /* USER CODE BEGIN WHILE */
    while (1)
    {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */

        if ((HAL_GetTick() - T) > SEND_DELAY)
        {
            TxHeader.DLC = 2;
            uint8_t data[8] = {0x10, 0x20}
            HAL_StatusTypeDef status = HAL_CAN_AddTxMessage(&hcan1, &TxHeader, data, &TxMailBox);
            if (status == HAL_OK)
            {
                printf("Data for servo has been sent \n");
            }
            else
            {
                printf("Error sending data\n");
            }
        }
    }
    /* USER CODE END 3 */
}


static void MX_CAN1_Init(void)
{
  /* USER CODE BEGIN CAN1_Init 2 */
  CAN_FilterTypeDef canfilter;

  canfilter.FilterActivation = CAN_FILTER_ENABLE;
  canfilter.FilterBank = 18;
  canfilter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
  canfilter.FilterIdHigh = FILTER_ID;                     // ID of income message (uint32_t)
  canfilter.FilterIdLow = 0;
  canfilter.FilterMaskIdHigh = FILTER_ID<<5;              // ID of income message (uint32_t) 
  canfilter.FilterMaskIdLow = 0x0000;
  canfilter.FilterMode = CAN_FILTERMODE_IDMASK;
  canfilter.FilterScale = CAN_FILTERSCALE_32BIT;
  canfilter.SlaveStartFilterBank = 20;

  HAL_CAN_ConfigFilter(&hcan1, &canfilter);
  /* USER CODE END CAN1_Init 2 *

}