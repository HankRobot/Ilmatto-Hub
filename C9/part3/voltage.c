/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License. 
 *           View this license at http://creativecommons.org/about/licenses/
 *   Notes: F_CPU must be defined to match the clock frequency
 */
#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"

void init_adc(void)
{
	/* TODO: Initialisation code */	
	ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADEN); /* F_ADC = F_CPU/64 ,enable single conversion */
	ADMUX = 0; /* Select channel 0 */
}

uint16_t read_adc(void)
{
	/* TODO: Acquisition code */ 
	ADCSRA |= _BV(ADSC);  // Start conversion 
	loop_until_bit_is_clear(ADCSRA, ADSC); //loop until adsc conversion is complete
	return ADC;  //ADCSH and ADCL
}

void channel_adc(uint8_t n)
{
	ADMUX = n;
}

int main(void)
{
	uint16_t result;
	double voltage;
	DDRB |= _BV(PB7); /* enable green LED */

	init_debug_uart0();
	init_adc();
	channel_adc(2); //switch to channel 2

	double BPM = 0;
	uint16_t count = 0;
	uint8_t FLAG = 0;

	for (;;) 
	{
		/* TODO: Measurement code */
		result = read_adc();
		voltage = (result / 1024.0) * 3.3; 
		printf("%4d : %6.5fV , %4lf BPM\n", result, voltage, BPM);

		if(voltage>0.4 && FLAG ==0)
		{
			BPM = 1 / (count * 0.1 /60);
			count = 0;
			FLAG = 1;
			PORTB |= _BV(PB7); /* turn on LED */
		}
		if(voltage<0.2)
		{
			FLAG = 0;
			PORTB &= ~_BV(PB7); /* turn off LED */
		}
		count ++;
		_delay_ms(100);
	}
}
