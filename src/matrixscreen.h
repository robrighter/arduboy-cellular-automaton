#ifndef MATRIXSCREEN_H
#define MATRIXSCREEN_H
#include "commons.h"
#include <Arduboy.h>
#include <stdlib.h>



class MatrixScreen {
    
    boolean screenMatrix[MATRIX_HEIGHT][MATRIX_WIDTH] = {{false}};
    Arduboy* arduboy;
    
    public:
        void setArduboy(Arduboy* a);
        void drawMatrix();
        void clearMatrix();
        void setPixel(int x,int y, bool on);
        void drawPixel(int x,int y);
};


#endif
