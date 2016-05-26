/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:40:29 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/26 12:15:36 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		ft_setup_ttf(t_sdl *sdl)
{
	if (TTF_Init() == -1)
	{
		ft_printf("TTF Init error");
		return (0);
	}
	sdl->font = TTF_OpenFont(sdl->fontname, 27);
	if (sdl->font == NULL)
	{
		ft_printf("TTF font error");
		return (0);
	}
	return (1);
}

void	init(SDL_Window **window, SDL_Renderer **renderer)
{
	int x;
	int y;

	SDL_Init(SDL_INIT_VIDEO);
	x = SDL_WINDOWPOS_CENTERED;
	y = SDL_WINDOWPOS_CENTERED;
	*window = SDL_CreateWindow("SDL Window", x, y, 1800, 1500,
	SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
}

void	quit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}

void	init_sdl(t_sdl *sdl)
{
	init(&sdl->window, &sdl->renderer);
	ft_setup_ttf(sdl);
}

int		ft_disp(t_sdl *sdl, t_vm *vm)
{
	if (sdl->aff % 23 == 0 || sdl->u == 1)
		create_text_textures(sdl, vm);
	SDL_SetRenderDrawColor(sdl->renderer, 127, 127, 127, 255);
	SDL_RenderClear(sdl->renderer);
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(sdl->renderer, 1325, 10, 1325, 1300);
	SDL_RenderDrawLine(sdl->renderer, 1325, 10, 1750, 10);
	SDL_RenderDrawLine(sdl->renderer, 1750, 10, 1750, 1300);
	SDL_RenderDrawLine(sdl->renderer, 1325, 1300, 1750, 1300);
	render_line(sdl, vm);
	SDL_RenderPresent(sdl->renderer);
	SDL_Delay(sdl->speed);
	ft_poll_event(sdl);
	sdl->aff++;
	return (0);
}
