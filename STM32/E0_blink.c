#include "main.h"
#include "stdbool.h"  // STM32 compiler doesn't know of bool type, 
                      // so we have to import library with such type

#define DELAY_TIME 1000

bool flag;
unsigned long T;


int main(void) 
{
    // Current code block like a setup() in Arduino.
    T = HAL_GetTick();   // Like a millis() in gcc and Arduino().

    while (1) 
    {
        // Change state of flag for turn on or off LED
        if (HAL_GetTick()-T >= DELAY_TIME) 
        {
            T = HAL_GetTick();
            flag = !flag;
        }

        // == DIFFERENT WAYS TO REALIZE PINS OUT ==
        // 1. Realize it using HAL tools
        if (flag)
            // Setup PIN_0 of PORT B to HIGH level (GPIO_PIN_SET)
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); 
        else 
            // Setup PIN_0 of PORT B to LOW level (GPIO_PIN_RESET)
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET)

        // 2. Also we can replace GPIO_PIN_SET/RESET to boolean type
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, flag);

        // 3. And we can use registers for set pin to low or high level
        //                             LOW level            HIGH level
        GPIOB->BSRR = flag ? (uint32_t) GPIO_PIN_0 << 16u : GPIO_PIN_0;
    }
}