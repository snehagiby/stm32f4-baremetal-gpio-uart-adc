/*
 * usart.h
 *
 *  Created on: Sep 24, 2026
 *      Author: Admin
 */

#ifndef USART_H_
#define USART_H_

#include "base.h"
#include <stdio.h>
#include <stdint.h>
#include "gpio.h"

#define USARTx_SR_OFFSET 	(0x00)
#define USART_SR(inst_num)         (*(volatile unsigned int *)(USART##inst_num##_PERIPHERAL + USARTx_SR_OFFSET))

#define USARTx_DR_OFFSET	(0x04)
#define USART_DR(inst_num)	(*(volatile unsigned int *)(USART##inst_num##_PERIPHERAL + USARTx_DR_OFFSET))

#define USARTx_BRR_OFFSET	(0x08)
#define USART_BRR(inst_num) (*(volatile unsigned int *)(USART##inst_num##_PERIPHERAL + USARTx_BRR_OFFSET))

#define USARTx_CR1_OFFSET	(0x0C)
#define USART_CR1(inst_num) (*(volatile unsigned int*)(USART##inst_num##_PERIPHERAL + USARTx_CR1_OFFSET))

#define USARTx_CR2_OFFSET   (0x10)
#define USART_CR2(inst_num) (*(volatile unsigned int*)(USART##inst_num##_PERIPHERAL + USARTx_CR2_OFFSET))

#define USARTx_CR3_OFFSET	(0x14)
#define USART_CR3(inst_num) (*(volatile unsigned int*)(USART##inst_num##_PERIPHERAL + USARTx_CR3_OFFSET))

#define USARTx_GTPR_OFFSET	(0x18)
#define USART_GTPR(inst_num) (*(volatile unsigned int *)(USART##inst_num##_PERIPHERAL + USARTx_GTPR_OFFSET))

#define RCC_APB1ENR_OFFSET			(0x40)
#define RCC_APB1ENR                (*(volatile unsigned int *)  (RCC_PERIPHERAL + RCC_APB1ENR_OFFSET))

#define RCC_APB2ENR_OFFSET			(0x44)
#define RCC_APB2ENR					(*(volatile unsigned int *) (RCC_PERIPHERAL + RCC_APB2ENR_OFFSET))


void usart_init(uint8_t inst);
void usart_write(uint8_t inst,char val);
char usart_read(uint8_t inst);
void usart_set_baudrate(unsigned inst,uint32_t peripheral_clock,uint32_t baudrate);
void print_string(char *ptr);
#endif /* USART_H_ */
