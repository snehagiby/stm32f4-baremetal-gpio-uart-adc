/*
 * gpio.h
 *
 *  Created on: Sep 24, 2026
 *      Author: Admin
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "base.h"
#include <stdint.h>
#include <stdio.h>

#define GPIOx_MODER_OFFSET 		(0x00)
#define GPIO_MODER(port)		(*(volatile unsigned int *)(GPIO##port##_PERIPHERAL + GPIOx_MODER_OFFSET))

#define GPIOx_ODR_OFFSET		(0x14)
#define GPIO_ODR(port)			(*(volatile unsigned int *)(GPIO##port##_PERIPHERAL + GPIOx_ODR_OFFSET))

#define GPIOx_IDR_OFFSET		(0x10)
#define GPIO_IDR(port)			(*(volatile unsigned int *)(GPIO##port##_PERIPHERAL + GPIOx_IDR_OFFSET))

#define GPIOx_BSRR_OFFSET		(0x18)
#define GPIO_BSRR(port)			(*(volatile unsigned int *)(GPIO##port##_PERIPHERAL + GPIOx_BSRR_OFFSET))

#define GPOIx_AFRL_OFFSET		(0x20)
#define GPIO_AFRL(port)			(*(volatile unsigned int *)(GPIO##port##_PERIPHERAL + GPOIx_AFRL_OFFSET))

#define GPOIx_AFRH_OFFSET		(0x24)
#define GPIO_AFRH(port)			(*(volatile unsigned int *)(GPIO##port##_PERIPHERAL + GPOIx_AFRH_OFFSET))


#define RCC_AHB1ENR_OFFSET		(0x30)
#define RCC_AHB1ENR				(*(volatile unsigned int *)(RCC_PERIPHERAL + RCC_AHB1ENR_OFFSET))

#define GPIO_INPUT				(0x00)
#define GPIO_OUTPUR				(0x01)
#define GPIO_AF					(0x02)
#define GPIO_ANALOG				(0x03)

enum state{
	ONN = 0,
	OFF = 1
};
#define USER_BUTTON               (0x0D)
void gpio_init(char pin_port,uint8_t pin,uint8_t mode);
void gpio_on(char pin_port,uint8_t pin);
void gpio_toggle(char port,uint8_t pin);
void led_delay(void);
void program_state_set(int *prgm_state);
void progrm_state_led(int *prgm_state);
#endif /* GPIO_H_ */
