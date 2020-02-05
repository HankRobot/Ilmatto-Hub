/*  Author: Klaus-Peter Zauner
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *          View this license at http://creativecommons.org/about/licenses/
 *   Notes: F_CPU must be defined to match the clock frequency
 */
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "et_scale.h"

/* Pin configuration
 *       progress LED:  PB7
 */

#define STEP_DELAY_MS 450

/* Inaudible frequencies used to indicate state for melody2freq: */
#define M2F_END    0
#define M2F_REST   1
#define M2F_UNKOWN 2
#define TONE_PRESCALER 8UL


/* You can find music pieces in abc-notation here:

    http://abcnotation.com/search
    "Currently the index contains around 330,000 tunes
      in 140,000 files."

    The following was copied form the above site and
    "\n\" was added at each line-break to make it suitable
    to insert directly in the source code.

 */

const char melody[] ="\
\n\
C C G G A A G24 F F E E D D C24 G G F F E E D24 G G F F E E D24 C C G G A A G24 F F E E D D C24 \n\
";


void init_tone(void);
void tone(uint16_t frequency);
uint16_t melody2freq(const char *abc_melody);

void init_volume(void);
void volume(uint8_t x);
int main() {
    uint16_t f;
    int8_t i=255;
    DDRA = 0xFF;
    DDRA |= _BV(PA0);
    DDRB |= _BV(PB7); /* LED */

    init_tone();
    init_volume();
    for(;;){
    	melody2freq(melody);  /* initialise  */
    	while((f=melody2freq(NULL)) != M2F_END)
		{
    		 /* skip unknown symnols */    		
    		volume(i);   		
    		_delay_ms(STEP_DELAY_MS/2);    		
			i+=5;
		PORTB ^= _BV(PB7); /* toggle LED */
		/*
		if(i>255)
		{
		i=0;
		}
		*/
		if (f == M2F_UNKOWN)  continue;
		tone(f);
		volume(0);
		_delay_ms(100);
		

    	}
		
		
    	_delay_ms(STEP_DELAY_MS);
    	_delay_ms(STEP_DELAY_MS);
    }
}

void init_volume(void){
	DDRD |= _BV(PD7);
	TCCR2A = _BV(COM2A1)|_BV(WGM21)|_BV(WGM20);
	TCCR2B = _BV(CS20);
	
}


void init_tone(void)
{

	DDRD |= _BV(PD5); /* enable ouput driver for OC1A */
	TCCR1A = _BV(COM1A0)|_BV(WGM10); /* frequency (f) correct PWM, */
	TCCR1B = _BV(WGM13) |_BV(CS11); /* prescaler set to 8 */

}


/* tone ---
   Set oscillator output to desired frequency
*/
void tone(uint16_t frequency)
{
	OCR1A = (uint16_t) (F_CPU/(2*2*TONE_PRESCALER)/frequency);
}

/* melody2freq ---
 *   If called with a string of abc music notation
 *   initialise with this string.
 *   If called with a null-pointer, return next
 *   frequency.
 *
 *   Low frequencies which are not part of the
 *   the tone scale are returned to report state.
 *
 *   The folowing is a very crude implementation
 *   of an abc-player.
 *
 */
uint16_t melody2freq(const char *m) {
    static const char *melody;
    static uint16_t pos;
    static uint8_t scale_index;

    if(m != NULL){  /* initialization */
        melody = m;
        pos = 0;
        return M2F_END; /* to be ignored */
    }

    if(melody[++pos] == '\0') return M2F_END;


    switch( melody[pos] ) {
	case 'c':
	case 'C': {
	    scale_index = ET_SCALE_C;
	    break;
	}
	case 'd':
	case 'D': {
	    /* 2 semitones above C */
	    scale_index = ET_SCALE_C + 2;
	    break;
	}
	case 'e':
	case 'E': {
	    /* 4 semitones above C */
	    scale_index = ET_SCALE_C + 4;
	    break;
	}
	case 'f':
	case 'F': {
	    /* 5 semitones above C */
	    scale_index = ET_SCALE_C + 5;
	    break;
	}
	case 'g':
	case 'G': {
	    /* 7 semitones above C */
	    scale_index = ET_SCALE_C + 7;
	    break;
	}
	case 'a':
	case 'A': {
	    /* 9 semitones above C */
	    scale_index = ET_SCALE_C + 9;
	    break;
	}
        case 'b':
	case 'B': {
	    /* 11 semitones above C */
	    scale_index = ET_SCALE_C + 11;
	    break;
	}
        default:
	    { /* unknown symbol --> no change */
		return M2F_UNKOWN;
	    }
    }

    if(  melody[pos] > 'Z' ) {  /* lower case chars have higher ASCII codes than A-Z */
         scale_index += 12;     /* shift one octave up */
    }

    return et_scale[scale_index];
}
void volume(uint8_t x)
{
	OCR2A = x* 0.3;
}
