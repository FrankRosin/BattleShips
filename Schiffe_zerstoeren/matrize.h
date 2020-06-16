#ifndef _MATRIZE_H_
#define _MATRIZE_H_

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "joystick.h"

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define YELLOW   0xEF00
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x0F00

typedef struct Ship2 {
  int length;
  int x;
  int y;
  bool turn;
  bool placed;
};

class Matrize {
  private:
    Adafruit_NeoPixel matrix;
    byte pin;
    int disp_x;
    int disp_y;
    
    
  public:
    Matrize(int disp_x = 8, int disp_y = 8, byte pin = 4);
    byte mtr [8][8];
    Ship2 longShip = {4, 0, 0, 1, 0};
    Joystick stick = Joystick(A0, A1);
    Button js = Button(2, LOW);

    void update();
    void setup();
    void clear();

    void drawLine(int x1, int y1, int x2, int y2, uint16_t color, int bright = 50);
    void drawPoint(int x, int y, uint16_t color, int bright = 50);
    void drawMatrix();
    void clearArr();
    void drawShip();
    void moveShip();
    void lockShip();
};

#endif
