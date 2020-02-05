/*7 Segment Clock Display
 By Chia Tze Hank
 EEE Year 1 2019
*/
#include <avr/io.h>
#include <util/delay.h>

uint8_t segments[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE4,0xFE,0xF6};

int main()
{
    DDRA = 0b11111111;
    uint8_t i;
    /* Set all Port A bits as outputs */
    while(1)
    {
        for(i=0;i<10;i++) 
        {
            PORTA = segments[i];
            _delay_ms(1000);
        }
    }
}