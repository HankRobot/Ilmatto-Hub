#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

rectangle yellow;

int main()
{
    init_lcd();
    display_string("Hello World");
    
    yellow.left = (240-100)/2;
    yellow.right = (240+100)/2;
    yellow.top = (320-200)/2;
    yellow.bottom = (320+200)/2;
    fill_rectangle(yellow,YELLOW);
    return 0;
}