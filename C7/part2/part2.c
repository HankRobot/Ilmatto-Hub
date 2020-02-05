#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"
#include "digitalPot.h"
#include "debug.h"

int main()
{
    uint8_t i = 0;
    init_pot();
    setXpot(0);
    setYpot(0);

    while(1)
    {
        for(i=0;i<255;i++) 
        {
            incXpot();
            incYpot();
        }
        setXpot(0);
        setYpot(0);
    }
}