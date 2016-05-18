#include <SDL2/SDL.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define WIDTH 500
#define HEIGHT 500

SDL_Window *window;
SDL_Renderer* renderer;

int i;
int left;
int right;
int mouseX;
int mouseY;
int prevX;
int prevY;

void init()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void render()
{
	prevX = mouseX;
	prevY = mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	if (left)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		// SDL_RenderDrawPoint(renderer, mouseX, mouseY);
		SDL_RenderDrawLine(renderer, prevX, prevY, mouseX, mouseY);
	}
	else if (right)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		// SDL_RenderDrawPoint(renderer, mouseX, mouseY);
		SDL_RenderDrawLine(renderer, prevX, prevY, mouseX, mouseY);
	}
	SDL_RenderPresent(renderer);
}

void setButtonState(Uint8 button, int j)
{
	if (button == SDL_BUTTON_LEFT)
	{
		left = j;
	}
	else if (button == SDL_BUTTON_RIGHT)
	{
		right = j;
	}
}

void handleEvent(SDL_Event event)
{
	if (event.type == SDL_QUIT)
	{
		i = 0;
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		setButtonState(event.button.button, 1);
		render();
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		setButtonState(event.button.button, 0);
		render();
	}
	else if (event.type == SDL_MOUSEMOTION)
	{
		render();
	}
}

void loop()
{
	SDL_Event event;

	while (i == 1)
	{
		while (SDL_PollEvent(&event))
		{
			handleEvent(event);
		}
	}
}



void clear()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

int main()
{
	i = 1;
	left = 0;
	right = 0;
	// if (!init())
	// 	return (0);
	init();
	clear();
	loop();
	quit();
	return (0);
}
