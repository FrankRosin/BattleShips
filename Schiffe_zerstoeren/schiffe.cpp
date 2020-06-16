#include "schiffe.h"

Schiffe :: Schiffe() {
  this->bState = config1;
}

void Schiffe :: clear(byte array[][8]) {
  for(int i = 0; i < 8; i++) {
    for(int k = 0; k < 8; k++) {
      array[i][k] = 0;
    }
  }
}

void Schiffe :: clearMatrix() {
  p1_view.clear();
  p2_view.clear();
  p1_cmd.clear();
  p2_cmd.clear();
}

void Schiffe :: moveCursor(Joystick& stick, Point& cursor) {
  if (stick.hasMovedUp()) {
    cursor.y--;
  }
  else if (stick.hasMovedDown()) {
    cursor.y++;
  }
  else if (stick.hasMovedRight()) {
    cursor.x++;
  }
  else if (stick.hasMovedLeft()) {
    cursor.x--;
  }
}

/*void Schiffe :: checkCursor(byte array[][8]) {
  for(int i = 0; i < 8; i++) {
    for(int k = 0; k < 8; k++) {
      if (array[i][k] == 1 << 7) {
        cursor.x = k;
        cursor.y = i;
        break;
      }
    }
  }
}*/

void Schiffe :: drawMatrix(byte array[][8], Matrize& matrix) {
  for(int i = 0; i < 8; i++) {
    for(int k = 0; k< 8; k++) {
      if (array[i][k] == 0) {
      }
      else if (array[i][k] == 1 << 1) {
        matrix.drawPoint(k, i, RED, 3);   
      }
      else if (array[i][k] == 1 << 2) {
        matrix.drawPoint(k, i, YELLOW, 3);   
      }
      else if (array[i][k] == 1 << 3) {
        matrix.drawPoint(k, i, GREEN, 3);   
      }
    }
  }
}

void Schiffe :: drawCursor(Matrize& matrix, Point& cursor) {
  matrix.drawPoint(cursor.x, cursor.y, BLUE, 3);
}

void Schiffe :: drawShip(Matrize& matrix, Ship& ship) {
  for(int i = 0; i < ship.length; i++) {
    if (ship.turn == 0) {
      matrix.drawPoint(ship.x + i, ship.y, GREEN, 3);
    }
    else if (ship.turn == 1) {
      matrix.drawPoint(ship.x, ship.y + i, GREEN, 3);
    }
  }
}

void Schiffe :: moveShip(Ship& ship, Joystick& stick) {
  if (stick.hasMovedUp()) {
    ship.y--;
  }
  if (stick.hasMovedDown()) {
    ship.y++;
  }
  if (stick.hasMovedRight()) {
    ship.x++;
  }
  if (stick.hasMovedLeft()) {
    ship.x--;
  }
}

void Schiffe :: lockShip(byte array[][8], Ship& ship) {
  for(int i = 0; i < ship.length; i++) {
    if (ship.turn == 0) {
      array[ship.y][ship.x + i] = 1 << 3;
      Serial.println(array[ship.y][ship.x + i]);
      Serial.println("1");
    }
    else if (ship.turn == 1) {
      array[ship.y + i][ship.x] = 1 << 3;
    }
  }
  ship.placed = true;
}

bool Schiffe :: check(byte array[][8]) {
  for (int i = 0; i < 8; i++) {
    for (int k = 0; k < 8; k++) {
      if (array[i][k] == 1 << 2) {
        return false;
      }
    }
  }
  return true;
}

void Schiffe :: configShip(byte array[][8], Matrize& matrix, Ship& ship, Joystick& stick, Button& btn_stick) {
  drawShip(matrix, ship);
  moveShip(ship, stick);
  if (btn_stick.hasBtnClicked()) {
    if (ship.turn == false) {
      ship.turn = true;
    }
    else if (ship.turn == true) {
      ship.turn = false;
    }
  }
  if (btn_stick.hasBtnLongClicked()) {
    lockShip(array, ship);
  }
}

