#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL_image.h>
#define WIDTH 640
#define HEIGHT 480

SDL_Window* window;
SDL_Surface* screen;
SDL_Surface* image;

int init()
{
	int flags;
	int status;
	int img_flags;
	int x;
	int y;

	flags = SDL_INIT_VIDEO;
	status = SDL_Init(flags);
	img_flags = 0;
	x = SDL_WINDOWPOS_UNDEFINED;
	y = SDL_WINDOWPOS_UNDEFINED;
	if (status == 0)
	{
		img_flags = IMG_INIT_PNG;
		IMG_Init(img_flags);
		window = SDL_CreateWindow("SDL window", x, y, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (window)
		{
			screen = SDL_GetWindowSurface(window);
			image = IMG_Load("emoticone.png");
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_render()
{
	SDL_Surface*	source;
	SDL_Rect*		sourceRegion;
	SDL_Surface*	destination;
	SDL_Rect		*destinationRegion;

	source = image;
	sourceRegion = NULL;
	destination = screen;
	destinationRegion = NULL;
	SDL_BlitSurface(source, sourceRegion, destination, destinationRegion);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(5000);
}

void	quit()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char **argv)
{

	if (init() == 0)
		return (0);
	else
	{
		ft_render();

		quit();
	}
	return (0);
}
