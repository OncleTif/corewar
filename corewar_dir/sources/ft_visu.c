/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 03:17:11 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/22 01:24:12 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
fichier pour afficher le joureur gagnant
*/

void initSdl(t_sdl *sdl)
{
	sdl->tplayer = 0;
	sdl->u = 0;
	sdl->aff = 0;
	sdl->s = 0;
	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->fontname = ft_strdup("SDL/open-sans/OpenSans-Bold.ttf");
}

SDL_Color ft_make_color(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color c = {r, g, b, 255};
	return (c);
}

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

	(void)vm;
	str = ft_strjoin("Contestant ", ft_itoa(tmp));
	str = ft_strjoin(str, " ");
	str2 = ft_strjoin(win, ", has won !");
	str = ft_strjoin(str, str2);
	last = TTF_RenderText_Blended(sdl->font, str, color2);
	sdl->lastTexture = SurfaceToTexture(last, sdl->renderer);
	SDL_QueryTexture(sdl->lastTexture, NULL, NULL, &sdl->lastRect.w, &sdl->lastRect.h);
	sdl->lastRect.x = 1325;
	sdl->lastRect.y = 1000;
}
