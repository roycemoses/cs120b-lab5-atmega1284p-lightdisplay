/*	Author: rmose005
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs, initalize to 1s.
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initalize to 0s.
   	
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
    /* Insert your solution below */
    while (1) {
	// 1) Read input
	tmpA = ~PINA;
	tmpA = tmpA & 0x0F; // only read in PA3..PA0
	tmpC = 0x00;
	// 2) Perform computation	
	if (tmpA == 1 || tmpA == 2)
		tmpC = 0x20; // PC5 lights
	else if (tmpA == 3 || tmpA == 4)
		tmpC = 0x30; // PC5 and PC4 light
	else if (tmpA == 5 || tmpA == 6)
		tmpC = 0x38; // PC5..PC3 light
	else if (tmpA == 7 || tmpA == 8 || tmpA == 9)
		tmpC = 0x3C; // PC5..PC2 light
	else if (tmpA == 10 || tmpA == 11 || tmpA == 12)
		tmpC = 0x3E; // PC5..PC1 light
	else if (tmpA == 13 || tmpA == 14 || tmpA == 15)
		tmpC = 0x3F;
	
	if (tmpA <= 4) // if fuel lvl less than 4:
		tmpC = tmpC | 0x40; // light up PC6.
			
	// 3) Write output
	PORTC = tmpC;
	
    }
    return 1;
}