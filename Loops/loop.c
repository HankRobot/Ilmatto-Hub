#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
    DDRD = 0xFF;
	PORTA = 0x00;
    PORTD = 0x00;
	uint8_t i;
    int delay = 100;
    
	for(;;) 
	{
        if (delay<5)
        {
            delay = 100;
        }
        else
        {
            delay -= 15;
        }
        
        
		for(i=0; i<8; i++) {
			PORTA |=  _BV(i);
            PORTD |=  _BV(i);
			_delay_ms(delay);
            PORTA = 0x00;
            PORTD = 0x00;
		}
        for(i=6; i>0; i--) {
			PORTA |=  _BV(i);
            PORTD |=  _BV(i);
			_delay_ms(delay);
            PORTA = 0x00;
            PORTD = 0x00;
		}
	}
    
	return (0);
}