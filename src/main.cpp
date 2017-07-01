#include <stdlib.h>
#include "commons.h"
#include <Arduboy.h>
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
    delay(700);                
}


void setup()
{
  
    arduboy.begin();
    arduboy.setFrameRate(60);
    arduboy.display();
    intro();
    //Serial.begin(9600);
    //Serial.println("Hello world");
    iteration = 0;
    mscreen.setArduboy( & arduboy );
    mscreen.clearMatrix();
    conway.seedTheCanvas();
}

void writeCellularValuesToScreen(){
    int x = 0;
    int y = 0;
    for(x=0; x<MATRIX_WIDTH; x++){
        for(y=0; y<MATRIX_HEIGHT; y++){
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
