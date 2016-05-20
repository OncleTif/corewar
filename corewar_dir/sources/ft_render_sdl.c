/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 01:25:56 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/20 03:47:48 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_render(t_sdl *sdl, t_vm *vm)
{
	SDL_RenderCopy(sdl->renderer, sdl->solidTexture, NULL, &sdl->solidRect);
	int i;

	i = 0;
	while (i < 5)
	{
		SDL_RenderCopy(sdl->renderer, sdl->textureTab[i], NULL, &sdl->textureRect[i]);
		i++;
	}
	i = 0;
	while (i < vm->bplr.nb_plyr)
	{
		SDL_RenderCopy(sdl->renderer, sdl->texturePlayer[i][0], NULL, &sdl->rectPlayer[i][0]);
		SDL_RenderCopy(sdl->renderer, sdl->texturePlayer[i][1], NULL, &sdl->rectPlayer[i][1]);
		// SDL_RenderCopy(sdl->renderer, sdl->texturePlayer[i][2], NULL, &sdl->rectPlayer[i][2]);
		i++;
	}
}

void 	ft_case_color(t_vm *vm, t_sdl *sdl, int i)
{
	if(vm->data[i].pc)
		SDL_SetRenderDrawColor(sdl->renderer, 40, 209, 214, 255);
	else if (vm->data[i].num_plr == (int)vm->bplr.tab[0])
		SDL_SetRenderDrawColor(sdl->renderer, 2, 200, 22, 255);
	else if (vm->data[i].num_plr == (int)vm->bplr.tab[1])
		SDL_SetRenderDrawColor(sdl->renderer, 13, 13, 242, 255);
	else if (vm->data[i].num_plr == (int)vm->bplr.tab[2])
		SDL_SetRenderDrawColor(sdl->renderer, 228, 215, 42, 255);
	else if (vm->data[i].num_plr == (int)vm->bplr.tab[3])
		SDL_SetRenderDrawColor(sdl->renderer, 255, 0, 45, 255);
	else
		SDL_SetRenderDrawColor(sdl->renderer, 200, 200, 200, 255);
}

void	render_line(t_sdl *sdl, t_vm *vm)
{
	int x;
	int y;
	int i;

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
		ft_case_color(vm, sdl, i);
		sdl->rect[i].x = x;
		sdl->rect[i].y = y;
		sdl->rect[i].w = 17;
		sdl->rect[i].h = 17;
		x += 20;
		SDL_RenderFillRect(sdl->renderer, &sdl->rect[i]);
		i++;
	}
	ft_render(sdl, vm);
}
