/*	Author: mlee212
 *  Partner(s) Name: 
 *	Lab Section:
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

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFE; PORTB = 0x01;
    DDRC = 0xFF; PORTC = 0x00;
    DDRD = 0x00; PORTD = 0xFF;
    unsigned short temp = 0x00;
    unsigned char fin = 0x00;
    
    /* Insert your solution below */
    while (1) {
	temp = (PIND << 1) | (PINB & 0x01);
	fin = PINB & 0x01;
	if(temp >= 70) {
	    fin = 0x02;
	}
	else if(temp > 5) {
	    fin = 0x04;
	}
	else {
	    fin = 0x00;
	}
	
	PORTB = fin;
    }
    return 1;
}
