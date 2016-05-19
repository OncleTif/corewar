/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:40:29 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/19 20:06:44 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

SDL_Rect solidRect;
SDL_Rect blendedRect;
SDL_Rect shadedRect;
SDL_Rect textureRect[10];
SDL_Rect rectPlayer[4][3];
TTF_Font* font;
SDL_Color textColor = {255, 255, 255, 255}; // white
SDL_Color backgroundColor = {0, 0, 0, 255}; // black
SDL_Color color1 = {2, 200, 22, 255};
SDL_Color color2 = {13, 13, 242, 255};
SDL_Color color3 = {228, 215, 42, 255};
SDL_Color color4 = {255, 0, 45, 255};
SDL_Texture* solidTexture;
SDL_Texture* blendedTexture;
SDL_Texture* shadedTexture;
SDL_Texture* textureTab[10];
SDL_Texture* texturePlayer[4][3];
SDL_Surface* player[4][3];

SDL_Texture*	SurfaceToTexture( SDL_Surface* surf, SDL_Renderer *renderer)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf );
	SDL_FreeSurface( surf );
	return text;
}

void			print_grid(int i, int j, int nb)
{
	SDL_QueryTexture(texturePlayer[i][nb], NULL, NULL, &rectPlayer[i][nb].w, &rectPlayer[i][nb].h);
	rectPlayer[i][nb].x = solidRect.x;
	rectPlayer[i][nb].y = solidRect.y + solidRect.h + (50 * (j + 2));
}

void	print_plr(char *str, int nb, int j, SDL_Renderer *renderer)
{
	if (j == 0 && nb == 0)
		player[j][nb] = TTF_RenderText_Blended(font, str, color1);
	else if (j == 1 && nb == 0)
		player[j][nb] = TTF_RenderText_Blended(font, str, color2);
	else if (j == 2 && nb == 0)
		player[j][nb] = TTF_RenderText_Blended(font, str, color3);
	else if (j == 3 && nb == 0)
		player[j][nb] = TTF_RenderText_Blended(font, str, color4);
	else
		player[j][nb] = TTF_RenderText_Blended(font, str, textColor);
	texturePlayer[j][nb] = SurfaceToTexture(player[j][nb], renderer);
	free(str);
}

void CreateTextTextures(SDL_Renderer *renderer, t_vm *vm)
{
	// SDL_Color color = {255, 0, 255, 0};
	SDL_Surface* texture[10];

	SDL_Surface* solid = TTF_RenderText_Blended(font, "COREWAR GAME", backgroundColor);
	solidTexture = SurfaceToTexture(solid, renderer);
	char *str;
	int j;
	int i;
	t_list_player *cur = vm->bplr.lst_plyr;

	SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 1350;
	solidRect.y = 20;
	j = 0;
	while (j < 5)
	{
		if (j == 0)
			str = ft_strjoin("Cycle : ", ft_itoa(CPU.cur_cycle));
		else if (j == 1)
			str = ft_strjoin("CYCLE_TO_DIE : ", ft_itoa(CPU.cycle2die));
		else if (j == 2)
			str = ft_strjoin("CYCLE_DELTA : ", ft_itoa(CYCLE_DELTA));
		else if (j == 3)
			str = ft_strjoin("NBR_LIVE : ", ft_itoa(vm->nbr_live));
		else if (j == 4)
			str = ft_strjoin("MAX_CHECKS : ", ft_itoa(MAX_CHECKS));
		texture[j] = TTF_RenderText_Blended(font, str, textColor);
		textureTab[j] = SurfaceToTexture(texture[j], renderer);
		free(str);
		j++;
	}
	j = 0;
	while (j < vm->bplr.nb_plyr)
	{
		str = ft_strjoin("Player ", ft_itoa(j + 1));
		str = ft_strjoin(str, " : ");
		str = ft_strjoin(str, cur->plr->name);
		print_plr(str, 0, j, renderer);
		str = ft_strjoin("Last live : ", ft_itoa(cur->plr->last_live));
		print_plr(str, 1, j, renderer);
		str = ft_strjoin("Live in current period : ", " ");
		print_plr(str, 2, j, renderer);
		cur = cur->next;
		j++;
	}
	i = 0;
	while (i < 5)
	{
		SDL_QueryTexture(textureTab[i], NULL, NULL, &textureRect[i].w, &textureRect[i].h);
		textureRect[i].x = solidRect.x;
		textureRect[i].y = solidRect.y + solidRect.h + (50 * i);
		i++;
	}
	i = 0;
	int k;
	while (i < vm->bplr.nb_plyr)
	{
		k = 0;
		while (k < 3)
		{
			print_grid(i, j, k++);
			j++;
		}
		j++;
		i++;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, 100, 400, 1600, 50);
}

