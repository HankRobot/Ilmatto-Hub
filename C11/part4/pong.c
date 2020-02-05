#include <avr/io.h>
#include <util/delay.h>

#include "debug.h"
#include "lcd.h"

rectangle yellowdot;
rectangle blackdot;

rectangle greenbar;
rectangle blackbar;

int16_t xspeed = 1;
int16_t yspeed = 1;

uint16_t x0;
uint16_t x1;
uint16_t y0;
uint16_t y1;

uint8_t i = 20; //speed of shifting green rectangle
uint8_t a1;
uint8_t a0;
uint8_t b1;
uint8_t b0;

move_dot()
{
    fill_rectangle(yellowdot,BLACK);
    fill_rectangle(greenbar,GREEN);
    yellowdot.left += xspeed;
    yellowdot.right += xspeed;
    yellowdot.top += yspeed;
    yellowdot.bottom += yspeed;
    fill_rectangle(yellowdot,YELLOW);
    _delay_ms(4);
    if (yellowdot.right>=240){
        fill_rectangle(yellowdot,BLACK);
        fill_rectangle(greenbar,GREEN);
        yellowdot.left = 240-5;
        yellowdot.right = 240;
        fill_rectangle(yellowdot,YELLOW);
        xspeed *= -1;
    }
    if (yellowdot.left<=0){
        fill_rectangle(yellowdot,BLACK);
        fill_rectangle(greenbar,GREEN);
        yellowdot.left = 0;
        yellowdot.right = 5;
        fill_rectangle(yellowdot,YELLOW);
        xspeed *= -1;
    }
    if (yellowdot.top<=0){
        fill_rectangle(yellowdot,BLACK);
        fill_rectangle(greenbar,GREEN);
        yellowdot.top = 0;
        yellowdot.bottom = 5;
        fill_rectangle(yellowdot,YELLOW);
        yspeed *= -1;
    }
    if (yellowdot.bottom>=320){
        fill_rectangle(yellowdot,BLACK);
        fill_rectangle(greenbar,GREEN);
        yellowdot.top = 320-5;
        yellowdot.bottom = 320;
        fill_rectangle(yellowdot,YELLOW);
        yspeed *= -1;
    }
}

encoder_setup()
{
    DDRB = 0b00000000;
    PORTB = 0xFF;
    
    /* Set all Port C bits as inputs and Port A bits as outputs */
    // PC1 is A, PC0 is B
    a0 = (PINB & _BV(PB1));        //reads A last state
    b0 = (PINB & _BV(PB0));        //reads B last state
}

encoder(){
    a1 = (PINB & _BV(PB1));        //reads again
    b1 = (PINB& _BV(PB0));
    if (1)          //if there is a change in value
    {         
        if ((a0==0 && a1==1) && (b0==0 && b1==0)) //if B state and A state are not the same (PINC & _BV(PC0))!=a1
        {  
            //clockwise
            if(greenbar.right<240)
            {
                fill_rectangle(greenbar,BLACK);
                greenbar.left += i;
                greenbar.right += i;
                fill_rectangle(greenbar,GREEN);
            }
            else{
                fill_rectangle(greenbar,BLACK);
                greenbar.left = 240-50;
                greenbar.right = 240;
                fill_rectangle(greenbar,GREEN);
            }
        }
        else if ((a0==1 && a1==1) && (b0==0 && b1==1))
        {
            //clockwise
            if(greenbar.right<240)
            {
                fill_rectangle(greenbar,BLACK);
                greenbar.left += i;
                greenbar.right += i;
                fill_rectangle(greenbar,GREEN);
            }
            else{
                fill_rectangle(greenbar,BLACK);
                greenbar.left = 240-50;
                greenbar.right = 240;
                fill_rectangle(greenbar,GREEN);
            }
        }
        else if ((a0==1 && a1==0) && (b0==1 && b1==1))
        {
            //clockwise
            if(greenbar.right<240)
            {
                fill_rectangle(greenbar,BLACK);
                greenbar.left += i;
                greenbar.right += i;
                fill_rectangle(greenbar,GREEN);
            }
            else{
                fill_rectangle(greenbar,BLACK);
                greenbar.left = 240-50;
                greenbar.right = 240;
                fill_rectangle(greenbar,GREEN);
            }
        }
        else if ((a0==0 && a1==0) && (b0==1 && b1==0))
        {
            //clockwise
            if(greenbar.right<240)
            {
                fill_rectangle(greenbar,BLACK);
                greenbar.left += i;
                greenbar.right += i;
                fill_rectangle(greenbar,GREEN);
            }
            else{
                fill_rectangle(greenbar,BLACK);
                greenbar.left = 240-50;
                greenbar.right = 240;
                fill_rectangle(greenbar,GREEN);
            }
        }
        else if ((a0==1 && a1==0) && (b0==0 && b1==0)) //if B state and A state are the same (PINC & _BV(PC0))==a1
        {   
            //anticlockwise
            if(greenbar.left>50)
            {
                fill_rectangle(greenbar,BLACK);
                greenbar.left -= i;
                greenbar.right -= i;
                fill_rectangle(greenbar,GREEN);
            }
            else{
                fill_rectangle(greenbar,BLACK);
                greenbar.left = 0;
                greenbar.right = 50;
                fill_rectangle(greenbar,GREEN);
            }
        }
        else if ((a0==0 && a1==0) && (b0==0 && b1==1))
        {
            //anticlockwise
            if(greenbar.left>50)
            {
                fill_rectangle(greenbar,BLACK);
                greenbar.left -= i;
                greenbar.right -= i;
                fill_rectangle(greenbar,GREEN);
            }
            else{
                fill_rectangle(greenbar,BLACK);
                greenbar.left = 0;
                greenbar.right = 50;
                fill_rectangle(greenbar,GREEN);
            }
        }
        else if ((a0==0 && a1==1) && (b0==1 && b1==1))
        {
            //anticlockwise
            if(greenbar.left>50)
            {
                fill_rectangle(greenbar,BLACK);
                greenbar.left -= i;
                greenbar.right -= i;
                fill_rectangle(greenbar,GREEN);
            }
            else{
                fill_rectangle(greenbar,BLACK);
                greenbar.left = 0;
                greenbar.right = 50;
                fill_rectangle(greenbar,GREEN);
            }
        }
        else if ((a0==1 && a1==1) && (b0==1 && b1==0))
        {
            //anticlockwise
            if(greenbar.left>50)
            {
                fill_rectangle(greenbar,BLACK);
                greenbar.left -= i;
                greenbar.right -= i;
                fill_rectangle(greenbar,GREEN);
            }
            else{
                fill_rectangle(greenbar,BLACK);
                greenbar.left = 0;
                greenbar.right = 50;
                fill_rectangle(greenbar,GREEN);
            }
        }
    }
    a0 = a1;
    b0 = b1;
}

int main(){
    encoder_setup();
    init_lcd();

    yellowdot.left = (240-5)/2;
    yellowdot.right = (240+5)/2;
    yellowdot.top = (320-5)/2;
    yellowdot.bottom = (320+5)/2;
    fill_rectangle(yellowdot,YELLOW);

    greenbar.left = (240-50)/2;
    greenbar.right = (240+50)/2;
    greenbar.top = 0;
    greenbar.bottom = 3;
    fill_rectangle(greenbar,GREEN);

    while(1)
    {
        encoder();
        move_dot();
        _delay_ms(100);
    }
    return 0;
}