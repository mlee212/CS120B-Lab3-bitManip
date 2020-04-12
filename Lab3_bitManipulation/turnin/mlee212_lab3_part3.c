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
    DDRB = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;
    /* Insert your solution below */
    while (1) {
	//button = PINA & 0x01;
	tmpA = PINA & 0x0F;
	tmpC = 0x00;
	if(tmpA < 3) {
	    tmpC = tmpC | 0x20;
	}
	else if(tmpA < 5) {
	    tmpC = tmpC | 0x30;
	}
	else if(tmpA < 7) {
	    tmpC = tmpC | 0x38;
	}
	else if(tmpA < 10) {
	    tmpC = tmpC | 0x3C;
	}
	else if(tmpA < 13) {
	    tmpC = tmpC | 0x3E;
	}
	else if(tmpA < 16) {
	    tmpC = tmpC | 0x3F;
	}
	if(tmpA < 5) {
	    tmpC = tmpC | 0x40;
	}
	
	tmpA = PINA & 0x70;
	
	if(tmpA == 0x30) {
	    tmpC = tmpC | 0x80;
	}
	
	PORTC = tmpC;
    }
    return 1;
}
