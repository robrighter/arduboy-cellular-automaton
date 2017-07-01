#include "conway.h"

Conway::Conway(){}

bool Conway::getValueAtLocation(int x, int y){
    if( (x < MATRIX_WIDTH) && (y < MATRIX_HEIGHT) ){
        return canvas[y][x];
    }
    else{
        return false;
    }
}
    

void Conway::processNextCycle(){
    int x=0;
    int y=0;
    
    bool nextcanvas[MATRIX_HEIGHT][MATRIX_WIDTH];
    
    //calculate the new values
    for(x=0; x<MATRIX_WIDTH; x++){
        for(y=0; y<MATRIX_HEIGHT; y++){
            nextcanvas[y][x] = x%2 ? true : false;//calculateValueAtLocation(x,y);
        }
    }
    
    //now copy the new values onto the canvas
    for(x=0; x<MATRIX_WIDTH; x++){
        for(y=0; y<MATRIX_HEIGHT; y++){
            canvas[y][x] = nextcanvas[y][x];//new_canvas[y][x] ? true : false;
        }
    }
}

void Conway::setValueAtLocation(bool toset, int x, int y){
    if( (x < MATRIX_WIDTH) && (y<MATRIX_HEIGHT) ){
        canvas[y][x] = toset;
    }
}

bool Conway::calculateValueAtLocation(int x, int y){
    bool neighbors[8];
    uint8_t top_y = (y == 0) ? MATRIX_HEIGHT-1 : y-1;
    uint8_t middle_y = y;
    uint8_t bottom_y = ((y+1)<MATRIX_HEIGHT) ? y+1 : 0;
    uint8_t left_x = (x == 0) ? MATRIX_WIDTH-1 : x-1;
    uint8_t middle_x = x;
    uint8_t right_x = ((x+1)<MATRIX_WIDTH) ? x+1 : 0;
    
    
    
    neighbors[0] = getValueAtLocation(left_x, top_y);
    neighbors[1] = getValueAtLocation(middle_x, top_y);
    neighbors[2] = getValueAtLocation(right_x, top_y);
    neighbors[3] = getValueAtLocation(left_x, middle_y);
    neighbors[4] = getValueAtLocation(right_x, middle_y);
    neighbors[5] = getValueAtLocation(left_x, bottom_y);
    neighbors[6] = getValueAtLocation(middle_x, bottom_y);
    neighbors[7] = getValueAtLocation(right_x, bottom_y);
    bool is_on = getValueAtLocation(middle_x, middle_y);
    
    uint8_t neighbors_on = 0;
    uint8_t neighbors_off = 0;
    
    for(int i = 0; i<8; i++){
        if(neighbors[i]){
            neighbors_on++;
        }
        else{
            neighbors_off++;
        }
    }
    //RULES
    //1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
    if( is_on && (neighbors_on<2) ){
        return false;
    }
    //2. Any live cell with two or three live neighbours lives on to the next generation.
    if( is_on && ((neighbors_on == 2) || (neighbors_on == 3)) ){
        return true;
    }
    //3. Any live cell with more than three live neighbours dies, as if by overpopulation.
    if( is_on && (neighbors_on>3) ){
        return false;
    }
    //4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    if( (!is_on) && (neighbors_on == 3) ){
        return true;
    }
    //should not get here
    return false;
}

void Conway::seedTheCanvas(){
    int number_on = random(10);
    int x = 0;
    int y = 0;
    for(int i=0; i<number_on; i++){
        x = random(MATRIX_WIDTH-2);
        y = random(MATRIX_HEIGHT-2);
        canvas[y][x] = true;
        canvas[y+1][x] = true;
        canvas[y+1][x+1] = true;
        canvas[y][x+1] = true;
    }
}
