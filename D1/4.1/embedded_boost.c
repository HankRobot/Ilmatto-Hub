/* embedded_boost.c 
 *
 *  Author: Steve Gunn & Klaus-Peter Zauner 
 * Licence: This work is licensed under the Creative Commons Attribution License. 
 *          View this license at http://creativecommons.org/about/licenses/
 *   Notes: 
 *          - Use with a terminal program
 * 
 *          - F_CPU must be defined to match the clock frequency
 *
 *          - Compile with the options to enable floating point
 *            numbers in printf(): 
 *               -Wl,-u,vfprintf -lprintf_flt -lm
 *
 *          - Pin assignment: 
 *            | Port | Pin | Use                         |
 *            |------+-----+-----------------------------|
 *            | A    | PA0 | Voltage at load             |
 *            | D    | PD0 | Host connection TX (orange) |
 *            | D    | PD1 | Host connection RX (yellow) |
 *            | D    | PD7 | PWM out to drive MOSFET     |
 */
//reference: https://tutorial.cytron.io/2012/06/22/pid-for-embedded-design/ for PID control
//taken from https://stackoverflow.com/questions/628761/convert-a-character-digit-to-the-corresponding-integer-in-c for changing char to digit

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

#define DELAY_MS      1
#define BDRATE_BAUD  9600

#define ADCREF_V     3.3
#define ADCMAXREAD   1023   /* 10 bit ADC */

/* Find out what value gives the maximum
   output voltage for your circuit:
*/
#define PWM_DUTY_MAX 240    /* 94% duty cycle */
		
void init_stdio2uart0(void);
int uputchar0(char c, FILE *stream);
int ugetchar0(FILE *stream);
		
void init_adc(void);
double v_load(void);
double set_target = 1.5; //target
double integral = 0;
double last_error = 0;
uint8_t set_value = 1;
void init_pwm(void);
void pwm_duty(uint8_t x);
void pid_control(double target, double kp, double ki);
void setup_interrupt_pin();

ISR(INT0_vect)   //falling edge port D pin 2
{
    set_value = 1;
}

int main(void)
{
    DDRB |= _BV(PB7) | _BV(PB6); // green led setup
	uint16_t cnt = 61; //goes to else condition first
    char str;    	
	init_stdio2uart0();
	init_pwm(); 
	init_adc();
	
    //for PID Tuning
    double kp = 5.5;
    double ki = 1.2;
    double kd = 1.0;

	for(;;) {	  
        if(&str!=NULL && set_value==0){
            //original 
            PINB |= _BV(PB7); //toggles the  green led per cycle
	        //printf( "%04d:  ", cnt );
        
	        printf( "  -->  %5.3f V\r\n", v_load()/0.176);
	        _delay_ms(DELAY_MS);
	        //cnt++; 
            pid_control(kp,ki,kd);   /* Limited by PWM_DUTY_MAX */
        }
        else{
            //edited and adapted from X2 UARTTest.c
            /* get character from UART */ 
            printf("Please type in a number between 2 and 10, type a if 10v, else 2-9\n\r");
		    scanf("%c", &str);;
            set_target = atoi(&str);  //taken from https://stackoverflow.com/questions/628761/convert-a-character-digit-to-the-corresponding-integer-in-c
            
		    /* send message back to the host terminal */
            if (set_target!=0 && set_target<=10 && set_target>=2){ //atoi returns zero if string/ch is a character entered except for letter a, which represents value 10V
                printf("You sent voltage setting %c V\n\r",str);
		        printf("\n\r");
                cnt = 0;
                set_value = 0;
            }
            else if (str=='a'){
                printf("You sent voltage setting 10 V\n\r");
		        printf("\n\r");
                cnt = 0;
                set_value = 0;
                set_target = 10;
            }
            else{
                printf("You sent the letter %c\n\r",str);
            }
        }
	}
}

