
# Example 4: UART

Example: [here](https://javakys.wordpress.com/2021/05/04/how-to-use-uart-dma-rx-on-stm32f103-mcu/)

This example show you how to work with UART (interrupt) on STM32.

## Hardware
**Configuring of project:** CubeMX

**Making code:** STM32CubeIDE  

## Config of project

### SYS
**Debug:** `Serial Wire`

**Timebase Source:** `SysTick`

### USART1

**Mode:** Activated

### - Parameter Settings

*You need to configure Prescaler and Time Quata in 1st and 2nd Bit for setting Baud Rate.*
*For example: if the frequency on clocks set as 16 MHz and you want the Baud Rate 500 000, you have to set next parameters:*

**Baud Rate:** 115200 Bits/s

**Word Length:** 8 Bits

### - NVIC Settings

**USART1 global interrupt:** True