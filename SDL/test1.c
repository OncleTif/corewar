#include <unistd.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


// int main(int argc, char **argv)
// {
// 	SDL_Init(SDL_INIT_VIDEO);
// 	SDL_Surface *fenetre;
//
// 	fenetre = NULL;
// 	fenetre = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
// 	SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 255, 0, 0));
// 	while (1)
// 	{
// 		SDL_Event event;
// 		SDL_WaitEvent(&event);
// 		if (event.type == SDL_QUIT)
// 		{
// 			break ;
// 		}
// 	}
// 	return (0);
// }
//
//
// int main(int argc, char **argv)
// {
// 	SDL_Window	*win;
// 	SDL_Surface	*winSurface;
// 	// SDL_Surface	*image1;
// 	// SDL_Surface	*image2;
// 	// SDL_Surface	*currentImage;
// 	SDL_Renderer* renderer = NULL;
// 	// SDL_SurfaceImage;
// 	SDL_Texture* image;
// 	SDL_Event mainEvent;
// 	int i;
//
// 	i = 1;
// 	win = NULL;
// 	winSurface = NULL;
// 	// image1 = SDL_LoadBMP("panda.bmp");
// 	// image2 = SDL_LoadBMP("WILDBOAR.bmp");
// 	// image3 = SDL_LoadBMP("test2.bmp");
// 	// currentImage = image1;
// 	SDL_Init(SDL_INIT_VIDEO);
// 	win = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
// 	winSurface = SDL_GetWindowSurface(win);
// 	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
// 	image = IMG_LoadTexture(renderer, "bricks.bmp");
// 	SDL_Rect grass_rect;
// 	grass_rect.x = 10;
// 	grass_rect.y = 50;
// 	grass_rect.w = 250;
// 	grass_rect.h = 250;
// 	while (1)
// 	{
// 		SDL_PollEvent(&mainEvent);
// 		SDL_RenderClear(renderer);
// 		SDL_RenderCopy(renderer, &grass_image, NULL, &grass_rect);
// 		SDL_RenderPresent(renderer);
// 		if (mainEvent.type == SDL_QUIT)
// 			break ;
// 	}
// 	// SDL_Delay(2000);
// 	SDL_DestroyWindow(win);
// 	SDL_DestroyRenderer(renderer);
// 	return (0);
// }
//
//
// int main(int argc, char **argv)
// {
// 	SDL_Init(SDL_INIT_VIDEO);
// 	SDL_Surface *fenetre;
//
// 	fenetre = NULL;
// 	fenetre = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
// 	SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 255, 0, 0));
// 	while (1)
// 	{
// 		SDL_Event event;
// 		SDL_WaitEvent(&event);
// 		if (event.type == SDL_QUIT)
// 		{
// 			break ;
// 		}
// 	}
// 	return (0);
// }

int main(int argc, char **argv)
{
	SDL_Window	*win;
	SDL_Surface	*winSurface;
	// SDL_Surface	*image1;
	// SDL_Surface	*image2;
	// SDL_Surface	*currentImage;
	SDL_Renderer* renderer = NULL;
	// SDL_SurfaceImage;
	SDL_Texture* image;
	SDL_Event mainEvent;
	int i;

	i = 1;
	win = NULL;
	winSurface = NULL;
	// image1 = SDL_LoadBMP("panda.bmp");
	// image2 = SDL_LoadBMP("WILDBOAR.bmp");
	// image3 = SDL_LoadBMP("test2.bmp");
	// currentImage = image1;
	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	winSurface = SDL_GetWindowSurface(win);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	image = IMG_LoadTexture(renderer, "bricks.bmp");
	SDL_Rect grass_rect;
	grass_rect.x = 10;
	grass_rect.y = 50;
	grass_rect.w = 250;
	grass_rect.h = 250;
	while (1)
	{
		SDL_PollEvent(&mainEvent);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, &grass_image, NULL, &grass_rect);
		SDL_RenderPresent(renderer);
		if (mainEvent.type == SDL_QUIT)
			break ;
	}
	// SDL_Delay(2000);
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(renderer);
	return (0);
}
// while (i == 1)
// {
// 	while (SDL_PollEvent(&event) != 0)
// 	{
// 		if (event.type == SDL_QUIT)
// 			i = 0;
// 		// else if (event.type == SDL_KEYDOWN)
// 		// {
// 		// 	if (event.key.keysym.sym == SDLK_1)
// 		// 		currentImage = image1;
// 		// 	else if (event.key.keysym.sym == SDLK_2)
// 		// 		currentImage = image2;
// 		// 		// case SDLK_3:
// 		// 		// 	currentImage = image3;
// 		// 		// 	break ;
// 		// }
// 		else if (event.type == SDL_MOUSEBUTTONDOWN)
// 		{
// 			if (event.button.button == SDL_BUTTON_LEFT)
// 				currentImage = image1;
// 			else if (event.button.button == SDL_BUTTON_RIGHT)
// 				currentImage = image2;
// 		}
// 	}
// 	// SDL_UptadeWindowSurface(win);
// 	SDL_BlitSurface(currentImage, NULL, winSurface, NULL);
// 	SDL_GetWindowSurface(win);
// }
// while (1)
// {
// 	// SDL_Event event;
// 	SDL_WaitEvent(&event);
// 	if (event.type == SDL_QUIT)
// 	{
// 		break ;
// 	}
// }
// SDL_FreeSurface(image1);
// SDL_FreeSurface(image2);
// SDL_FreeSurface(image3);
// imgSurface = SDL_LoadBMP("");
// SDL_UptadeWindowSurface(win);
