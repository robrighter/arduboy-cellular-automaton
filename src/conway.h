
#ifndef CONWAY_H
#define CONWAY_H
#include <Arduboy.h>
#include "commons.h"

#define CONWAY_CHANGE_SLEEP_SECONDS 10

class Conway {
  public:
    Conway();
    bool getValueAtLocation(int x, int y);
    void processNextCycle();
    void seedTheCanvas();

  private:
    void setValueAtLocation(bool toset, int x, int y);
    bool calculateValueAtLocation(int x, int y);
    bool canvas[MATRIX_HEIGHT][MATRIX_WIDTH] = {
      {false}
    };

};


#endif