//https://tutorial.cytron.io/2012/06/22/pid-for-embedded-design/
void pid_control(double kp, double ki, double kd){
    // kp and ki values
    //printf( "kp reading %5.5f \r\n", kp);
    //printf( "ki reading %5.5f \r\n", ki);

    //get the current position
    double current = v_load()/0.176; //adc reading convert to real voltage at vout
    //printf( "current reading %5.3f V\r\n", current);
    
    //calculate the current error
    double error = set_target - current;
    //printf( "error reading %5.3f V\r\n", error);
    if(error<=0.05){
        PORTB |= _BV(PB6); //toggles the  blue led if error is small and reached steady state
    }
    else{
        PORTB &= ~_BV(PB6);
    }
    //calculate the integral
    integral += error;
    //printf( "integral reading %5.3f V\r\n", integral);
    
    //calculate the derivative
    double derivative = error - last_error;

    //calculate the control variable
    uint8_t pwm = (kp*error) + (ki*integral) + (kd*derivative);
    //printf( "final reading %3u \r\n", pwm);

    //tune the pwm
    if(pwm>255) pwm = 255;
    else if(pwm < -255) pwm = 0;
    pwm_duty(pwm);
    last_error = error;
}

void setup_interrupt_pin(){
    DDRA = 0x00;
    /* Set to trigger on falling edge */
    EICRA |= _BV(ISC01); //falling edge on INT0

    /* Enable interrupt */
    EIMSK |= _BV(INT0);
    sei();
}

int uputchar0(char c, FILE *stream){
	if (c == '\n') uputchar0('\r', stream);
	while (!(UCSR0A & _BV(UDRE0)));
	UDR0 = c;
	return c;
}

int ugetchar0(FILE *stream){
	while(!(UCSR0A & _BV(RXC0)));
	return UDR0;
}

void init_stdio2uart0(void){
	/* Configure UART0 baud rate, one start bit, 8-bit, no parity and one stop bit */
	UBRR0H = (F_CPU/(BDRATE_BAUD*16L)-1) >> 8;
	UBRR0L = (F_CPU/(BDRATE_BAUD*16L)-1);
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
	UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);

	/* Setup new streams for input and output */
	static FILE uout = FDEV_SETUP_STREAM(uputchar0, NULL, _FDEV_SETUP_WRITE);
	static FILE uin = FDEV_SETUP_STREAM(NULL, ugetchar0, _FDEV_SETUP_READ);

	/* Redirect all standard streams to UART0 */
	stdout = &uout;
	stderr = &uout;
	stdin = &uin;
}

void init_adc (void){
    /* REFSx = 0 : Select AREF as reference
     * ADLAR = 0 : Right shift result
     *  MUXx = 0 : Default to channel 0
     */
    ADMUX = 0x00;
    /*  ADEN = 1 : Enable the ADC
     * ADPS2 = 1 : Configure ADC prescaler
     * ADPS1 = 1 : F_ADC = F_CPU / 64
     * ADPS0 = 0 :       = 187.5 kHz
     */
    ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1);
}

double v_load(void){
     uint16_t adcread;
         
     /* Start single conversion */
     ADCSRA |= _BV ( ADSC );
     /* Wait for conversion to complete */
     while ( ADCSRA & _BV ( ADSC ) );
     adcread = ADC;
    
     //printf("ADC=%4d", adcread);  
 
     return (double) (adcread * ADCREF_V/ADCMAXREAD);
}

void init_pwm(void){
    /* TIMER 2 */
    DDRD |= _BV(PD6); /* PWM out */
    DDRD |= _BV(PD7); /* inv. PWM out */
    

    TCCR2A = _BV(WGM20) | /* fast PWM/MAX */
	     _BV(WGM21) | /* fast PWM/MAX */
	     _BV(COM2A1); /* A output */
    TCCR2B = _BV(CS20);   /* no prescaling */   
}

/* Adjust PWM duty cycle
   Keep in mind this is not monotonic
   a 100% duty cycle has no switching
   and consequently will not boost.  
*/
void pwm_duty(uint8_t x) {
    x = x > PWM_DUTY_MAX ? PWM_DUTY_MAX : x; //if keyed in value is larger than defined max, will choose defined value, else choose keyed in value
                       
    //printf("PWM=%3u \r\n", x);  

    OCR2A = x;
}

