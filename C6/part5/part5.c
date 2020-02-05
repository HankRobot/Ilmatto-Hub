/*Encoder Reading to change segment display with buzzer
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
    uint8_t i;
    uint8_t aState;
    uint8_t aLastState;
    /* Set all Port C and Port B bits as inputs and Port A bits as outputs */
    // PC1 is A, PC0 is B
    aLastState = (PINC & _BV(PC1));        //reads last state
    while(1){
        aState = (PINC & _BV(PC1));        //reads again
        if (aState != aLastState){         //if there is a change in value
            if ((PINC & _BV(PC0))!=aState){  //if B state and A state are not the same
                i++;   //clockwise
                aLastState = aState;
                PORTA |= _BV(PINA0);
                _delay_ms(100);
            }
            else{                          //if B state and A state are the same
                i--;   //anticlockwise
                aLastState = aState;
                PORTA |= _BV(PINA0);
                _delay_ms(100);
            }
            if(i>10){
                i = 0;
            }
        }
        PORTA = segments[i];
        PORTA &= ~_BV(PINA0);
        aLastState = aState;
    }
}