void Render(SDL_Renderer *renderer, t_vm *vm)
{
	SDL_RenderCopy(renderer, solidTexture, NULL, &solidRect);
	int i = 0;
	while (i < 5)
	{
		SDL_RenderCopy(renderer, textureTab[i], NULL, &textureRect[i]);
		i++;
	}
	i = 0;
	while (i < vm->bplr.nb_plyr)
	{
		SDL_RenderCopy(renderer, texturePlayer[i][0], NULL, &rectPlayer[i][0]);
		SDL_RenderCopy(renderer, texturePlayer[i][1], NULL, &rectPlayer[i][1]);
		SDL_RenderCopy(renderer, texturePlayer[i][2], NULL, &rectPlayer[i][2]);
		i++;
	}
}


int SetupTTF(char *fontName)
{
	if (TTF_Init() == -1)
	{
		printf("error");
		return false;
	}
	font = TTF_OpenFont(fontName, 30);
	if (font == NULL)
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

void render_line(SDL_Rect rect[4096], SDL_Renderer *renderer, t_vm *vm)
{
	int x;
	int y;
	int i;
	(void)vm;
	x = 20;
	y = 20;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
		{
			x = 20;
			y += 20;
		}
		if(vm->data[i].pc)
			SDL_SetRenderDrawColor(renderer, 40, 209, 214, 255);
		else if (vm->data[i].num_plr == (int)vm->bplr.tab[0])
			SDL_SetRenderDrawColor(renderer, 2, 200, 22, 255);
		else if (vm->data[i].num_plr == (int)vm->bplr.tab[1])
			SDL_SetRenderDrawColor(renderer, 13, 13, 242, 255);
		else if (vm->data[i].num_plr == (int)vm->bplr.tab[2])
			SDL_SetRenderDrawColor(renderer, 228, 215, 42, 255);
		else if (vm->data[i].num_plr == (int)vm->bplr.tab[3])
			SDL_SetRenderDrawColor(renderer, 255, 0, 45, 255);
		else
			SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		rect[i].x = x;
		rect[i].y = y;
		rect[i].w = 15;
		rect[i].h = 15;
		x += 20;
		SDL_RenderFillRect(renderer, &rect[i]);
		i++;

	}
	Render(renderer, vm);
}

void init_sdl(SDL_Window **window, SDL_Renderer **renderer)
{
	init(window, renderer);
	SetupTTF( "../../SDL/open-sans/OpenSans-Bold.ttf" );
}

int disp(SDL_Window* window, SDL_Renderer* renderer, t_vm *vm)
{
	SDL_Event event;
	SDL_Rect rect[4096];
	(void)window;
	CreateTextTextures(renderer, vm);
	SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
	SDL_RenderClear(renderer);
	render_line(rect, renderer, vm);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || event.type == SDLK_ESCAPE)
		{
			TTF_CloseFont( font );
			quit(window, renderer);
			exit(0);
		}
	}
	SDL_RenderPresent(renderer);
	return (0);
}
