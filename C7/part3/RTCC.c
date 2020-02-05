/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *          View this license at http://creativecommons.org/about/licenses/
 */
#include "i2c.h"
#include "RTCC.h"

// start -> tx read-> rx -> start -> tx write -> tx(rx variables) -> stop  

void init_clock(void)
{
    /* TODO: Code to initiliase interface and start clock */
    init_i2c_master();
    i2c_start();
}

void set_time(rtcc t)
{
    /* TODO: Code to set time to value in t */      
    i2c_start();
    i2c_tx(0b1101110);  
    i2c_tx(0x00);
    i2c_tx((t.seconds<<4)|t.seconds);
    i2c_tx((t.ten_minutes<<4)|t.minutes);
    i2c_tx((t.ten_hours<<4)|t.hours);
    i2c_stop();
}   

rtcc get_time()
{
    /* TODO: Code to get time from RTCC and return it in an rtcc struct */  
    rtcc t;
    i2c_start();
    i2c_tx(0b1101111);        //accessing RTCC
    i2c_tx(0x00);             //accessing address
    i2c_start();    
    i2c_tx(0b10101111);

    t.seconds = i2c_rx_ack();
    t.ten_seconds = (t.seconds & 0b01110000)>>4;
    t.seconds = (t.seconds & 0b00001111)>>4;

    t.minutes = i2c_rx_ack();
    t.ten_minutes = (t.minutes & 0b01110000)>>4;
    t.minutes = (t.minutes & 0b00001111)>>4;

    t.hours = i2c_rx_ack();
    t.ten_hours = (t.hours & 0b01110000)>>4;
    t.hours = (t.hours & 0b00001111)>>4;

    i2c_stop();
    return t;
}

