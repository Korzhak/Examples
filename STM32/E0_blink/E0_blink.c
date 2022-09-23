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
        if (flag)
        {
            GPIOB->BSRR = GPIO_PIN_0;       // HIGH level
        }
        else
        {
            GPIOB->BSRR = GPIO_PIN_0 << 16; // LOW level
            // OR                           
            GPIOB->BRR = GPIO_PIN_0;        // LOW levels
        }
            
        /*     About registers ORD, BSRR, BRR

        ODR registerIt is readable and writable, 32 bits, can control the pin to be high level, 
        and can also control the pin to be low level. For GPIO pins, write 1 to high level and 
        write 0 to low level. (The low 16 bits are used to set the output high/low level of the 
        corresponding bit of the GPIO port. The high 16 bits are reserved for the address, and 
        reading and writing are invalid.)

        BSRR registerIt is called port bit setting/clearing register, write-only register, 32-bit, 
        can control the pin to be high level, also can control the pin to be low level, write 1 
        to the high 16 bits of the register , the corresponding pin is low level , Write 1 to the 
        lower 16 bits of the register and the corresponding pin is high. Write 0, no action

        BRR registerIt is called port bit clearing register, only write register, 32 bits, can 
        only change the pin status to low level, the corresponding bit of the register pin will 
        be written 1 and the corresponding pin will become low level. Writing 0 has no action. 
        (The lower 16 bits of BRR are used to set the corresponding bit of the GPIO port to output 
        low level. The upper 16 bits are reserved for the address, and reading and writing are invalid.)

        So theoretically, the function of the BRR register (lower 16 bits) is the same as the function 
        of the upper 16 bits of the BSRR register.

        Source: https://blog.krybot.com/a?ID=01600-ce7296c6-40e3-4155-b9ce-fe10137169ee

        */
        
    }
}