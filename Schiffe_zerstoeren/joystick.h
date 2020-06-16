#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include "button.h"
#include "Arduino.h"

enum JoystickState {isLoose, isUp, isDown, isLeft, isRight};

class Joystick {
private:
  byte pinX;
  byte pinY;
  bool hasMoved = false;
  JoystickState state;
  
public:
  Joystick(byte pinX, byte pinY);
  
  void update();
  
  int xCord() {return analogRead(pinX);}
  int yCord() {return analogRead(pinY);}

  bool hasMovedUp();
  bool hasMovedDown();
  bool hasMovedLeft();
  bool hasMovedRight();

  bool peekHasMovedUp() {return state == isUp;}
  bool peekHasMovedDown() {return state == isDown;}
  bool peekHasMovedLeft() {return state == isLeft;}
  bool peekHasMovedRight() {return state == isRight;}
};

#endif
