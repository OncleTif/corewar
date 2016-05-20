/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 03:17:11 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/20 18:28:22 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
fichier pour afficher le joureur gagnant
*/

void initSdl(t_sdl *sdl)
{
	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->fontname = ft_strdup("SDL/open-sans/OpenSans-Bold.ttf");
}

SDL_Color ft_make_color(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color c = {r, g, b, 255};
	return (c);
}
/*
void	renderLast(t_sdl *sdl, t_vm *vm)
{
	(void)vm;
	SDL_RenderCopy(sdl->renderer, sdl->lastTexture, NULL, &sdl->lastRect);
}

void 	createLastTexture(t_sdl *sdl, t_vm *vm, int tmp, char *win)
{
	SDL_Surface *last;
	char *str;
	char *str2;

	str = ft_strjoin("Contestant ", ft_itoa(tmp));
	str2 = ft_strjoin(win, ", has won !\n");
	str = ft_strjoin(str, str2);
	last = TTF_RenderText_Blended(sdl->font, str, backgroundColor);
	sdl->lastTexture = SurfaceToTexture(last, sdl->renderer);
	SDL_QueryTexture(sdl->lastTexture, NULL, NULL, &sdl->lastRect.w, &sdl->lastRect.h);
	sdl->lastRect.x = 1000;
	sdl->lastRect.y = 1000;
	SDL_SetRenderDrawColor(sdl->renderer, 127, 127, 127, 255);
	SDL_RenderClear(sdl->renderer);
	renderLast(sdl, vm);
	free(str);
	free(str2);
}

void	display_winner(t_sdl *sdl, t_vm *vm)
{
	t_bin	*win;
	int		tmp;
	int 	i;

	i = 1;
	win = who_win(vm);
	if (win->num_plyr < 0)
		tmp = (-1 * win->num_plyr);
	else
		tmp = win->num_plyr;
		createLastTexture(sdl, vm, tmp, win->prog_name);
		SDL_SetRenderDrawColor(sdl->renderer, 127, 127, 127, 255);
		SDL_RenderClear(sdl->renderer);
		SDL_Delay(5000);
	SDL_RenderPresent(sdl->renderer);
}


void	renderFirst(t_sdl *sdl, t_vm *vm)
{
	(void)vm;
	SDL_RenderCopy(sdl->renderer, sdl->firstTexture, NULL, &sdl->firstRect);
}

void 	createFirstTexture(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface *first;

	first = TTF_RenderText_Blended(sdl->font, "COREWAR", backgroundColor);
	sdl->firstTexture = SurfaceToTexture(first, sdl->renderer);
	SDL_QueryTexture(sdl->firstTexture, NULL, NULL, &sdl->firstRect.w, &sdl->firstRect.h);
	sdl->firstRect.x = 1000;
	sdl->firstRect.y = 1000;
	SDL_SetRenderDrawColor(sdl->renderer, 127, 127, 127, 255);
	SDL_RenderClear(sdl->renderer);
	renderLast(sdl, vm);
}

void	display_first(t_sdl *sdl, t_vm *vm)
{
	createFirstTexture(sdl, vm);
	SDL_SetRenderDrawColor(sdl->renderer, 127, 127, 127, 255);
	SDL_RenderClear(sdl->renderer);
	// while (SDL_PollEvent(&sdl->event))
	// {
	// 	if (sdl->event.type == SDL_QUIT || sdl->event.key.keysym.sym == SDLK_ESCAPE)
	// 	{
	// 		quit(sdl);
	// 		exit(0);
	// 	}
	// }
	SDL_Delay(4000);
	SDL_RenderPresent(sdl->renderer);
}*/
