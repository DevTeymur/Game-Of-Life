#ifndef __WINDOW_RENDERER_H__
#define __WINDOW_RENDERER_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.h"

typedef struct _Screen {
  float scaleX, scaleY;
  SDL_Window * window;
  SDL_Renderer * renderer;
} Screen;

// Function to initalze screen
Screen screenInit(int width, int height, float scaleX, float scaleY);

// Loads the texture to the screen in order to display
SDL_Texture * screenLoadTexture(Screen * screen, const char * filePath);

// Rendering the corresponding entities to screen
void screenRender(Screen * screen, Entity * entity);

#endif // __WINDOW_RENDERER_H__