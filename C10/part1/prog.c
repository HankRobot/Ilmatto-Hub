/*7 Segment Clock Display
 By Chia Tze Hank
 EEE Year 1 2019
*/
#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"
#include <avr/interrupt.h>

uint8_t segments[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE4,0xFE,0xF6};
volatile uint8_t i;

ISR(TIMER1_COMPA_vect)
{
    /* Toggle LED on PB7 and print to debug */
    //PINB |= _BV(PB7);
    //printf("%i\n",i);
    i = (i==9) ? 0 : i+1;
}

int main()
{
    DDRB |= _BV(PB7);
	init_debug_uart0();
    DDRA = 0b11111111;
    

    /* Timer 1 CTC Mode 4 */
    TCCR1A = 0;
    TCCR1B = _BV(WGM12);
    /* Prescaler /1024 */
    TCCR1B |= _BV(CS12) | _BV(CS10);
    /* Set timeout at 1000ms */
    OCR1A = 5859 * 2;
    /* Enable interrupt */
    TIMSK1 |= _BV(OCIE1A);
    sei();

    /* Set all Port A bits as outputs */
    while(1)
    {
        PORTA = segments[i];
    }
}