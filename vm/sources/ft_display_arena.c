/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:40:29 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/18 18:25:44 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include <SDL2/SDL.h>
#include <../../SDL/SDL2_image.framework/Headers/SDL_image.h>
#include <../../SDL/SDL2_ttf.framework/Headers/SDL_ttf.h>
#define false 0
#define true 1

SDL_Rect solidRect; // Ajout
SDL_Rect blendedRect;
SDL_Rect shadedRect;
SDL_Rect textureRect[10];
TTF_Font* font;
SDL_Color textColor = {255, 255, 255, 255}; // white
SDL_Color backgroundColor = {0, 0, 0, 255}; // black
SDL_Texture* solidTexture;
SDL_Texture* blendedTexture;
SDL_Texture* shadedTexture;
SDL_Texture* textureTab[10];

SDL_Texture* SurfaceToTexture( SDL_Surface* surf, SDL_Renderer *renderer)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf );
	SDL_FreeSurface( surf );
	return text;
}

void CreateTextTextures(SDL_Renderer *renderer, int j)
{
	SDL_Color color = {255, 0, 255, 0};
	SDL_Surface* texture[10];
	SDL_Surface* solid = TTF_RenderText_Blended(font, "COREWAR GAME", color);
	solidTexture = SurfaceToTexture(solid, renderer);

	// *textureRect = (SDL_Surface*)malloc(sizeof(SDL_Surface) * 10);
	SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 1350;
	solidRect.y = 20;


	// SDL_Surface* blended = TTF_RenderText_Blended(font, "Cycles/second Limit : ", textColor);
	// blendedTexture = SurfaceToTexture( blended, renderer);
	char *str;
	int i = 0;
	str = ft_strjoin("Cycle : ", ft_itoa(j));
	texture[0] = TTF_RenderText_Blended(font, str, textColor);
	textureTab[0] = SurfaceToTexture(texture[0], renderer);
	texture[1] = TTF_RenderText_Blended(font, "Processes : ", textColor);
	textureTab[1] = SurfaceToTexture(texture[1], renderer);

	// une fonction pour les players un tableau de textures
	texture[2] = TTF_RenderText_Blended(font, "Player 1 : ", textColor);
	textureTab[2] = SurfaceToTexture(texture[2], renderer);
	texture[3] = TTF_RenderText_Blended(font, "Last live : ", textColor);
	textureTab[3] = SurfaceToTexture(texture[3], renderer);
	texture[4] = TTF_RenderText_Blended(font, "Live in current period : ", textColor);
	textureTab[4] = SurfaceToTexture(texture[4], renderer);

	//fin joueur
	texture[5] = TTF_RenderText_Blended(font, "CYCLE_TO_DIE : ", textColor);
	textureTab[5] = SurfaceToTexture(texture[5], renderer);
	texture[6] = TTF_RenderText_Blended(font, "CYCLE_DELTA : ", textColor);
	textureTab[6] = SurfaceToTexture(texture[6], renderer);
	texture[7] = TTF_RenderText_Blended(font, "NBR_LIVE : ", textColor);
	textureTab[7] = SurfaceToTexture(texture[7], renderer);
	texture[8] = TTF_RenderText_Blended(font, "MAX_CHECKS : ", textColor);
	textureTab[8] = SurfaceToTexture(texture[8], renderer);
	i = 0;

	while (i < 8)
	{
		SDL_QueryTexture(textureTab[i], NULL, NULL, &textureRect[i].w, &textureRect[i].h);
		textureRect[i].x = solidRect.x;
		textureRect[i].y = solidRect.y + solidRect.h + (50 * i);
		i++;
	}

	// SDL_Surface* shaded = TTF_RenderText_Shaded(font, "visu", textColor, backgroundColor);
	// shadedTexture = SurfaceToTexture( shaded, renderer);

	// SDL_QueryTexture(shadedTexture , NULL, NULL, &shadedRect.w, &shadedRect.h);
	// shadedRect.x = solidRect.x;
	// shadedRect.y = blendedRect.y + blendedRect.h + 20;
}


void Render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, solidTexture, NULL, &solidRect);
	int i = 0;
	while (i < 8)
	{
		SDL_RenderCopy(renderer, textureTab[i], NULL, &textureRect[i]);
		i++;
	}
}


int SetupTTF(char *fontName)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if ( TTF_Init() == -1 )
	{
		printf("error");
		return false;
	}
	// Load our fonts, with a huge size
	font = TTF_OpenFont(fontName, 30);
	// Error check
	if ( font == NULL )
	{
		printf("error");
		return false;
	}
	return true;
}

void init(SDL_Window **window, SDL_Renderer **renderer)
{
	SDL_Init(SDL_INIT_VIDEO);
	int x;
	int y;

	x = SDL_WINDOWPOS_CENTERED;
	y = SDL_WINDOWPOS_CENTERED;
	*window = SDL_CreateWindow("SDL Window", x, y, 2000, 3000, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	// SDL_RenderSetLogicalSize(*renderer, 2000, 3000 ); // Ajout
}

void quit(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void render_line(SDL_Rect rect[4096], SDL_Renderer *renderer)
{
	int column;
	int x;
	int y;

	x = 20;
	y = 20;
	column = 0;
	while (column < 4096)
	{
		if (column % 64 == 0 && column != 0)
		{
			x = 20;
			y += 20;
		}
		SDL_SetRenderDrawColor(renderer, 20, 20, 20, 20);
		rect[column].x = x;
		rect[column].y = y;
		rect[column].w = 15;
		rect[column].h = 15;
		x += 20;
		SDL_RenderFillRect(renderer, &rect[column]);
		column++;

	}
	Render(renderer);
}

int disp()
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	SDL_Rect rect[4096];
	int i;
	int j;

	j = 0;
	i = 0;
	init(&window, &renderer);
	SetupTTF( "../../SDL/open-sans/OpenSans-Bold.ttf" );
	while (i == 0)
	{
		CreateTextTextures(renderer, j);
		SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
		SDL_RenderClear(renderer);
		render_line(rect, renderer);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				i = 1;
				break ;
			}
		}
		if (j > 5000)
			break ;
		j++;
		SDL_RenderPresent(renderer);
	}
	TTF_CloseFont( font );
	quit(window, renderer);
	return (0);
}
