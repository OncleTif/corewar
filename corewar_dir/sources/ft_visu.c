/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 03:17:11 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/23 19:07:31 by eozdek           ###   ########.fr       */
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
	// sdl->fontname = ft_strdup("SDL/open-sans/OpenSans-Bold.ttf");
	sdl->fontname = ft_strdup("SDL/Capture-it/Capture_it.ttf");
	// sdl->fontname2 = ft_strdup("SDL/")
}

SDL_Color ft_make_color(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color c = {r, g, b, 255};
	return (c);
}

SDL_Color 	ft_color_player(int color)
{
	if (color == 1)
	{
		return (color1);
	}
	else if (color == 2)
	{
		return (color2);
	}
	else if (color == 3)
	{
		return (color3);
	}
	else if (color == 4)
	{
		return (color4);
	}
	return (color1);
}

void 	createLastTexture(t_sdl *sdl, t_vm *vm, int tmp, char *win)
{
	SDL_Surface* last[3];
	char *str;
	int i;

	i = 0;
	(void)vm;
	while (i < 3)
	{
		if (i == 0)
			str = ft_strjoin("Contestant ", ft_itoa(tmp));
		else if (i == 1)
			str = ft_strjoin(win, ",");
		else if (i == 2)
			str = ft_strdup("has won !");
		last[i] = TTF_RenderText_Blended(sdl->font, str, ft_color_player(tmp));
		sdl->lastT[i] = SurfaceToTexture(last[i], sdl->renderer);
		SDL_QueryTexture(sdl->lastT[i], NULL, NULL, &sdl->lastRect[i].w, &sdl->lastRect[i].h);
		sdl->lastRect[i].x = sdl->solidRect.x - 50;
		sdl->lastRect[i].y = 1000 + (i * 50);
		i++;
	}
}

void			ft_pollEvent(t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->event))
	{
		if (sdl->event.type == SDL_QUIT || sdl->event.key.keysym.sym == SDLK_ESCAPE)
		{
			TTF_CloseFont(sdl->font);
			quit(sdl);
			exit(0);
		}
		else if (sdl->event.key.keysym.sym == SDLK_p)
		{
			sdl->tplayer++;
		}
		else if (sdl->event.key.keysym.sym == SDLK_o)
		{
			sdl->tplayer = 0;
		}
	}
}
