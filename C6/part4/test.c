/*Encoder Reading to change segment display
 By Chia Tze Hank
 EEE Year 1 2019
*/
#include <avr/io.h>
#include <util/delay.h>

uint8_t segments[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE4,0xFE,0xF6};

int main()
{
    DDRC = 0b00000000;
    PORTC = 0xFF;
    DDRA = 0b11111111;
    uint8_t i;
    uint8_t a1;
    uint8_t a0;
    uint8_t b1;
    uint8_t b0;
    /* Set all Port C bits as inputs and Port A bits as outputs */
    // PC1 is A, PC0 is B
    a0 = (PINC & _BV(PC1));        //reads A last state
    b0 = (PINC & _BV(PC0));        //reads B last state
    while(1)
    {
        a1 = (PINC & _BV(PC1));        //reads again
        b1 = (PINC & _BV(PC0));
        if (1)          //if there is a change in value
        {         
            if ((a0==0 && a1==1) && (b0==0 && b1==0)) //if B state and A state are not the same (PINC & _BV(PC0))!=a1
            {  
                i++;   //clockwise
                if(i>9)
                {
                    i = 0;
                }
            }
            else if ((a0==1 && a1==1) && (b0==0 && b1==1))
            {
                i++;
                if(i>9)
                {
                    i = 0;
                }
            }
            else if ((a0==1 && a1==0) && (b0==1 && b1==1))
            {
                i++;
                if(i>9)
                {
                    i = 0;
                }
            }
            else if ((a0==0 && a1==0) && (b0==1 && b1==0))
            {
                i++;
                if(i>9)
                {
                    i = 0;
                }
            }
            else if ((a0==1 && a1==0) && (b0==0 && b1==0)) //if B state and A state are the same (PINC & _BV(PC0))==a1
            {   
                i--;   //anticlockwise
                if(i<0)
                {
                    i = 9;
                }
            }
            else if ((a0==0 && a1==0) && (b0==0 && b1==1))
            {
                i--;
                if(i<0)
                {
                    i = 9;
                }
            }
            else if ((a0==0 && a1==1) && (b0==1 && b1==1))
            {
                i--;
                if(i<0)
                {
                    i = 9;
                }
            }
            else if ((a0==1 && a1==1) && (b0==1 && b1==0))
            {
                i--;
                if(i<0)
                {
                    i = 9;
                }
            }
        }
        PORTA = segments[i];
        a0 = a1;
        b0 = b1;
    }
}