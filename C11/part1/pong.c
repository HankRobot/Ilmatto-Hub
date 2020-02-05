#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

rectangle yellow;

int main()
{
    init_lcd();
    display_string("Hello World");
    return 0;
}