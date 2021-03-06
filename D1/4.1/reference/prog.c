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

int main( void )
{
    DDRB |= _BV(PB7);
    PORTB &= ~_BV(PB7);

    DDRA = 0x00;
    init_debug_uart0();

    /* Set to trigger on falling edge */
    EICRA |= _BV(ISC01) | _BV(ISC11); //falling edge on INT0 and INT1

    /* Enable interrupt */
    EIMSK |= _BV(INT0) | _BV(INT1);
    sei();

    while (1)
    {
        PORTA = value;
        printf("%i\n",value);
        _delay_ms(100);
    }
}