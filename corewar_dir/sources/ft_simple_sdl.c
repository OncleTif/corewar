/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:18:19 by eozdek            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/05/25 13:44:37 by eozdek           ###   ########.fr       */
=======
/*   Updated: 2016/05/25 18:49:54 by ssicard          ###   ########.fr       */
>>>>>>> 908e8c73faedb1265d2c468bbdf6ac0cdd202a32
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
			init_sdl(sdl);
		else if (i == 1)
		{
			sdl->u = 1;
			ft_disp(sdl, vm);
			SDL_Delay(6000);
			quit(sdl);
		}
	}
}
