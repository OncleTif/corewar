/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:18:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/24 18:01:46 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		ft_simple_sdl(t_sdl *sdl, t_vm *vm, int i)
{
	int j;

	j = 0;
	if (vm->visu == 1)
	{
		if (i == 0)
		{
				init_sdl(sdl);
		}
		else if (i == 1)
		{
			sdl->u = 1;
			ft_disp(sdl, vm);
			SDL_Delay(6000);
			quit(sdl);
		}
	}
}
