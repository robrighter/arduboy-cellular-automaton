#include "matrixscreen.h"

void MatrixScreen::drawPixel(byte x,byte y){
  arduboy.fillRect((5*x)+2, 5*y, 4, 4, 1);
}


void MatrixScreen::clearMatrix(){
  for(int x=0;x<X_WIDTH;x++){
    for(int y=0;y<Y_WIDTH;y++){
      screenMatrix[x][y] = false;
    }
  }
}

void MatrixScreen::drawMatrix(){
  arduboy.drawRect(1, 0, X_WIDTH*5, Y_WIDTH*5, 1);
  for(int x=0;x<X_WIDTH;x++){
    for(int y=0;y<Y_WIDTH;y++){
      if(screenMatrix[x][y] == true){
        drawPixel(x,y);  
      }
    }
  }
}

void MatrixScreen::setPixel(byte x,byte y, bool on){
  screenMatrix[x][y] = on;
}

void MatrixScreen::scrollText(String toscroll, boolean endOnJoystickMove) {
  //do nothing for now
}

