/*
 * C7.c
 *
 *  Created on: 22 Nov 2017
 *      Author: xhf1a15
 */

#include <assert.h>
#include <stdio.h>
#include <avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include"debug.h"

uint8_t segments[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE4,0xFE,0xF6};
uint8_t n=0;

int main(void) 
{
	DDRA = 0xFF;
	char ch;
	init_debug_uart0();

	for(;;)
	{
		PORTA = segments[n];
		printf("%i",n);
		n++;
		if(n>=10)
		{
			_delay_ms(500);
			fprintf(stderr,"Count overflow\n\r");
			ch = ugetchar0(stdin);
			if(ch>0)
			{
				ch = 0;
				n=0;
			}
		}
		_delay_ms(500);
	}
}
