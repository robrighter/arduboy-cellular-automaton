#include "matrixscreen.h"


void MatrixScreen::setArduboy(Arduboy *a){
    arduboy = a;
}

void MatrixScreen::drawPixel(uint8_t x,uint8_t y){
    int8_t thex = (int8_t)x;
    thex = (3*thex)+2;
    int8_t they= (int8_t)y;
    they = 3*they;
    int8_t width = 2;
    int8_t height = 2;
    int8_t color = 1;
    arduboy->fillRect(thex, they, width, height, color);
}

bool (*MatrixScreen::getCanvas())[MATRIX_WIDTH]{
  return screenMatrix;
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
  for(uint8_t x=0;x<MATRIX_WIDTH;x++){
    for(uint8_t y=0;y<MATRIX_HEIGHT;y++){
      if(screenMatrix[y][x] == true){
        drawPixel(x,y);  
      }
    }
  }
}

void MatrixScreen::setPixel(uint8_t x, uint8_t y, bool on){
  screenMatrix[y][x] = on;
}


