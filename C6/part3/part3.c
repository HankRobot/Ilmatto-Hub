/*Debouncing Solution
 By Chia Tze Hank
 EEE Year 1 2019
*/
#include <avr/io.h>
#include <util/delay.h>

uint8_t segments[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE4,0xFE,0xF6};

int main()
{
    DDRC = 0b00000000;
    DDRA = 0b11111111;
    uint8_t i = 0;
    /* Set all Port C bits as inputs and Port A bits as outputs */
    while(1)
    {
        while ((PINC & _BV(PC6)) == 0);
            _delay_ms(100);
            i++; /* Increment count */
            if(i>9)
            {
                i = 0;
            }
        /* Wait for switch to be released */
        while ((PINC & _BV(PC6)) != 0);
            PORTA = segments[i];
    }
}