// Author: Rachael Seedenburg     
// Net ID:   rtseeden      
// Date:           
// Assignment:     Lab 4
//----------------------------------------------------------------------//

#include "timer4.h"

/* Initialize timer 4, you should not turn the timer on here. You will need to
* use CTC mode
*/
void initTimer4(){
  //Set the mode to CTC
  TCCR4B |= (1 << WGM42);
  TCCR4A &= ~(1<<WGM41)|~(1<<WGM43)|~(1<<WGM40);

}

/* This delays the program an amount specified by unsigned int delay.
*/
void delayUs(unsigned int delay){

  // calculate what value goes in OCR0A per microsecond
  delay=2*delay;
  OCR4AH = (delay >> 8) & 0xFF;
  OCR4AL = delay & 0xFF;
  
  // Make sure the appropriate flag is down
  TIFR4 |= (1 << OCF1A);

  // Clear the timer
  TCNT4H= 0;
  TCNT4L= 0;

  // turn on the timer by setting the pre-scaler to 8
  TCCR4B |= (1 << CS41);

  // while the flag is down, do not do anything.
  while(!(TIFR4 & (1 << OCF4A)));

  // Turn the clock back off
  TCCR4B &= ~(1 << CS42 | 1 << CS41 | 1 << CS40);
}
