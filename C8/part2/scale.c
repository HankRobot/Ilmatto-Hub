/*  Author: Klaus-Peter Zauner
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *          View this license at http://creativecommons.org/about/licenses/
 *   Notes: F_CPU must be defined to match the clock frequency
 */

/*
3 | Signal | Port | Pin |
4 |----------+------+-----|
5 | Tone Osc | D | 5 |
6 */

#include <avr/io.h>
#include <util/delay.h>
#include "et_scale.h"
//#define FREQ 4000

#define TONE_FREQ 262
#define TONE_PRESCALER 8UL

unsigned long toneClock;   /* set at timer initialisation and used
                              to calculate TOP when setting frequency */ 

void init_tone(void);
void tone(uint16_t frequency);

int main(void) {

    init_tone();
    
    uint8_t n;
    for (;;) 
    {
    	for(n=0;n<74;n++)
        {
    	tone(et_scale[n]);
    	_delay_ms(100);
    	}
    	for(n=74;n>0;n--)
        {
    	   tone(et_scale[n]);
    	   _delay_ms(100);
    	}
    	
    }

}

/* init_tone ---
   Setup timer as a tone frequency oscillator.
*/
void init_tone(void)
{
    DDRD |= _BV(PD5); /* enable ouput driver for OC1A */
    TCCR1A = _BV(COM1A0) | _BV(WGM10);/* toggle OC1A on match */
     /* frequency (f) correct PWM, */
    TCCR1B = _BV(WGM13) | _BV(CS11); /* varying f with OCR1A */
     /* prescaler set to 8 */
}

/* tone ---
   Set oscillator output to desired frequency
*/
void tone(uint16_t frequency)
{
    OCR1A = (uint16_t) (F_CPU/(2*2*TONE_PRESCALER)/frequency);
}


