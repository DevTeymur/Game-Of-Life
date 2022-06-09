#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "gui/map.c"

int main(int argc, char * argv[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		printf("SDL init failed. Error: %s\n", SDL_GetError());
	}

	if (IMG_Init(IMG_INIT_PNG) == 0) {
		printf("IMG init failed. Error: %s\n", SDL_GetError());
	}

	srand(getpid());
	
	int size;
	printf("Enter the size(which represents the amount of rows and columns) of the board to start: ");
	scanf("%d", &size);

	Map map = mapCreate(size*3, size*3, size, size);

	startGame(&map);

	return 0;
}