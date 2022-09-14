# Example 2: blink

This example show you how to get button state on STM32

## Hardware
**MCU:** STM32H743ZIT6

**BOARD:** NUCLEO-144

### Additional information about board
*User Button:* `PC13` 

## Used software

**Configuring of project:** CubeMX

**Making code:** IAR Embedded Workbench IDE; Visual Studio Code (with IAR plugins) 

## Config of project

### SYS
**Timebase Source:** `SysTick`

### RCC
**HSE:** `Crystal/Ceramic Resonator`

### GPIO
**PC13:** `GPIO_Input`
