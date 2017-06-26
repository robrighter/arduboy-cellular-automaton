#include "Arduboy.h"
#include "matrixscreen.h"
#include <EEPROM.h>


Arduboy arduboy;
MatrixScreen mscreen;


void setup()
{
  mscreen = MatrixScreen();
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.display();
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  delay(90);
  mscreen.clearMatrix();
  arduboy.clear();
  //drawMatrix();
  //arduboy.setCursor(2, 57);
  //char displaystring[22];
  //sprintf(displaystring, "LEN %d | HIGH %d", snakeLength, highScoreLength);
  //arduboy.print(displaystring);
  //arduboy.display();
  
}
