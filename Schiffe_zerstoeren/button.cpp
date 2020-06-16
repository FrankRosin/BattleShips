#include "button.h"

Button :: Button(byte pin, bool isActiveHigh=false, unsigned long debounceMS) {
  this->pin          = pin;
  this->isActiveHigh = isActiveHigh;
  this->debounceMS   = debounceMS;
  this->state        = isReleased;
  
  pinMode(pin, INPUT_PULLUP);
}

void Button :: update() {
  bool isButtonOn = (! isActiveHigh) ^ digitalRead(pin);
  
  switch (state) {
   
    case isReleased:
      if (isButtonOn) {
        state = bouncingOn;
        timer.set(debounceMS);
      }
      break;
      
    case bouncingOn:
      if (timer.elapsed()) {
        if (isButtonOn) { 
          state = isPressed;
          hasClicked = true;
          timer.set(1000);
        }
        else {
          state = isReleased;    // zurück...
        }
      }
      break;
      
    case isPressed:
      if ( ! isButtonOn) {
        state = bouncingOff;
        timer.set(debounceMS);
      };
      if (timer.elapsed()) {
        hasClickedLong = true;
        state = isLongPressed;
        timer.set(500);
      }
      break;
      
    case bouncingOff:
      if (timer.elapsed()) {
        if ( ! isButtonOn) {
          state = isReleased;
        }
        else {
          state = isPressed;    // zurück...
        }
      }
      break;

   case isLongPressed:
      if (!isButtonOn) {
        state = bouncingOff;
        hasClickedLong = false;
        timer.set(debounceMS);  
      }
      if (timer.elapsed()) {
        hasClicked = true;
        timer.set(500);
      }
      break;
  }
}
