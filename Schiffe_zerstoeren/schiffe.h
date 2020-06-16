#ifndef _SCHIFFE_H_
#define _SCHIFFE_H_

#include "button.h"
#include "joystick.h"
#include "arduino.h"
#include "matrize.h"

#define YELLOW   0xFFE0
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0

enum battleState {config1, config2, battle, end1, end2};

typedef struct Point {
  int x, y;
};

typedef struct Ship {
  int length;
  int x;
  int y;
  bool turn;
  bool placed;
};

class Schiffe {
  private:
  byte cmd1 [8][8];
  byte view1 [8][8]; 
  byte cmd2 [8][8];
  byte view2 [8][8];
  byte player = false;
  
  
  Matrize p1_cmd = Matrize(8, 8, 10);
  Matrize p1_view = Matrize(8, 8, 11);
  Matrize p2_cmd = Matrize(8, 8, 12);
  Matrize p2_view = Matrize(8, 8, 13);
  Joystick p1_js = Joystick(A0, A1);
  Joystick p2_js = Joystick(A2, A3);
  Button p1_btn = Button(7, LOW);
  Button p2_btn = Button(8, LOW);
  Button p1_js_btn = Button(2, LOW);
  Button p2_js_btn = Button(4, LOW);
  
  SimpleTimer timer;
  Point cursor1 = {1, 1};
  Point cursor2 = {0, 0};

  Ship longShip1 = {4, 0, 0, 0, 0};
  Ship longShip2 = {4, 0, 0, 0, 0};
  Ship middleShip1_1 = {3, 0, 0, 0, 0};
  Ship middleShip1_2 = {3, 0, 0, 0, 0};
  Ship middleShip2_1 = {3, 0, 0, 0, 0};
  Ship middleShip2_2 = {3, 0, 0, 0, 0};
  Ship shortShip1_1 = {2, 0, 0, 0, 0};
  Ship shortShip1_2 = {2, 0, 0, 0, 0};
  Ship shortShip1_3 = {2, 0, 0, 0, 0};
  Ship shortShip2_1 = {2, 0, 0, 0, 0};
  Ship shortShip2_2 = {2, 0, 0, 0, 0};
  Ship shortShip2_3 = {2, 0, 0, 0, 0};
  
  battleState bState;
   
  public:
  int i = 0;
  Schiffe();
  void update();
  void clear(byte array[][8]);
  void clearMatrix();
  void setArray(byte array[][8]);
  void drawCursor(Matrize& matrix, Point& cursor);
  void moveCursor(Joystick& stick, Point& cursor);
  //void checkCursor(byte array[][8], Point cursor);
  void drawMatrix(byte array[][8], Matrize& matrix);
  void drawShip(Matrize& matrix, Ship& ship);
  void moveShip(Ship& ship, Joystick& stick);
  void lockShip(byte array[][8], Ship& ship);
  void configShip(byte array[][8], Matrize& matrix, Ship& ship, Joystick& stick, Button& btn_stick);
  bool check(byte array[][8]);
  void setup();
};

#endif
