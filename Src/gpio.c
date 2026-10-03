/*
 * gpio.c
 *
 *  Created on: Sep 24, 2026
 *      Author: Admin
 */


#include "gpio.h"

#define GPIOAEN		(1U<<0)
#define GPIOBEN 	(1U<<1)
#define GPIOCEN 	(1U<<2)
#define GPIODEN 	(1U<<3)
#define GPIOEEN 	(1U<<4)
#define GPIOFEN 	(1U<<5)
#define GPIOGEN 	(1U<<6)
#define GPIOHEN 	(1U<<7)

void gpio_init(char pin_port,uint8_t pin,uint8_t mode)
{
	switch(pin_port){
	case 'A':
		RCC_AHB1ENR |= GPIOAEN;
		GPIO_MODER(A) &= ~(0x3 << (pin*2));   // clear mode bits
		GPIO_MODER(A) |= (mode << (pin*2));
		break;
	case 'B':
		RCC_AHB1ENR |= GPIOBEN;
		GPIO_MODER(B) &= ~(0x3 << (pin*2));   // clear mode bits
		GPIO_MODER(B) |= (mode << (pin*2));
		break;

	case 'C':
		RCC_AHB1ENR |= GPIOCEN;
		GPIO_MODER(C) &= ~(0x3 << (pin*2));   // clear mode bits
		GPIO_MODER(C) |= (mode << (pin*2));
		break;


	case 'D':
		RCC_AHB1ENR |= GPIODEN;
		GPIO_MODER(D) &= ~(0x3 << (pin*2));   // clear mode bits
		GPIO_MODER(D) |= (mode << (pin*2));
		break;


	case 'E':
		RCC_AHB1ENR |= GPIOEEN;
		GPIO_MODER(E) &= ~(0x3 << (pin*2));   // clear mode bits
		GPIO_MODER(E) |= (mode << (pin*2));
		break;

	case 'F':
		RCC_AHB1ENR |= GPIOFEN;
		GPIO_MODER(F) &= ~(0x3 << (pin*2));   // clear mode bits
		GPIO_MODER(F) |= (mode << (pin*2));
		break;

	case 'G':
		RCC_AHB1ENR |= GPIOGEN;
		GPIO_MODER(G) &= ~(0x3 << (pin*2));   // clear mode bits
		GPIO_MODER(G) |= (mode << (pin*2));
		break;

	case 'H':
		RCC_AHB1ENR |= GPIOHEN;
		GPIO_MODER(H) &= ~(0x3 << (pin*2));   // clear mode bits
		GPIO_MODER(H) |= (mode << (pin*2));
		break;

	}
}
void gpio_on(char pin_port,uint8_t pin)
{
	switch(pin_port){
	case 'A':
		GPIO_ODR(A) |= (1U << pin);
		break;
	case 'B':
		GPIO_ODR(B) |= (1U << pin);
		break;

	case 'C':
		GPIO_ODR(C) |= (1U << pin);
		break;

	case 'D':
		GPIO_ODR(D) |= (1U << pin);
		break;


	case 'E':
		GPIO_ODR(E) |= (1U << pin);
		break;

	case 'F':
		GPIO_ODR(F) |= (1U << pin);
		break;

	case 'G':
		GPIO_ODR(G) |= (1U << pin);
		break;

	case 'H':
		GPIO_ODR(H) |= (1U << pin);
		break;

	}

}
void gpio_toggle(char port,uint8_t pin)
{
	switch(port){
	case 'A':
		GPIO_ODR(A) ^= (1U << pin);
		break;
	case 'B':
		GPIO_ODR(B) ^= (1U << pin);
		break;

	case 'C':
		GPIO_ODR(C) ^= (1U << pin);
		break;


	case 'D':
		GPIO_ODR(D) ^= (1U << pin);
		break;

	case 'E':
		GPIO_ODR(E) ^= (1U << pin);
		break;

	case 'F':
		GPIO_ODR(F) ^= (1U << pin);
		break;

	case 'G':
		GPIO_ODR(G) ^= (1U << pin);
		break;

	case 'H':
		GPIO_ODR(H) ^= (1U << pin);
		break;

	}
}
void led_delay(void)
{
	for (volatile int x = 0; x < 50000; x++);
}
void program_state_set(int *prgm_state){
	if(!(GPIO_IDR(C) & (1<<USER_BUTTON))){
		if(*prgm_state != ONN)
			*prgm_state = ONN;
		else if(*prgm_state != OFF)
			*prgm_state = OFF;
	}
}

void progrm_state_led(int *prgm_state){
	if(*prgm_state == ONN){
		gpio_toggle('A',5);
		led_delay();
	}
}
