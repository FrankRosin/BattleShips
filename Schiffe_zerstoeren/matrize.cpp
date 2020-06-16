#include "matrize.h"

Matrize :: Matrize(int disp_x = 8, int disp_y = 8, byte pin = 4) {
  this->disp_x = disp_x;
  this->disp_y = disp_y;
  this->pin = pin;
  this->matrix = Adafruit_NeoPixel (disp_x * disp_y, pin, NEO_GRB + NEO_KHZ800);
}

void Matrize :: drawLine(int x1, int y1, int x2, int y2, uint16_t color, int bright = 50){
  int dx = x2 - x1;
  int dy = y2 - y1;
  
  if (dx && (abs(dy) >= abs(dx))) {
    if (x2 < x1) {
      int h=y1; y1=y2; y2=h;
          h=x1; x1=x2; x2=h;
      dx = x2 - x1;
      dy = y2 - y1;
    }
    float k = (float)dy/(float)dx;
    float xstep = 1.0/fabs(k);
    for (float x = (float)x1; x <= (float)x2; x+= xstep) {
      int y = y1 + round(k*(x - (float)x1));
      drawPoint(round(x), y, color, bright);
    }
  }
  
  else if (dy) {
    if (y2 < y1) {
      int h=y1; y1=y2; y2=h;
          h=x1; x1=x2; x2=h;
          dx = x2 - x1;
          dy = y2 - y1;
    }
    float k = (float)dx/(float)dy;
    float ystep = 1.0/fabs(k);
    for (float y = (float)y1; y <= (float)y2; y+= ystep) {
      int x = x1 + round(k*(y - (float)y1));
      drawPoint(x, round(y), color, bright);
    }
  }
  
  else {
      drawPoint(x1, y1, color, bright);   
  }
}

void Matrize :: drawPoint(int x, int y, uint16_t color, int bright = 50){
  byte red =   (((color >> 11) & 0x1F) << 3)*bright/100;
  byte green = (((color >> 6)  & 0x1F) << 3)*bright/100;
  byte blue =  (((color >> 1)  & 0x1F) << 3)*bright/100;
  int linearPos = y *disp_x +  x;
  matrix.setPixelColor(linearPos, matrix.Color(red, green, blue));
}

void Matrize :: setup(){
  matrix.clear();
  matrix.begin();
  matrix.show();
}

void Matrize :: clear() {
  matrix.clear();
}

void Matrize :: update(){
  matrix.show();
  /*stick.update();
  js.update();*/
}

/*void Matrize :: drawMatrix() {
  for(int i = 0; i < 8; i++) {
    for(int k = 0; k< 8; k++) {
      if (mtr[i][k] == 0) {}
      else if (mtr[i][k] == 1 << 0) {
        drawPoint(k, i, RED, 3);   
      }
      else if (mtr[i][k] == 1 << 1) {
        drawPoint(k, i, YELLOW, 3);   
      }
      else if (mtr[i][k] == 1 << 2) {
        drawPoint(k, i, GREEN, 3);   
      }
    }
  }
}

void Matrize :: clearArr() {
  for(int i = 0; i < 8; i++) {
    for(int k = 0; k < 8; k++) {
      mtr[i][k] = 0;
    }
  }
}*/

/*void Matrize :: drawShip() {
  for(int i = 0; i < longShip.length; i++) {
    if (longShip.turn == 0) {
      drawPoint(longShip.x + i, longShip.y, GREEN, 3);
    }
    else if (longShip.turn == 1) {
      drawPoint(longShip.x, longShip.y + i, GREEN, 3);
    }
  }
}


void Matrize :: moveShip() {
  if (stick.hasMovedUp()) {
    longShip.y = longShip.y - 1;
  }
  if (stick.hasMovedDown()) {
    longShip.y = longShip.y + 1;
  }
  if (stick.hasMovedRight()) {
    longShip.x = longShip.x + 1;
  }
  if (stick.hasMovedLeft()) {
    longShip.x = longShip.x - 1;
  }
}

void Matrize :: lockShip() {
  for(int i = 0; i < longShip.length; i++) {
    if (longShip.turn == 0) {
      mtr[longShip.y][longShip.x + 1] = 1 << 1;
    }
    else if (longShip.turn == 1) {
      mtr[longShip.y + 1][longShip.x] = 1 << 1;
    }
  }
  longShip.placed = true;
}*/
