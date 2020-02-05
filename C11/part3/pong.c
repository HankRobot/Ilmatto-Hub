#include <avr/io.h>
#include <util/delay.h>

#include "debug.h"
#include "lcd.h"

rectangle yellow;
rectangle black;
int16_t xspeed = 1;
int16_t yspeed = 1;

uint16_t x0;
uint16_t x1;
uint16_t y0;
uint16_t y1;

move_rect()
{
    fill_rectangle(yellow,BLACK);
    yellow.left += xspeed;
    yellow.right += xspeed;
    yellow.top += yspeed;
    yellow.bottom += yspeed;
    fill_rectangle(yellow,YELLOW);
    _delay_ms(4);
    if (yellow.right>=240){
        clear_screen();
        yellow.left = 240-5;
        yellow.right = 240;
        fill_rectangle(yellow,YELLOW);
        xspeed *= -1;
    }
    if (yellow.left<=0){
        clear_screen();
        yellow.left = 0;
        yellow.right = 5;
        fill_rectangle(yellow,YELLOW);
        xspeed *= -1;
    }
    if (yellow.top<=0){
        clear_screen();
        yellow.top = 0;
        yellow.bottom = 5;
        fill_rectangle(yellow,YELLOW);
        yspeed *= -1;
    }
    if (yellow.bottom>=320){
        clear_screen();
        yellow.top = 320-5;
        yellow.bottom = 320;
        fill_rectangle(yellow,YELLOW);
        yspeed *= -1;
    }
}

int main(){
    init_lcd();
    yellow.left = (240-5)/2;
    yellow.right = (240+5)/2;
    yellow.top = (320-5)/2;
    yellow.bottom = (320+5)/2;

    fill_rectangle(yellow,YELLOW);

    while(1)
    {
        move_rect();
        _delay_ms(100);
    }
    return 0;
}