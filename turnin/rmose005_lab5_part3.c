/*	Author: rmose005
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 * 
 *  Demo Link: https://youtu.be/aJkoukZjvz4
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;

enum SM1_STATES { SM1_Off, SM1_On1Wait, SM1_On1, SM1_On2Wait, SM1_On2, SM1_On3Wait, SM1_On3, SM1_On4Wait, SM1_On4, SM1_On5Wait, SM1_On5, SM1_On6Wait, SM1_On6, SM1_OffWait } SM1_STATE;
void Tick_Cycle() { 
    switch (SM1_STATE) { 
        case SM1_Off:
            if (tmpA) {
                tmpB = 0x01;
                SM1_STATE = SM1_On1Wait;
            }
            else
                SM1_STATE = SM1_Off;
            break;
        case SM1_On1Wait:
            if (tmpA) 
                SM1_STATE = SM1_On1Wait;
            else
                SM1_STATE = SM1_On1;
            break;
        case SM1_On1:
            if (tmpA) {
                tmpB = 0x02;
                SM1_STATE = SM1_On2Wait;
            }
            else
                SM1_STATE = SM1_On1;
            break;
        case SM1_On2Wait:
            if (tmpA) 
                SM1_STATE = SM1_On2Wait;
            else
                SM1_STATE = SM1_On2;
            break;
        case SM1_On2:
            if (tmpA) {
                tmpB = 0x04;
                SM1_STATE = SM1_On3Wait;
            }
            else
                SM1_STATE = SM1_On2;
            break;
        case SM1_On3Wait:
            if (tmpA) 
                SM1_STATE = SM1_On3Wait;
            else
                SM1_STATE = SM1_On3;
            break;
        case SM1_On3:
            if (tmpA) {
                tmpB = 0x08;
                SM1_STATE = SM1_On4Wait;
            }
            else
                SM1_STATE = SM1_On3;
            break;
        case SM1_On4Wait:
            if (tmpA) 
                SM1_STATE = SM1_On4Wait;
            else
                SM1_STATE = SM1_On4;
            break;
        case SM1_On4:
            if (tmpA) {
                tmpB = 0x10;
                SM1_STATE = SM1_On5Wait;
            }
            else
                SM1_STATE = SM1_On4;
            break;
        case SM1_On5Wait:
            if (tmpA) 
                SM1_STATE = SM1_On5Wait;
            else
                SM1_STATE = SM1_On5;
            break;
        case SM1_On5:
            if (tmpA) {
                tmpB = 0x20;
                SM1_STATE = SM1_On6Wait;
            }
            else
                SM1_STATE = SM1_On5;
            break;
        case SM1_On6Wait:
            if (tmpA) 
                SM1_STATE = SM1_On6Wait;
            else
                SM1_STATE = SM1_On6;
            break;
        case SM1_On6:
            if (tmpA) {
                tmpB = 0x00;
                SM1_STATE = SM1_OffWait;
            }
            else
                SM1_STATE = SM1_On6;
            break;
        case SM1_OffWait:
            if (tmpA) 
                SM1_STATE = SM1_OffWait;
            else
                SM1_STATE = SM1_Off;
            break;
        default:
            SM1_STATE = SM1_Off;
            break;
    }
}


int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs, initalize to 1s.
        DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initalize to 0s.

    /* Insert your solution below */
    SM1_STATE = SM1_Off;
    while (1) {
        tmpA = ~PINA;
        Tick_Cycle();      // Execute one SM tick
        PORTB = tmpB;
    }
    return 1;
}