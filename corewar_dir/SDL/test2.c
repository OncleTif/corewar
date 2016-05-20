
#include <SDL2/SDL.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define WIDTH 500
#define HEIGHT 500
#define BOX_H 64
#define BOX_W 64

void 	ft_putchar(char c)
{
	write (1, &c, 1);
}

void init(SDL_Window **window, SDL_Renderer **renderer)
{
	SDL_Init(SDL_INIT_VIDEO);
	int x;
	int y;

	x = SDL_WINDOWPOS_CENTERED;
	y = SDL_WINDOWPOS_CENTERED;
	*window = SDL_CreateWindow("SDL Window", x, y, 900, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
}

void quit(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int ft_event(int *i, SDL_Event *event)
{
	// SDL_Event event;

	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT)
		{
			*i = 1;
		}
		else if (event->type == SDL_MOUSEBUTTONDOWN)
		{
			// mouseDown = 1;
			return (1);
		}
		else if (event->type == SDL_MOUSEBUTTONUP)
		{
			// mouseDown = 0;
			return (0);
		}
	}
	return (0);
}

int click_color(int *i, SDL_Event event)
{
	int mouseDown;

	mouseDown = 0;
	if (event.type == SDL_QUIT)
	{
		*i = 1;
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		mouseDown = 1;
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		mouseDown = 0;
	}
	return (mouseDown);
}

int main()
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect rect;
	SDL_Rect rect1;
	int i;
	int mouseX;
	int mouseY;
	int mouseDown;
	SDL_Event event;

	i = 0;
	mouseDown = 0;
	init(&window, &renderer);
	while (i == 0)
	{

		while (SDL_PollEvent(&event))
		{
			// mouseDown = click_color(&i, event);
			if (event.type == SDL_QUIT)
			{
				i = 1;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				mouseDown = 1;
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				mouseDown = 0;
			}
		}
		// mouseDown = ft_event(&i, &event);
		SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
		SDL_RenderClear(renderer);
		rect.x = 50;
		rect.y = 50;
		rect.w = 50;
		rect.h = 50;
		SDL_RenderFillRect(renderer, &rect);

		SDL_GetMouseState(&mouseX, &mouseY);
		rect.x = mouseX - BOX_W / 2;
		rect.y = mouseY - BOX_H / 2;
		rect.w = BOX_W;
		rect.h = BOX_H;
		if (mouseDown == 1)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
			// SDL_Delay(1000);
			// SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		}
		else
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		// SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderFillRect(renderer, &rect);
		rect1.x = 50;
		rect1.y = 50;
		rect1.w = 100;
		rect1.h = 100;
		SDL_RenderFillRect(renderer, &rect1);
		
		SDL_RenderPresent(renderer);
	}
	quit(window, renderer);
	return (0);
}
