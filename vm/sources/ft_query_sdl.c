/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_query_sdl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 01:23:40 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/20 03:47:21 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			ft_QueryPlayerTexture(int i, int j, int nb, t_sdl *sdl)
{
	SDL_QueryTexture(sdl->texturePlayer[i][nb], NULL, NULL, &sdl->rectPlayer[i][nb].w, &sdl->rectPlayer[i][nb].h);
	sdl->rectPlayer[i][nb].x = sdl->solidRect.x;
	sdl->rectPlayer[i][nb].y = sdl->solidRect.y + sdl->solidRect.h + (50 * (j + 2));
}

void 	ft_handleQueryPlayer(t_sdl *sdl, t_vm *vm)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 5;
	while (i < vm->bplr.nb_plyr)
	{
		k = 0;
		while (k < 2)
		{
			ft_QueryPlayerTexture(i, j, k++, sdl);
			j++;
		}
		j++;
		i++;
	}
}

void ft_QueryBaseTexture(t_sdl *sdl)
{
	int i;

	i = 0;
	while (i < 5)
	{
		SDL_QueryTexture(sdl->textureTab[i], NULL, NULL, &sdl->textureRect[i].w, &sdl->textureRect[i].h);
		sdl->textureRect[i].x = sdl->solidRect.x;
		sdl->textureRect[i].y = sdl->solidRect.y + sdl->solidRect.h + (50 * i);
		i++;
	}
}

void ft_QuerySolidTexture(t_sdl *sdl)
{
	SDL_Surface* solid = TTF_RenderText_Blended(sdl->font, "COREWAR GAME", backgroundColor);
	sdl->solidTexture = SurfaceToTexture(solid, sdl->renderer);
	SDL_QueryTexture(sdl->solidTexture, NULL, NULL, &sdl->solidRect.w, &sdl->solidRect.h);
	sdl->solidRect.x = 1350;
	sdl->solidRect.y = 20;
}
