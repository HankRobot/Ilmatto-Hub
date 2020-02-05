#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "debug.h"

volatile uint8_t value;


ISR(INT0_vect)   //falling edge decrement pin 2
{
    if(value>0)
    {
        value--;
    }
}

ISR(INT1_vect)   //falling edge increment pin 3
{
    if(value<255)
    {
        value++;
    }
}

ISR(ADC_vect) 
{
	PINB |= _BV(PB7); //toggle led
}

ISR(TIMER0_COMPA_vect) //when timer exceeds value,trigger ADC's auto trigger
{
    OCR0A = value;
}

void init_adc(void)
{
	ADCSRA |= _BV(ADATE) | _BV(ADEN) | _BV(ADIE);
	ADCSRB |= _BV(ADTS1) | _BV(ADTS0); //auto triggering enabled
}

void init_timer0(void)
{
     /* Timer 0 CTC Mode 4 */
    TCCR0A |= _BV(WGM01);
    /* Prescaler /1024 */
    TCCR0B |= _BV(CS00);
    /* Enable interrupt */
    TIMSK0 |= _BV(OCIE0A);
}

void init_extinterrupts(void)
{
	/* Set to trigger on falling edge */
    EICRA |= _BV(ISC01) | _BV(ISC11); //falling edge on INT0 and INT1

    /* Enable interrupt */
    EIMSK |= _BV(INT0) | _BV(INT1);
}

int main( void )
{
    DDRB |= _BV(PB7);
    PORTB &= ~_BV(PB7);

    DDRA = 0x00;
    init_debug_uart0();
    
    init_timer0();
    init_adc();
    
    init_extinterrupts();
    sei();
    while (1)
    {
        PORTA = value;
        printf("%i\n",value);
    }
}