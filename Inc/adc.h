/*
 * adc.h
 *
 *  Created on: Sep 25, 2026
 *      Author: Admin
 */

#include "base.h"

#define ADC_SR_OFFSET		 (0x00)
#define ADC_SR(inst_num)     (*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_SR_OFFSET))

#define ADC_CR2_OFFSET		 (0x08)
#define ADC_CR2(inst_num)    (*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_CR2_OFFSET))

#define ADC_CR1_OFFSET		 (0x04)
#define ADC_CR1(inst_num)    (*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_CR1_OFFSET))

#define ADC_DR_OFFSET 		 ( 0x4C)
#define ADC_DR(inst_num)	 (*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_DR_OFFSET))

#define ADC_SQR1_OFFSET		 (0x2C)
#define ADC_SQR1(inst_num)			(*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_SQR1_OFFSET))

#define ADC_SQR2_OFFSET		 (0x30)
#define ADC_SQR2(inst_num)			(*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_SQR2_OFFSET))

#define ADC_SQR3_OFFSET		 (0x34)
#define ADC_SQR3(inst_num)			(*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_SQR3_OFFSET))

#define ADC_SMPR1_OFFSET	 (0x0C)
#define ADC_SMPR1(inst_num) 	(*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_SMPR1_OFFSET))

#define ADC_SMPR2_OFFSET	 ( 0x10)
#define ADC_SMPR2(inst_num) 	(*(volatile unsigned int*) (ADC##inst_num##_PERIPHERAL + ADC_SMPR2_OFFSET))


void adc_init(void);
void adc_conversion(void);
int adc_read(void);
void adc_sample_signal(char *buff,int *prgm_state);
void adc_transmit_signal(char *buff);
