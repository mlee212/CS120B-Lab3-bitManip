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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    /* Insert your solution below */
    unsigned char cnt;
    unsigned char i = 0x00;
    while (1) {
	//button = PINA & 0x01;
	cnt = 0x00;
	tmpA = PINA;
	for(i = 0; i < 8; i++) {
	    if((tmpA >> i & 0x01) == 0x01) {
		cnt++;
	    }
	}
	tmpB = PINB;
	for(i = 0; i < 8; i++) {
	    if((tmpB >> i & 0x01) == 0x01) {
		cnt++;
	    }
	}
	PORTC = cnt;
    }
    return 1;
}
