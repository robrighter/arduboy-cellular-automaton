#ifndef MATRIXSCREEN_H
#define MATRIXSCREEN_H
#include "commons.h"
#include <Arduboy.h>
#include <stdlib.h>
#include <avr/pgmspace.h>



class MatrixScreen {
    
    bool screenMatrix[MATRIX_HEIGHT][MATRIX_WIDTH] = {{false}};
    Arduboy* arduboy;
    
    public:
        void setArduboy(Arduboy* a);
        void drawMatrix();
        void clearMatrix();
        void setPixel(uint8_t x,uint8_t y, bool on);
        void drawPixel(uint8_t x,uint8_t y);
        bool (*getCanvas())[MATRIX_WIDTH];
};


#endif
