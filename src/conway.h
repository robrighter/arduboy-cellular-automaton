
#ifndef CONWAY_H
#define CONWAY_H
#include "Arduboy.h"

#define CANVAS_WIDTH 25
#define CANVAS_HEIGHT 11
#define CONWAY_CHANGE_SLEEP_SECONDS 10

class Conway {
  public:
    Conway();
    bool getValueAtLocation(uint8_t x, uint8_t y);
    void processNextCycle();
    void seedTheCanvas();

  private:
    void setValueAtLocation(bool toset, uint8_t x, uint8_t y);
    bool calculateValueAtLocation(uint8_t x, uint8_t y);
    bool canvas[CANVAS_HEIGHT][CANVAS_WIDTH] = {
      {false}
    };

};


#endif
