/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 03:17:11 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/23 14:16:01 by eozdek           ###   ########.fr       */
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

// void	renderLast(t_sdl *sdl, t_vm *vm)
// {
	// (void)vm;
	// SDL_RenderCopy(sdl->renderer, sdl->lastT, NULL, &sdl->lastRect);
// }

void 	createLastTexture(t_sdl *sdl, t_vm *vm, int tmp, char *win)
{
	SDL_Surface* last[3];
	char *str;
	int i;

	i = 0;
	(void)vm;
	ft_putendl("\n\n\n\n\n\nhello\n\n\n\n\n\n");
	while (i < 3)
	{
		if (i == 0)
			str = ft_strjoin("Contestant ", ft_itoa(tmp));
		else if (i == 1)
			str = ft_strjoin(win, ",");
		else if (i == 2)
			str = ft_strdup("has won !");
		last[i] = TTF_RenderText_Blended(sdl->font, str, color2);
		sdl->lastT[i] = SurfaceToTexture(last[i], sdl->renderer);
		SDL_QueryTexture(sdl->lastT[i], NULL, NULL, &sdl->lastRect[i].w, &sdl->lastRect[i].h);
		sdl->lastRect[i].x = 1325;
		sdl->lastRect[i].y = 1000 + (i * 50);
		i++;
	}
	ft_putendl("\n\n\n\n\n\nhello\n\n\n\n\n\n");
}
