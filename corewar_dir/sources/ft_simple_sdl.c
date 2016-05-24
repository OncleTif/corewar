/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:18:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/24 13:00:17 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		ft_simple_sdl(t_sdl *sdl, t_vm *vm, int i)
{
	int j;

	j = 0;
	if (i == 0)
	{
		if (vm->visu == 1)
			init_sdl(sdl);
	}
	else if (i == 1)
	{
		if (vm->visu == 1)
		{
			sdl->u = 1;
			while (1)
			{
				j++;
				if (j == 1)
					ft_disp(sdl, vm);
				if (sdl->u == 0)
					break ;
			}
		}
	}
}
