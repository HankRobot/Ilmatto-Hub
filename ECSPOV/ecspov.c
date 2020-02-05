/*
 *  ecspov.c
 *
 *  Created by Steve Gunn on 10/07/2013.
 *  University of Southampton.
 *  Copyright 2013. All rights reserved.
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "font5x7.h"

const char message[] = "Hank";
const uint8_t strip_delay = 1;
const uint8_t msg_delay = 20;

void delay_ms(uint16_t m)
{
	uint16_t i;
	for(i=0; i<m; i++) _delay_ms(1);
}

int main(void)
{
	PGM_P fdata;

	DDRA = 0xFF;
	PORTA = 0x00;
	uint8_t c;
	uint8_t p;

	for(;;) 
	{
		delay_ms(msg_delay);
		
		for(c=0; c<strlen(message); c++) {
			fdata = font5x7 + (message[c] - ' ')*5;
			for(p=0; p<5; p++) {
				PORTA = pgm_read_byte(fdata++);
				delay_ms(strip_delay);
			}
			PORTA = 0x00;
			delay_ms(strip_delay);
		}
	}
	return (0);
}


