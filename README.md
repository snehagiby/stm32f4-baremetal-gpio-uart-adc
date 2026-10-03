Register-level peripheral drivers for the STM32F446RE written without CMSIS or HAL.
All peripheral access done directly via memory mapped register address and bit field.

Target Hardware
	
-MCU	STM32F446RE
-Board	NUCLEO-F446RE
-Toolchain	STM32CubeIDE

Feature

  -GPIO Pin PA5 in build LED on Nucleo board blink based on inbuild button press status.
  -GPIO Pin PC13 in build button for the Nucleo board controls the LED blinking.
  -USART2 PA2,PA3 AF0 in build USART for printing the data on console.
  -ADC1 PA1 in build A1 pin for reading the Analog value based on the button status.

Project Structure

├── Inc/           # Header files (base.h,adc.h,gpio.h,usart.h)
├── Src/           # Source files (driver implementations-base.c,adc.c,gpio.c,usart.c, main.c)
├── Startup/       # Startup assembly file
├── STM32F446RETX_FLASH.ld   # Linker script (Flash)
├── STM32F446RETX_RAM.ld     # Linker script (RAM)
├── .project / .cproject     # STM32CubeIDE project files
└── .gitignore

Usage API
GPIO:
void gpio_init(char pin_port,uint8_t pin,uint8_t mode);
void gpio_on(char pin_port,uint8_t pin);
void gpio_toggle(char port,uint8_t pin);
void led_delay(void);
void program_state_set(int *prgm_state);
void progrm_state_led(int *prgm_state);

USART:
void usart_init(uint8_t inst);
void usart_write(uint8_t inst,char val);
char usart_read(uint8_t inst);
void usart_set_baudrate(unsigned inst,uint32_t peripheral_clock,uint32_t baudrate);  //USART_BRR = (peripheral_clock + baudrate/2U)/baudrate;
void print_string(char *ptr);

adc:
void adc_init(void);
void adc_conversion(void);
int adc_read(void);
void adc_sample_signal(char *buff,int *prgm_state);
void adc_transmit_signal(char *buff);


NOTE: Clock source is determined from the Block Diagram in the Datasheet DS10693 Rev 11.
Peripheral address are determine from the memory map in the reference manual RM0390.
Alternate function is also determined from the Data sheet DS10693 Rev 11.
Nucleo board pin for the in build LED,Push Button,USART and ADC is determined from the Nucleo - f446re schematic MB1136.

