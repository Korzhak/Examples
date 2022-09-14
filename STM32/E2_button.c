#include "main.h"

int main(void) 
{
    if(HAL_GPIO_ReadPin(GPIOC, GPIOC_PIN_13))
    {
        // If button push
    }
    else
    {
        // if button doesn't push
    }
}