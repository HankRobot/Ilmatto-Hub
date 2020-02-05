#include <avr/io.h>
#include <util/delay.h>

#include "debug.h"
#include "lcd.h"

rectangle yellowdot;
rectangle blackdot;

rectangle yellowdot0;
rectangle blackdot0;
rectangle yellowdot1;
rectangle blackdot1;
rectangle yellowdot2;
rectangle blackdot2;
rectangle yellowdot3;
rectangle blackdot3;

int16_t xspeed = 1;
int16_t yspeed = 1;

uint16_t x0;
uint16_t x1;
uint16_t y0;
uint16_t y1;

//player 1
uint8_t i = 40; //speed of shifting green rectangle
uint8_t a1;
uint8_t a0;
uint8_t b1;
uint8_t b0;
rectangle greenbar;
rectangle blackbar;

//player 2
uint8_t a3;
uint8_t a2;
uint8_t b3;
uint8_t b2;
rectangle greenbar0;
rectangle blackbar0;

uint8_t gamestate = 1;

uint8_t move_dot()
{
    fill_rectangle(yellowdot,BLACK);
    fill_rectangle(greenbar,GREEN);
    fill_rectangle(greenbar0,GREEN);
    yellowdot.left += xspeed;
    yellowdot.right += xspeed;
    yellowdot.top += yspeed;
    yellowdot.bottom += yspeed;
    createball();
    _delay_ms(4);   //delay for the ball
    if (yellowdot.right>=240){
        fill_rectangle(yellowdot,BLACK);
        fill_rectangle(greenbar,GREEN);
        fill_rectangle(greenbar0,GREEN);
        yellowdot.left = 240-5;
        yellowdot.right = 240;
        createball();
        xspeed *= -1;
    }
    if (yellowdot.left<=0){
        fill_rectangle(yellowdot,BLACK);
        fill_rectangle(greenbar,GREEN);
        fill_rectangle(greenbar0,GREEN);
        yellowdot.left = 0;
        yellowdot.right = 5;
        createball();
        xspeed *= -1;
    }
    if (yellowdot.top<=0){ 
        return 0;
    }
    if (yellowdot.bottom>=320){
        return 0;
    }

    //state for greenbar if ball hits
    if (yellowdot.top<=greenbar.bottom && yellowdot.left>=greenbar.left && yellowdot.right<=greenbar.right){ 
        fill_rectangle(yellowdot,BLACK);
        fill_rectangle(greenbar,GREEN);
        fill_rectangle(greenbar0,GREEN);
        yellowdot.top = greenbar.bottom;
        yellowdot.bottom = greenbar.bottom + 5;
        createball();
        yspeed *= -1;
    }

    //state for greenbar0 if ball hits
    if (yellowdot.bottom>=greenbar0.top && yellowdot.left>=greenbar0.left && yellowdot.right<=greenbar0.right){ 
        fill_rectangle(yellowdot,BLACK);
        fill_rectangle(greenbar,GREEN);
        fill_rectangle(greenbar0,GREEN);
        yellowdot.top = greenbar0.top -5;
        yellowdot.bottom = greenbar0.top;
        createball();
        yspeed *= -1;
    }
}

encoder_setup()
{
    DDRB = 0b00000000;
    PORTB = 0xFF;
    DDRD = 0b00000000;
    PORTD = 0xFF;
    /* Set all Port C bits as inputs and Port A bits as outputs */
    // PC1 is A, PC0 is B
    a0 = (PINB & _BV(PB1));        //reads A last state
    b0 = (PINB & _BV(PB0));        //reads B last state
    a2 = (PIND & _BV(PD1));        //reads A last state
    b2 = (PIND & _BV(PD0));        //reads B last state
}

