#ifndef MATRIXSCREEN_H
#define MATRIXSCREEN_H
#include "Arduboy.h"
#include <stdlib.h>

#define X_WIDTH 25
#define Y_WIDTH 11


class MatrixScreen {
    
    boolean screenMatrix[X_WIDTH][Y_WIDTH] = {{false}};
    Arduboy* arduboy;
    
    public:
        void setArduboy(Arduboy* a);
        void drawMatrix();
        void clearMatrix();
        void setPixel(byte x,byte y, bool on);
        void drawPixel(byte x,byte y);
};


#endif
