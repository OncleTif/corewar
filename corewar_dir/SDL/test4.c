#include <SDL/SDL.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	SDL_Window *window;

	window = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL window !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	SDL_DestroyWindow(window);

	SDL_Quit();
	return (0);
}
