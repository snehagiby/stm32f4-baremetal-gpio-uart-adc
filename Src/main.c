
#include "gpio.h"
#include "usart.h"
#include "adc.h"

int state = OFF;
char buffer[10];
int main(void)
{
	gpio_init('A',5,GPIO_OUTPUR);
	gpio_init('C',13,GPIO_INPUT);
	usart_init(2);
	adc_init();
	 adc_conversion();
    /* Loop forever */
	for(;;){
		program_state_set(&state);
		progrm_state_led(&state);
		//print_string("\r\n Enter data here:");
		led_delay();
		adc_sample_signal(buffer,&state);
	}
}
