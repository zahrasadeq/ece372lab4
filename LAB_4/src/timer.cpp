/// Author:        Andrew Enriquez, 
// Net ID:         andrewenriquez, 
// Date:           10/24/2018
// Assignment:     Lab 4
//----------------------------------------------------------------------//

#include "timer.h"

/* Initialize timer 0, you should not turn the timer on here. You will need to
* use CTC mode
*/
void initTimer0(){
  //This is CTC mode for timer 1.
  /*TCCR1B |= (1 << WGM12);
  TCCR1A &= ~(1 << WGM10) | ~(1 << WGM11);
  */
  // Set the mode to be CTC for timer0
  TCCR0A |= (1 << WGM01);
  TCCR0A &= ~(1 << WGM00);
  TCCR0B &= ~(1 << WGM02);

}

/* This delays the program an amount specified by unsigned int delay.
*/
void delayUs(unsigned int delay){
  delay = 2*delay; //needed
  // Make sure the appropriate flag is down
  TIFR0 |= (1 << OCF0A);

  // Clear the timer
  TCNT0 = 0;

  
  //This is for timer 1 High and low registers
  // Make CTC Mode is set to Timer1 if you want to use Timer 1 as a delay
  /*OCR1AH = (0xff & (delay >> 8)); //first 8 bits set to high
  OCR1AL = (0xff & (delay)); //last 8 bits set to low
  */

  // clear the timer
  TCNT0 = 0;

  // calculate the TOP value and assign it to OCR1A
    TIFR0 |= (1 << OCF0A);


  // Turn on the timer with prescalar of 8
  TCCR0B |= (1 << CS01);
                
  // Do nothing while the OCF0A flag is not up
  while(!(TIFR0 & (1 << OCF0A)));

  // Clear the OCF0A flag

  // Turn off the timer
  TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00);

}

