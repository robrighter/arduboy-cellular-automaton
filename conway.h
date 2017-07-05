
#ifndef CONWAY_H
#define CONWAY_H
#include <Arduboy.h>
#include "commons.h"
#include <avr/pgmspace.h>

#define CONWAY_CHANGE_SLEEP_SECONDS 10

class Conway {
  public:
    Conway();
    bool getValueAtLocation(uint8_t x, uint8_t y);
    void processNextCycle();
    void seedTheCanvas();
    void setTheCanvas(bool theCanvas[MATRIX_HEIGHT][MATRIX_WIDTH]);
    
  private:
    void setValueAtLocation(bool toset, uint8_t x, uint8_t y);
    bool calculateValueAtLocation(uint8_t x, uint8_t y);
    bool (*canvas)[MATRIX_WIDTH];
    bool neighbors[8];
};


#endif
