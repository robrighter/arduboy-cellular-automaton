#include "Arduboy.h"
#include "matrixscreen.h"
#include "conway.h"
#include <EEPROM.h>


Arduboy arduboy;
MatrixScreen mscreen = MatrixScreen();
Conway conway = Conway();
int iteration = 0;

void intro(){
    for(int i = -8; i < 28; i = i + 2){
        arduboy.clear();
        arduboy.setCursor(10, i);
        arduboy.print("Cellular Automaton");
        arduboy.display();
    }
    arduboy.tunes.tone(987, 160);
    delay(160);
    arduboy.tunes.tone(1318, 400);
    delay(400);
    arduboy.tunes.tone(2000, 400);
    delay(2000);                
}


void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.display();
  intro();
  iteration = 0;
  mscreen.setArduboy( & arduboy );
  conway.seedTheCanvas();
}

void writeCellularValuesToScreen(){
    uint8_t width = 25;
    uint8_t height = 11;
    uint8_t x = 0;
    uint8_t y = 0;
    for(x=0; x<width; x++){
        for(y=0; y<height; y++){
           mscreen.setPixel(x,y, conway.getValueAtLocation(x,y));
        }
    }
}

void loop() {
    if (!(arduboy.nextFrame()))
        return;
    delay(500);
    mscreen.clearMatrix();
    arduboy.clear();
    writeCellularValuesToScreen();
    mscreen.drawMatrix();
    arduboy.setCursor(2, 57);
    char displaystring[22];
    sprintf(displaystring, "Conway  %d", iteration++);
    arduboy.print(displaystring);
    arduboy.display();
    conway.processNextCycle();
}
