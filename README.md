Register-level peripheral drivers for the STM32F446RE written without CMSIS or HAL.All peripheral access done directly via memory mapped register address and bit field.

TARGET HARDWARE
MCU:STM32F446RE
Board : Nucleo-F446RE
Toolchain: STM32CUBEIDE

Feature
GPIO Pin PA5 in build LED on Nucleo board blink based on inbuild button press status.
GPIO Pin PC13 in build button for the Nucleo board controls the LED blinking.
USART2 PA2,PA3 AF0 in build USART for printing the data on console.
ADC1 PA1 in build A1 pin for reading the Analog value based on the button status.