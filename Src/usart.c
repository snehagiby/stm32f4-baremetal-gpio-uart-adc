/*
 * usart.c
 *
 *  Created on: Sep 24, 2026
 *      Author: Admin
 */
#include <usart.h>

#define SR_TXE (1U << 7)
#define SR_RXNE (1U << 5)

#define CR1_UE	(1U << 13)
#define CR1_RE	(1U << 2)
#define CR1_TE	(1U << 3)

#define RCC_APB2_UARST1		(1U << 4)
#define RCC_APB1_UARST2		(1U << 17)
#define RCC_APB1_UARST3		(1U << 18)
#define RCC_APB1_UARST4		(1U << 19)
#define RCC_APB1_UARST5		(1U << 20)
#define RCC_APB2_UARST6		(1U << 5)

#define SYS_CLK 			(16000000)
#define PERIPHERAL_CLOCK 	SYS_CLK
#define DEFAULT_BAUD_RATE	115200
/**
 * allow clock access to usart peripheral.
 * set usart alternate function in gpio.c.
 * configure baudrate.
 * enable tx and rx transfer function in ctrl.
 * enable usart module.
 */
void usart_init(uint8_t inst){
	switch(inst){
	case 1:
		RCC_APB2ENR |= RCC_APB2_UARST1;
		gpio_init('A',9,GPIO_AF);    //PA9-TX
		gpio_init('A',10,GPIO_AF);   //PA10-RX
		//PA9,PA10-AF7
		GPIO_AFRH(A) |= (7 << (9-8)*4) ;
		GPIO_AFRH(A) |= (7 << (10-8)*4) ;

		usart_set_baudrate(1,PERIPHERAL_CLOCK, DEFAULT_BAUD_RATE);
			USART_CR1(1) |= CR1_RE;
			USART_CR1(1) |= CR1_TE;
			USART_CR1(1) |= CR1_UE;
		break;
	case 2:
		RCC_APB1ENR |= RCC_APB1_UARST2;
		gpio_init('A',2,GPIO_AF);   //PA2 - TX
		gpio_init('A',3,GPIO_AF);   //PA3 -RX
		//PA2,PA3-AF7
		GPIO_AFRL(A) |= (7 << 2*4);
		GPIO_AFRL(A) |= (7 << 3*4);

		usart_set_baudrate(2,PERIPHERAL_CLOCK, DEFAULT_BAUD_RATE);
			USART_CR1(2) |= CR1_RE;
			USART_CR1(2) |= CR1_TE;
			USART_CR1(2) |= CR1_UE;
		break;

	case 3:
		RCC_APB1ENR |= RCC_APB1_UARST3;
		gpio_init('B',10,GPIO_AF);   //PB10-TX
		gpio_init('B',11,GPIO_AF);   //PB11-RX
		//PB10,PB11 - AF7
		GPIO_AFRH(B) |= (7 << (10-8)*4);
		GPIO_AFRH(B) |= (7 << (11-8)*4);

		usart_set_baudrate(3,PERIPHERAL_CLOCK, DEFAULT_BAUD_RATE);
			USART_CR1(3) |= CR1_RE;
			USART_CR1(3) |= CR1_TE;
			USART_CR1(3) |= CR1_UE;
		break;

	case 4:
		RCC_APB1ENR |= RCC_APB1_UARST4;
		gpio_init('A',0,GPIO_AF);   //PA0 -TX
		gpio_init('A',1,GPIO_AF);   //PA1 -RX
		//PA0,PA1 - AF8
		GPIO_AFRL(A) |= (8 << 0*4);
		GPIO_AFRL(A) |= (8 << 1*4);

		usart_set_baudrate(4,PERIPHERAL_CLOCK, DEFAULT_BAUD_RATE);
			USART_CR1(4) |= CR1_RE;
			USART_CR1(4) |= CR1_TE;
			USART_CR1(4) |= CR1_UE;
		break;

	case 5:
		RCC_APB1ENR |= RCC_APB1_UARST5;
		gpio_init('C',12,GPIO_AF);   //PC12-TX
		gpio_init('D',2,GPIO_AF);   //PD2-RX
		// PD2,PC12 - AF8
		GPIO_AFRH(C) |= (8 << (12-8)*4);
		GPIO_AFRL(D) |= (8 << 2*4);

		usart_set_baudrate(5,PERIPHERAL_CLOCK, DEFAULT_BAUD_RATE);
			USART_CR1(5) |= CR1_RE;
			USART_CR1(5) |= CR1_TE;
			USART_CR1(5) |= CR1_UE;
		break;

	case 6:
		RCC_APB2ENR |= RCC_APB2_UARST6;
		gpio_init('G',14,GPIO_AF);   //PG14 - TX
		gpio_init('G',9,GPIO_AF);   //PG9 -RX
		//PG9,PG14 - AF8
		GPIO_AFRH(G) |= (8 << (14-8)*4);
		GPIO_AFRH(G) |= (8 << (9-8)*4);

		usart_set_baudrate(6,PERIPHERAL_CLOCK, DEFAULT_BAUD_RATE);
			USART_CR1(6) |= CR1_RE;
			USART_CR1(6) |= CR1_TE;
			USART_CR1(6) |= CR1_UE;
		break;
	}

}
void usart_write(uint8_t inst,char val){
   switch(inst){
   case 1:
	  while(!(USART_SR(1) & SR_TXE));
	  USART_DR(1) = val & 0xFF;
	   break;
   case 2:
	   while(!(USART_SR(2) & SR_TXE));
	   USART_DR(2) = val & 0xFF;
	   break;
   case 3:
	   while(!(USART_SR(3) & SR_TXE));
	   USART_DR(3) = val & 0xFF;
	   break;
   case 4:
	   while(!(USART_SR(4) & SR_TXE));
	   USART_DR(4) = val & 0xFF;
	   break;
   case 5:
	   while(!(USART_SR(5) & SR_TXE));
	   USART_DR(5) = val & 0xFF;
	   break;
   case 6:
	   while(!(USART_SR(6) & SR_TXE));
	   USART_DR(6) = val & 0xFF;
	   break;
   }
}
char usart_read(uint8_t inst){
	uint8_t rec_data;
	switch(inst){
	   case 1:
		  while(!(USART_SR(1) & SR_RXNE));
		  rec_data = USART_DR(1);
		   break;
	   case 2:
		   while(!(USART_SR(2) & SR_RXNE));
		   rec_data = USART_DR(2);
		   break;
	   case 3:
		   while(!(USART_SR(3) & SR_RXNE));
		   rec_data = USART_DR(3);
		   break;
	   case 4:
		   while(!(USART_SR(4) & SR_RXNE));
		   rec_data = USART_DR(4);
		   break;
	   case 5:
		   while(!(USART_SR(5) & SR_RXNE));
		   rec_data = USART_DR(5);
		   break;
	   case 6:
		   while(!(USART_SR(6) & SR_RXNE));
		   rec_data = USART_DR(6);
		   break;
	   }
	return rec_data;
}
void usart_set_baudrate(unsigned inst,uint32_t peripheral_clock,uint32_t baudrate){
	switch(inst){
	case 1:
		USART_BRR(1) = (peripheral_clock + baudrate/2U)/baudrate;
		break;
	case 2:
		USART_BRR(2) = (peripheral_clock + baudrate/2U)/baudrate;
		break;
	case 3:
		USART_BRR(3) = (peripheral_clock + baudrate/2U)/baudrate;
		break;
	case 4:
		USART_BRR(4) = (peripheral_clock + baudrate/2U)/baudrate;
		break;
	case 5:
		USART_BRR(5) = (peripheral_clock + baudrate/2U)/baudrate;
		break;
	case 6:
		USART_BRR(6) = (peripheral_clock + baudrate/2U)/baudrate;
		break;
	}

}

void print_string(char *ptr){
while(*ptr){
	usart_write(2,*ptr);
	ptr++;
}
}
