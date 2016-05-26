/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 08:57:19 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/26 15:57:43 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_print_header(t_vm *vm)
{
	t_list_player	*elem;

	elem = vm->bplr.lst_plyr;
	ft_printf("Introducing contestants...\n");
	while (elem)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				elem->plr->index_plyr, elem->plr->size, elem->plr->name,
				elem->plr->com);
		elem = elem->next;
	}
	if (vm->step)
	{
		print_core(vm);
		ft_wait();
	}
}
