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


int main(void) {
    DDRA = 0xFF; PORTA = 0x00;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    ADC_init();
    while (1) {
	in = ADC;
	inB = (char)in;
	inD = (char)(in >> 8);
	PORTB = inB;
	PORTD = inD;
    }
    return 1;
}