void Schiffe :: update() {
  switch (bState) {
    case config1:
      p1_view.update();
      drawMatrix(view1, p1_view);
      if (longShip1.placed == false) {
        configShip(view1, p1_view, longShip1, p1_js, p1_js_btn);
      }
      else if (longShip1.placed && middleShip1_1.placed == false) {
        configShip(view1, p1_view, middleShip1_1, p1_js, p1_js_btn);
      }
      else if (middleShip1_1.placed && middleShip1_2.placed == false) {
       configShip(view1, p1_view, middleShip1_2, p1_js, p1_js_btn);
      }
      else if (middleShip1_2.placed && shortShip1_1.placed == false) {
       configShip(view1, p1_view, shortShip1_1, p1_js, p1_js_btn);
      }
      else if (shortShip1_1.placed && shortShip1_2.placed == false) {
       configShip(view1, p1_view, shortShip1_2, p1_js, p1_js_btn);
      }
      else if (shortShip1_2.placed && shortShip1_3.placed == false) {
        configShip(view1, p1_view, shortShip1_3, p1_js, p1_js_btn);
      }
      else if (shortShip1_3.placed) {
       bState = config2;
      }
      p1_view.update();
      break;
    
    
    case config2:
      drawMatrix(view1, p1_view);
      drawMatrix(view2, p2_view);
      Serial.println(view2[0][0]);
      if (longShip2.placed == false) {
        configShip(view2, p2_view, longShip2, p2_js, p2_js_btn);
      }
      else if (longShip2.placed && middleShip2_1.placed == false) {
        configShip(view2, p2_view, middleShip2_1, p2_js, p2_js_btn);
      }
      else if (middleShip2_1.placed && middleShip2_2.placed == false) {
       configShip(view2, p2_view, middleShip2_2, p2_js, p2_js_btn);
      }
      else if (middleShip2_2.placed && shortShip2_1.placed == false) {
       configShip(view2, p2_view, shortShip2_1, p2_js, p2_js_btn);
      }
      else if (shortShip2_1.placed && shortShip2_2.placed == false) {
       configShip(view2, p2_view, shortShip2_2, p2_js, p2_js_btn);
      }
      else if (shortShip2_2.placed && shortShip2_3.placed == false) {
        configShip(view2, p2_view, shortShip2_3, p2_js, p2_js_btn);
      }
      else if (shortShip2_3.placed) {
       bState = battle;
      }
      p1_view.update();
      p2_view.update();
      break;
          
      /*case battle:
        if (player == false) {
          drawCursor(p1_cmd, cursor1);
          moveCursor(p1_js, cursor1);
          if (p1_btn.hasBtnClicked()) {
            if (view2[cursor1.y][cursor1.x] == 0) {
              view2[cursor1.y][cursor1.x] = 1 << 1;
              cmd1[cursor1.y][cursor1.x] = 1 << 1;
              player = true;
            }
            else if (view2[cursor1.y][cursor1.x] == 1 << 2) {
              view2[cursor1.y][cursor1.x] = 1 << 0;
              cmd1[cursor1.y][cursor1.x] = 1 << 0;
              if (check(view2)) {
                bState == end1;
              }
            }
          }  
        }
        
        else if (player) {
          drawCursor(p2_cmd, cursor2);
          moveCursor(p2_js, cursor2);
          if (p2_btn.hasBtnClicked()) {
            if (view1[cursor2.y][cursor2.x] == 0) {
              view1[cursor2.y][cursor2.x] = 1 << 1;
              cmd2[cursor2.y][cursor2.x] = 1 << 1;
              player = false;
            }
            else if (view1[cursor2.y][cursor2.x] == 1 << 2) {
              view1[cursor2.y][cursor2.x] = 1 << 0;
              cmd2[cursor1.y][cursor1.x] = 1 << 0;
              if (check(view1)) {
                bState == end2;
              }
            }
          }
        }
        break;
      
      case end1:
        
        break;      
      
      case end2:
        
        break;*/
  }
 
 //drawMatrix(view2, p2_view);
 p1_cmd.update();
 //drawMatrix(cmd1, p1_cmd);
 p2_cmd.update();
 //drawMatrix(cmd2, p2_cmd);
 p1_js.update();
 p2_js.update();
 p1_js_btn.update();
 p2_js_btn.update();
 clearMatrix();
}  

void Schiffe :: setup() {
  p1_cmd.setup();
  p2_cmd.setup();
  p1_view.setup();
  p2_view.setup();
  clear(view1);
  clear(view2);
  clear(cmd1);
  clear(cmd2);
}
