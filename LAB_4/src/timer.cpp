/// Author:        Andrew Enriquez
// Net ID:         andrewenriquez
// Date:           10/8/2018
// Assignment:     Lab 3
//----------------------------------------------------------------------//

#include "timer.h"

/* Initialize timer 1, you should not turn the timer on here. You will need to
* use CTC mode
*/
void initTimer1(){
  //TCCR0A |= (1 << WGM01); //timer0
  //This is CTC mode for timer 1.
  TCCR1B |= (1 << WGM12);
  TCCR1A &= ~(1 << WGM10) | ~(1 << WGM11);
}

/* This delays the program an amount specified by unsigned int delay.
*/
void delayUs(unsigned int delay){

  delay = 2*delay; //needed
  OCR1AH = (0xff & (delay >> 8)); //first 8 bits set to high
  OCR1AL = (0xff & (delay)); //last 8 bits set to low
  

  // clear the timer
  TCNT1 = 0;

  // calculate the TOP value and assign it to OCR1A
    TIFR1 |= (1 << OCF1A);


  // Turn on the timer
  TCCR1B |= (1 << CS11);
                
  // Do nothing while the OCF0A flag is not up
  while(!(TIFR1 & (1 << OCF1A)));

  // Clear the OCF0A flag

  // Turn off the timer
  TCCR0B &= ~(1 << CS12 | 1 << CS11 | 1 << CS10);

}

