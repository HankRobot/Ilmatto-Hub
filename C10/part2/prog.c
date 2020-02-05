/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License. 
 *           View this license at http://creativecommons.org/about/licenses/
 *   Notes: F_CPU must be defined to match the clock frequency
 */
#include <avr/io.h>
//#include <util/delay.h>
//#include "debug.h"
#include <avr/interrupt.h>

//volatile uint16_t result;
//volatile double voltage;

ISR(ADC_vect) 
{
	
	PINB |= _BV(PB7);
	//printf("on\n");
	/*
	result = ADC;
	voltage = (result / 1024.0) * 3.3; 
	printf("%4d : %6.5fV\n", result,voltage);
	
	
	if(voltage<0.2)
	{
		PORTB |= _BV(PB7); 
		
	}
	else
	{
		PORTB &= ~_BV(PB7); 
	}
	*/
	
}

void init_adc(void)
{
	/* AREF reference, channel 0, right shift result */
	ADMUX = 0x00;
	/* Free-running mode and enable ADC */
	ADCSRA |= _BV(ADATE) | _BV(ADEN) | _BV(ADIE);
	ADCSRB = 0x00;
	/* Enable Interrupts */
	sei();
	/* Start Conversions */
	ADCSRA |= _BV(ADSC);
}

int main(void)
{
	
	DDRB |= _BV(PB7);/* enable green LED */

	//init_debug_uart0();
	init_adc();
	
	while (1) 
	{
		/* TODO: Measurement code */
		
	}
}
