#include "map.h"


SDL_Texture * deadTexture, * aliveTexture;

Map mapCreate(int width, int height, int cols, int rows) {
  float scaleX = width / (cols * 30.0), scaleY = width / (rows * 30.0);
  Map map; 
  map.screen = screenCreate(width, height, scaleX, scaleY);
  map.board = boardCreate(cols, rows);

  aliveTexture = screenLoadTexture(&map.screen, "../gui/cells/redsquare.png");
  deadTexture = screenLoadTexture(&map.screen, "../gui/cells/bluesquare.png");

  return map;
}


void startGame(Map * map) {
  bool gameRunning = true;
	SDL_Event event;

  while (gameRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        gameRunning = false;
      }
    }
    mapShow(map);
    // drawAnsi(map);
  }

	SDL_DestroyWindow(map->screen.window);
	SDL_Quit();
}

void mapShow(Map * map) {
  SDL_Texture * texture;

  SDL_RenderClear(map->screen.renderer);

  for (int i = 0; i < map->board.cols; i++) {
    for (int j = 0; j < map->board.rows; j++) {
      Entity entity;
      if (getCellState(&map->board, i, j)) {
        entity = entityCreate(i*30, j*30, 30, 30, aliveTexture);
      } else {
        entity = entityCreate(i*30, j*30, 30, 30, deadTexture);
      }
      screenRender(&map->screen, &entity);
    }
  }

  SDL_RenderPresent(map->screen.renderer);
  // usleep(200000);
  generateNext(&map->board);
  duplicateTable(&map->board);
}