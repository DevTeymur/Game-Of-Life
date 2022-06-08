#ifndef __MAP_H__
#define __MAP_H__

#include <unistd.h>

#include "screen.h"
#include "../game/board.h"


typedef struct _Map {
  Board board;  // will be created
  Screen screen;
} Map;


// Initializing board and screen respectively inside function and the images of the cells
Map mapCreate(int width, int height, int cols, int rows);

// Main function to run the game
void startGame(Map * map);

// Function to display changes of the cells updating the map while the game running
void mapShow(Map * map);

#endif // __MAP_H__