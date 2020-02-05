#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include "RTCC.h"

int main()
{
    rtcc t;
    t.ten_hours = 1;
    t.hours = 2;
    t.ten_minutes = 3;
    t.minutes = 4;
    t.ten_seconds = 5;
    t.seconds = 6;
    set_time(t);

    for(;;)
    {
        t = get_time();
        _delay_ms(5000);
    }
}