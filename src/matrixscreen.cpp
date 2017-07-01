#include "matrixscreen.h"


void MatrixScreen::setArduboy(Arduboy *a){
    arduboy = a;
}

void MatrixScreen::drawPixel(int x,int y){
    int16_t thex = (int16_t)x;
    thex = (3*thex)+2;
    int16_t they= (int16_t)y;
    they = 3*they;
    int16_t width = 2;
    int16_t height = 2;
    int16_t color = 1;
    arduboy->fillRect(thex, they, width, height, color);
}


void MatrixScreen::clearMatrix(){
  for(int x=0;x<MATRIX_WIDTH;x++){
    for(int y=0;y<MATRIX_HEIGHT;y++){
      screenMatrix[y][x] = false;
    }
  }
}

void MatrixScreen::drawMatrix(){
  arduboy->drawRect(1, 0, MATRIX_WIDTH*3, MATRIX_HEIGHT*3, 1);
  for(int x=0;x<MATRIX_WIDTH;x++){
    for(int y=0;y<MATRIX_HEIGHT;y++){
      if(screenMatrix[y][x] == true){
        drawPixel(x,y);  
      }
    }
  }
}

void MatrixScreen::setPixel(int x, int y, bool on){
  screenMatrix[y][x] = on;
}


