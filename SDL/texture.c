#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main()
{
	SDL_Window *window = NULL;
	SDL_Texture *currentImage = NULL;
	SDL_Renderer *renderTarget = NULL;
	SDL_Rect playerRect;
	SDL_Rect playerPosition;
	playerPosition.x = playerPosition.y = 0;
	playerPosition.w = playerPosition.h = 32;
	int frameWidth, frameHeight;
	int textureWidth, textureHeight;
	float frameTime = 0;
	int prevTime = 0;
	int currentTime = 0;
	float deltaTime = 0;
	const Uint8 *keyState;


	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	TTF_Init();
	TTF_Font *font = TTF_OpenFont("./open-sans/OpenSans-Bold.ttf", 20);
	SDL_Color color = {0, 255, 0, 255};
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, "blabla", color);
	SDL_Texture *text = SDL_CreateTextureFromSurface(renderTarget, textSurface);
	SDL_Rect textRect;
	textRect.x = textRect.y = 0;

	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);

	SDL_RenderClear(renderTarget);
	SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
	SDL_RenderCopy(renderTarget, text, NULL, &textRect);
	SDL_RenderPresent(renderTarget);

	SDL_Quit();
	return (0);
}
