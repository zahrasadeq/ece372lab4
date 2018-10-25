/// Author:        Andrew Enriquez, 
// Net ID:         andrewenriquez, 
// Date:           10/24/2018
// Assignment:     Lab 4
//------------------------------------------------------------------//
#include "PWM.h"

void initPWMTimer1() {
    DDRB |= (1 << DDB5); //pin 11 on dev board

    // set Fast PWM 10-bit mode, non-inverting
    TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10);
    TCCR1B |= (1 << WGM12) | (1 << CS10);

    //duty cycle to 25%
    OCR1A = 255; 
}