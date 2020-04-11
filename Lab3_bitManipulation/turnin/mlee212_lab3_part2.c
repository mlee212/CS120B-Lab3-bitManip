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
    DDRB = 0xFF; PORTB = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    /* Insert your solution below */
    while (1) {
	//button = PINA & 0x01;
	tmpA = PINA & 0x0F;
	tmpB = 0x00;
	if(tmpA < 3) {
	    tmpB = tmpB | 0x20;
	}
	else if(tmpA < 5) {
	    tmpB = tmpB | 0x30;
	}
	else if(tmpA < 7) {
	    tmpB = tmpB | 0x38;
	}
	else if(tmpA < 10) {
	    tmpB = tmpB | 0x3C;
	}
	else if(tmpA < 13) {
	    tmpB = tmpB | 0x3E;
	}
	else if(tmpA < 16) {
	    tmpB = tmpB | 0x3F;
	}
	if(tmpA < 5) {
	    tmpB = tmpB | 0x40;
	}

	PORTB = tmpB;
    }
    return 1;
}
