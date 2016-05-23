/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_sdl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 01:06:59 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/23 16:47:20 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

SDL_Texture*	SurfaceToTexture(SDL_Surface* surf, SDL_Renderer *renderer)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	return text;
}

void			playerTexture(char *str, int nb, int j, t_sdl *sdl)
{
	if (j == 0 && nb == 0)
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, color1);
	else if (j == 1 && nb == 0)
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, color2);
	else if (j == 2 && nb == 0)
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, color3);
	else if (j == 3 && nb == 0)
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, color4);
	else
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, textColor);
	sdl->texPlay[j][nb] = SDL_CreateTextureFromSurface(sdl->renderer, sdl->player[j][nb]);
	free(str);
}

void 	ft_handleBaseTexture(t_sdl *sdl, t_vm *vm, SDL_Surface* texture[5])
{
	int j;
	char *str;

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
		texture[j] = TTF_RenderText_Blended(sdl->font, str, textColor);
		sdl->textureTab[j] = SDL_CreateTextureFromSurface(sdl->renderer, texture[j]);
		free(str);
		j++;
	}
}

int 			ft_handlePlayerTexture(t_sdl *sdl, t_vm *vm)
{
	t_list_player *cur = vm->bplr.lst_plyr;
	char *str;
	int j;
	int i;

	j = 0;
	i = 0;
	while (j < vm->bplr.nb_plyr)
	{
		str = ft_strjoin("Player ", ft_itoa(j + 1));
		str = ft_strjoin(str, " : ");
		str = ft_strjoin(str, cur->plr->name);
		playerTexture(str, 0, j, sdl);
		str = ft_strjoin("Last live : ", ft_itoa(cur->plr->last_live));
		playerTexture(str, 1, j, sdl);
		// str = ft_strjoin("Live in current period : ", " ");
		// playerTexture(str, 2, j, sdl);
		cur = cur->next;
		j++;
	}
	return (j);
}

void	CreateTextTextures(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface *solid;
	SDL_Surface *texture[5];
	int i;
	int tmp;
	t_bin *win;

	tmp = 0;
	solid = NULL;
	win = NULL;
	i = 0;
	// ft_putchar('c');
	ft_QuerySolidTexture(sdl, solid);
	// ft_putchar('d');
	ft_handleBaseTexture(sdl, vm, texture);
	// ft_putchar('e');
	ft_handlePlayerTexture(sdl, vm);
	// ft_putchar('f');
	ft_QueryBaseTexture(sdl);
	// ft_putchar('g');
	ft_handleQueryPlayer(sdl, vm);
	// ft_putchar('h');
	win = who_win(vm);
	if (win->num_plyr < 0)
		tmp = (-1 * win->num_plyr);
	else
		tmp = win->num_plyr;
	createLastTexture(sdl, vm, tmp, win->prog_name);
}
