#ifndef _BUTTON_H
#define _BUTTON_H

#include "Arduino.h"
#include "SimpleTimer.h"

enum ButtonState {isPressed, isLongPressed, bouncingOn, isReleased, bouncingOff};

class Button {
private:
  byte pin;
  bool isActiveHigh;
  unsigned long debounceMS;

  SimpleTimer timer;
  SimpleTimer timer1;

  bool hasClicked = false;
  bool hasClickedLong = false;
  ButtonState state;

public:
  Button(byte pin, bool isActiveHigh, unsigned long debounceMS = 10);

  void update();

  bool isBtnPressed() {return state == isPressed  || state == bouncingOn || state == isLongPressed;}
  bool isBtnReleased() {return state == isReleased || state == bouncingOff;}

  bool peekHasBtnClicked() {return hasClicked;}
  bool hasBtnClicked() {bool r = hasClicked;  hasClicked = false;  return r;}

  bool peekHasBtnLongClicked() {return hasClickedLong;}
  bool hasBtnLongClicked() {bool r = hasClickedLong;  hasClickedLong = false;  return r;}

};

#endif
