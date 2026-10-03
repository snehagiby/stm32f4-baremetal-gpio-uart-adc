/*
 * adc.c
 *
 *  Created on: Sep 25, 2026
 *      Author: Admin
 */


#include "adc.h"
#include "gpio.h"
#include "usart.h"

#define RCC_APB2_ADC1EN  (1U << 8)

#define ADC_SR_EOC				(1U << 1)
#define ADC_CR2_ADON			(1U << 0)
#define ADC_CR2_SWSTART			(1U << 30)
#define ADC_CR2_LEFT_ALIGN		(1U << 11)
#define ADC_CR2_RIGHT_ALIGN		(0U << 11)
#define ADC_CR2_CONT			(1U << 1)

/**
 * In Nucleo -F446RE we have PA0-A0,PA1-A1,PA4-A2,PB0-A3,PC1-A4,PC0-A5.
 * We are using PA1- A1 pin of board in our project.
 */
void adc_init(void){
  //allow clock to adc module
	RCC_APB2ENR &= ~(RCC_APB2_ADC1EN);
	RCC_APB2ENR |= (RCC_APB2_ADC1EN);
  //set the GPIO PA1 as analog input
	gpio_init('A',1,GPIO_ANALOG);
//set adc resolution 12-bit,continuous conversion, right aligned result.ans sampling time
	ADC_CR1(1) &= ~(3U << 24);   //resolution 00:12 bit

	ADC_CR2(1) &= ~(1U << 11);   // right aligned result
	ADC_SMPR2(1) &= ~(1 << 3*1);	//sample time set to 3 cycle.
	//select the channel
	ADC_SQR3(1)|= (1U << 0);             //assigned first channel conversion in position 0.
	//enable adc module
	ADC_CR2(1) |= (1u << 0);               // ADON = 1 (wake up)
	for (volatile int i = 0; i < 10000; i++);   // stabilization delay (missing)
}

void adc_conversion(void){
	ADC_CR2(1) |= ADC_CR2_CONT;	 //Continuous conversion

	ADC_CR2(1) |= ADC_CR2_SWSTART;//ADC conversion start
}

int adc_read(void){
  while(!(ADC_SR(1) & ADC_SR_EOC));
  return ADC_DR(1);
}
void adc_sample_signal(char *buff,int *prgm_state){
	int adc_val;
     if(*prgm_state == ONN){
    	 adc_val = adc_read();
    	 sprintf(buff, "%d\r\n", adc_val);
    	 adc_transmit_signal(buff);
     }
}
void adc_transmit_signal(char *buff){
	if(*buff)
		usart_write(2,*buff);
	print_string("\r\n");
	    buff++;
}
