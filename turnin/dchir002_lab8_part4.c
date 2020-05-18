/*	Author: Dumitru Chiriac lab
 *  Partner(s) Name: 
 *	Lab Section: 026
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC ) | (1 << ADATE);
}

unsigned short in;
unsigned char inB;
unsigned char inD;
unsigned char temp;


int main(void) {
    DDRA = 0xFF; PORTA = 0x00;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    ADC_init();
    while (1) {
	in = ADC;
	temp = in - 17;

	if (temp == 0)
		PORTB = 0x00;
	else if (temp == 1)
		PORTB = 0x01;
	else if (temp == 2)
                PORTB = 0x03;
	else if (temp == 3)
                PORTB = 0x07;
	else if (temp == 4)
                PORTB = 0x0F;
	else if (temp == 5)
                PORTB = 0x1F;
	else if (temp == 6)
                PORTB = 0x3F;
	else if (temp == 7)
                PORTB = 0x7F;
    }
    return 1;
}
