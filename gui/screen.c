#include "screen.h"

Screen screenCreate(int width, int height, float scaleX, float scaleY) {
  Screen screen;
  screen.scaleX = scaleX;
  screen.scaleY = scaleY;
  screen.window = SDL_CreateWindow("Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

  if (screen.window == NULL)
    printf("Failed to initialize the window. Error: %s\n", SDL_GetError());

  screen.renderer = SDL_CreateRenderer(screen.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (screen.renderer == NULL)
    printf("Fail in render process. Error: %s\n", SDL_GetError());

  return screen;
}


SDL_Texture * screenLoadTexture(Screen * screen, const char * filePath) {
  SDL_Texture * texture = IMG_LoadTexture(screen->renderer, filePath);

  if (texture == NULL)
    printf("Failed to load the texture. Error: %s\n", SDL_GetError());

  return texture;
}


void screenRender(Screen * screen, Entity * entity) {
  SDL_Rect source;
  source.x = entity->frame.x;
  source.y = entity->frame.y;
  source.w = entity->frame.w;
  source.h = entity->frame.h;

  SDL_Rect destination; 
  destination.x = entity->position[0] * screen->scaleX;
  destination.y = entity->position[1] * screen->scaleY;
  destination.w = entity->frame.w * screen->scaleX;
  destination.h = entity->frame.h * screen->scaleY;

  SDL_RenderCopy(screen->renderer, entity->texture, &source, &destination);
}
