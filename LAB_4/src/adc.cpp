
#include "adc.h"
#include <avr/io.h>


void initADC()
{
    //set voltage reference and right shift
    ADMUX |= (1 << REFS0);

    //Right Adjust
    ADMUX &= ~(1 << ADLAR);

    //set free running
    ADCSRB &= ~(1 << ADTS2 | 1<<ADTS1 | 1 << ADTS0); 

    //enable auto-triggering and turn on ADC
    ADCSRA |= (1 << ADEN) | (1 << ADATE);

    // disable digital input
    DIDR0 |= (1 << ADC2D) | (1 << ADC1D) | (1 << ADC0D);

    //start conversion
    ADCSRA |= (1 << ADSC);
}


