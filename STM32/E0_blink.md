# Example 0: blink

This example show you how to blinking led in different ways in STM32

## Hardware
**MCU:** STM32H743ZIT6

**BOARD:** NUCLEO-144

### Additional information about board
*LED_1 (green):* `PB0` 

*LED_2 (yellow):* `PB7` 

*LED_3 (red):* `PB14` 

## Used software

**Configuring of project:** CubeMX

**Making code:** IAR Embedded Workbench IDE; Visual Studio Code (with IAR plugins) 

## Config of project

### SYS
**Timebase Source:** `SysTick`

### RCC
**HSE:** `Crystal/Ceramic Resonator`

### GPIO
**PB0:** `GPIO_Output`