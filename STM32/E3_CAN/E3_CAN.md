# Example 3: CAN bus

This example show you how to work with CAN bus on STM32.

For normal work you need CAN tranceiver like VP230 or MCP2515


## Hardware
**Configuring of project:** CubeMX

**Making code:** STM32CubeIDE  

## Config of project

### SYS
**Debug:** `Serial Wire`

**Timebase Source:** `SysTick`

### CAN1

**Activated:** True

### - Parameter Settings

*You need to configure Prescaler and Time Quata in 1st and 2nd Bit for setting Baud Rate.*
*For example: if the frequency on clocks set as 16 MHz and you want the Baud Rate 500 000, you have to set next parameters:*

**Prescaler (for Time Quantum):** 8

**Time Quanta in Bit Segment 1:** 2 Time

**Time Quanta in Bit Segment 2:** 1 Time

### - NVIC Settings

*You can set interrupts parameters for Receiving and Tranceiving messages.*

*If you set RX0 interrupts, the message will income to FIFO0 buffer.*

*And if you set RX1 interrupts, the message will income to FIFO1 buffer.*

**CAN1 Rx0 interrupts:** True