encoder(){
    a1 = (PINB & _BV(PB1));        //reads again
    b1 = (PINB & _BV(PB0));
    a3 = (PIND & _BV(PD1));        //reads again
    b3 = (PIND & _BV(PD0));
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

    if (1)          //if there is a change in value
    {         
        if ((a2==0 && a3==1) && (b2==0 && b3==0)) //if B state and A state are not the same (PINC & _BV(PC0))!=a1
        {  
            //clockwise
            if(greenbar0.right<240)
            {
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left += i;
                greenbar0.right += i;
                fill_rectangle(greenbar0,GREEN);
            }
            else{
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left = 240-50;
                greenbar0.right = 240;
                fill_rectangle(greenbar0,GREEN);
            }
        }
        else if ((a2==1 && a3==1) && (b2==0 && b3==1))
        {
            //clockwise
            if(greenbar0.right<240)
            {
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left += i;
                greenbar0.right += i;
                fill_rectangle(greenbar0,GREEN);
            }
            else{
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left = 240-50;
                greenbar0.right = 240;
                fill_rectangle(greenbar0,GREEN);
            }
        }
        else if ((a2==1 && a3==0) && (b2==1 && b3==1))
        {
            //clockwise
            if(greenbar0.right<240)
            {
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left += i;
                greenbar0.right += i;
                fill_rectangle(greenbar0,GREEN);
            }
            else{
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left = 240-50;
                greenbar0.right = 240;
                fill_rectangle(greenbar0,GREEN);
            }
        }
        else if ((a2==0 && a3==0) && (b2==1 && b3==0))
        {
            //clockwise
            if(greenbar0.right<240)
            {
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left += i;
                greenbar0.right += i;
                fill_rectangle(greenbar0,GREEN);
            }
            else{
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left = 240-50;
                greenbar0.right = 240;
                fill_rectangle(greenbar0,GREEN);
            }
        }
        else if ((a2==1 && a3==0) && (b2==0 && b3==0)) //if B state and A state are the same (PINC & _BV(PC0))==a1
        {   
            //anticlockwise
            if(greenbar0.left>50)
            {
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left -= i;
                greenbar0.right -= i;
                fill_rectangle(greenbar0,GREEN);
            }
            else{
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left = 0;
                greenbar0.right = 50;
                fill_rectangle(greenbar0,GREEN);
            }
        }
        else if ((a2==0 && a3==0) && (b2==0 && b3==1))
        {
            //anticlockwise
            if(greenbar0.left>50)
            {
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left -= i;
                greenbar0.right -= i;
                fill_rectangle(greenbar0,GREEN);
            }
            else{
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left = 0;
                greenbar0.right = 50;
                fill_rectangle(greenbar0,GREEN);
            }
        }
        else if ((a2==0 && a3==1) && (b2==1 && b3==1))
        {
            //anticlockwise
            if(greenbar0.left>50)
            {
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left -= i;
                greenbar0.right -= i;
                fill_rectangle(greenbar0,GREEN);
            }
            else{
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left = 0;
                greenbar0.right = 50;
                fill_rectangle(greenbar0,GREEN);
            }
        }
        else if ((a2==1 && a3==1) && (b2==1 && b3==0))
        {
            //anticlockwise
            if(greenbar0.left>50)
            {
                fill_rectangle(greenbar0,BLACK);
                greenbar0.left -= i;
                greenbar0.right -= i;
                fill_rectangle(greenbar0,GREEN);
            }
            else{
                fill_rectangle(greenbar0,BLACK);
                greenbar.left = 0;
                greenbar.right = 50;
                fill_rectangle(greenbar0,GREEN);
            }
        }
    }
    a2 = a3;
    b2 = b3;
    a0 = a1;
    b0 = b1;
}

createball()
{
    fill_rectangle(yellowdot,BLACK);
    yellowdot0.left = yellowdot.left;
    yellowdot0.right = yellowdot.right - 4;
    yellowdot0.top = yellowdot.top;
    yellowdot0.bottom = yellowdot.bottom - 4;

    yellowdot1.left = yellowdot.left + 4;
    yellowdot1.right = yellowdot.right;
    yellowdot1.top = yellowdot.top;
    yellowdot1.bottom = yellowdot.bottom - 4;

    yellowdot2.left = yellowdot.left;
    yellowdot2.right = yellowdot.right - 4;
    yellowdot2.top = yellowdot.top + 4;
    yellowdot2.bottom = yellowdot.bottom;

    yellowdot3.left = yellowdot.left + 4;
    yellowdot3.right = yellowdot.right;
    yellowdot3.top = yellowdot.top + 4;
    yellowdot3.bottom = yellowdot.bottom;
    fill_rectangle(yellowdot,BLUE);
    fill_rectangle(yellowdot0,BLACK);
    fill_rectangle(yellowdot1,BLACK);
    fill_rectangle(yellowdot2,BLACK);
    fill_rectangle(yellowdot3,BLACK);
}

int main(){
    encoder_setup();
    init_lcd();

    yellowdot.left = (240-5)/2;
    yellowdot.right = (240+5)/2;
    yellowdot.top = (320-5)/2;
    yellowdot.bottom = (320+5)/2;
    fill_rectangle(yellowdot,BLUE);

    greenbar.left = (240-50)/2;
    greenbar.right = (240+50)/2;
    greenbar.top = 0;
    greenbar.bottom = 3;
    fill_rectangle(greenbar,GREEN);

    greenbar0.left = (240-50)/2;
    greenbar0.right = (240+50)/2;
    greenbar0.top = 320-3;
    greenbar0.bottom = 320;
    fill_rectangle(greenbar0,GREEN);

    while(gamestate)
    {
        encoder();
        encoderx();
        gamestate = move_dot();
        _delay_ms(100);
    }
    clear_screen();
    uint16_t z;
    for(z=1;z<817;z++){
        display_string(" ");
    }
    display_string("Game over!");
    return 0;
}