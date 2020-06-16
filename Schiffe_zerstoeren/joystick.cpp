#include "joystick.h"
#include "button.h"

Joystick :: Joystick(byte pinX, byte pinY) {
  this->state = isLoose;
  this->pinX = pinX;
  this->pinY = pinY;
}

void Joystick :: update() {

  switch (state) {

    case isLoose:
      if (xCord() >= 1000) {
        state = isRight;
        hasMoved = true;
      }
      else if (xCord() <= 20) {
        state = isLeft;
        hasMoved = true;
      }
      else if (yCord() <= 20) {
        state = isUp;
        hasMoved = true;
      }
     else if (yCord() >= 1000) {
       state = isDown;
       hasMoved = true;
      }
     break;

    case isUp:
      if (yCord() <= 20) {}
      else {
        state = isLoose;
        hasMoved = false;
      }
      break;

    case isDown:
      if (yCord() >= 1000) {}
      else {
        state = isLoose;
        hasMoved = false;
      }
      break;

    case isLeft:
      if (xCord() <= 20) {}
      else {
        state = isLoose;
        hasMoved = false;
      }
      break;

    case isRight:
      if (xCord() >= 1000) {}
      else {
        state = isLoose;
        hasMoved = false;
      }
      break;
  }
}

bool Joystick :: hasMovedUp() {
  if (state == isUp && hasMoved) {
    bool r = hasMoved;
    hasMoved = false;
    return r;
  }
  else {return false;}
}

bool Joystick :: hasMovedDown() {
 if (state == isDown && hasMoved == true) {
    hasMoved = false;
    return true;
  }
  else {return false;}
}

bool Joystick :: hasMovedLeft() {
  if (state == isLeft && hasMoved == true) {
    hasMoved = false;
    return true;
  }
  else {return false;}
}

bool Joystick :: hasMovedRight() {
  if (state == isRight && hasMoved == true) {
    hasMoved = false;
    return true;
  }
  else {return false;}
}
