/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:18:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/26 13:00:42 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		ft_init_sdl_cpu(t_sdl *sdl, t_vm *vm)
{
	if (vm->visu == 1)
	{
		init_sdl_window(sdl);
	}
}

void		ft_quit_sdl_cpu(t_sdl *sdl, t_vm *vm)
{
	if (vm->visu == 1)
	{
		sdl->u = 1;
		ft_disp(sdl, vm);
		SDL_Delay(3000);
		quit(sdl);
	}
}
