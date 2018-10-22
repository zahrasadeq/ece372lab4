
#include "PWM.h"

void initPWMTimer1() {
    DDRB |= (1 << DDB5); //pin 11 on dev board

    TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10);
    TCCR1B |= (1 << WGM12) | (1 << CS10);


    OCR1A = 255;
}