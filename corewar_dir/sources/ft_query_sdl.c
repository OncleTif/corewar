/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_query_sdl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 01:23:40 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/26 13:07:06 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_query_player_texture(int i, int j, int nb, t_sdl *sdl)
{
	SDL_QueryTexture(sdl->texPlay[i][nb], NULL, NULL,
		&sdl->rectPlayer[i][nb].w, &sdl->rectPlayer[i][nb].h);
	if (nb < 2)
		sdl->rectPlayer[i][nb].x = 1370;
	else
		sdl->rectPlayer[i][nb].x = 1540;
	if (nb < 2)
	{
		sdl->rectPlayer[i][nb].y = 20 +
		sdl->solidRect.h + (50 * (j + 2));
	}
	else
	{
		sdl->rectPlayer[i][nb].y = 20 +
		sdl->solidRect.h + (50 * (j + 2));
	}
}

void	ft_handle_query_player(t_sdl *sdl, t_vm *vm)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 5;
	while (i < vm->bplr.nb_plyr)
	{
		k = 0;
		while (k < 3)
		{
			ft_query_player_texture(i, j, k++, sdl);
			if (k < 2)
				j++;
		}
		j++;
		i++;
	}
}

void	ft_query_base_texture(t_sdl *sdl)
{
	int i;

	i = 0;
	while (i < 5)
	{
		SDL_QueryTexture(sdl->textureTab[i], NULL, NULL,
		&sdl->textureRect[i].w, &sdl->textureRect[i].h);
		sdl->textureRect[i].x = sdl->solidRect.x - 50;
		sdl->textureRect[i].y = sdl->solidRect.y + 50 +
		sdl->solidRect.h + (50 * i);
		i++;
	}
}

void	ft_query_corewar_texture(t_sdl *sdl, SDL_Surface *solid)
{
	solid = TTF_RenderText_Blended(sdl->font, "COREWAR GAME", backgroundColor);
	sdl->solidTexture = surface_to_texture(solid, sdl->renderer);
	SDL_QueryTexture(sdl->solidTexture, NULL, NULL,
		&sdl->solidRect.w, &sdl->solidRect.h);
	sdl->solidRect.x = 1420;
	sdl->solidRect.y = 20;
}
