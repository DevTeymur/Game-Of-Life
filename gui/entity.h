#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <SDL2/SDL.h>

typedef struct _Entity {
  int position[2];
  SDL_Rect frame;
  SDL_Texture * texture;
} Entity;

// Fuction to initialize entity with necessary components
Entity entityCreate(int x, int y, int width, int height, SDL_Texture * texture);

// Function to change texture(color) of the frame obeying the rules
void entityChangeTexture(Entity * entity, SDL_Texture * texture);

#endif // __ENTITY_H__