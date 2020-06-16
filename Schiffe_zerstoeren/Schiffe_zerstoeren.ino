#include "joystick.h"
#include "button.h"
#include "matrize.h"
#include "Adafruit_GFX.h"
#include "Adafruit_NeoMatrix.h"
#include "Adafruit_NeoPixel.h"
#include "schiffe.h"

/*Joystick test(A4, A5);
Button stickJamm(4, LOW);
#define CRED 0xf800
#define CGRN 0x07C0
#define CBUE 0x003E*/
Matrize pixels(8, 8, 12);

Schiffe ships;
//int i = 0;

void setup() {
   
   //pixels.setup();
   Serial.begin(9600);
   ships.setup();
   /*pixels.setup();
   pixels.clearArr();
   //pixels.mtr[0][0] = 1 << 2;
   //pixels.mtr[0][1] = 1 << 1;*/
}

void loop() {
  /*pixels.drawShip();
  pixels.moveShip();
  pixels.drawMatrix();
  //Serial.println(pixels.mtr[0][0]);
  //uint16_t color = random(2, 0xFFFF);

  //pixels.drawPoint(5, 5, RED, 12);
  pixels.update();
  //delay(100);
  pixels.clear();
  //pixels.stick.update();
  //pixels.longShip.y++;
  //ships.update();*/
  ships.update();
  //pixels.clear();
}
