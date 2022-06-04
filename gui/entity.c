#include "entity.h"

Entity entityInit(int x, int y, int width, int height, SDL_Texture * texture) {

  Entity entity;
  entity.position[0] = x;
  entity.position[1] = y;
  entity.texture = texture;

  entity.frame.x = 0;
  entity.frame.y = 0;
  entity.frame.w = width;
  entity.frame.h = height;
  
  return entity;
}

void entityChangeTexture(Entity * entity, SDL_Texture * texture) {
  entity->texture = texture;
}
