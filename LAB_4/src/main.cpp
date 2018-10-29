// Author:
// Net ID:
// Date:
// Assignment:
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <Arduino.h>
#include "PWM.h"
#include "timer.h" 
#include "adc.h"

int main(){
initADC();
Serial.begin(5600);
unsigned int result=0;
  while(1){
   result=ADCL;
   result+=((unsigned int)ADCH<<8);
   Serial.println(result);
  }

  return 0;
}
