/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 08:57:19 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/18 09:20:43 by tmanet           ###   ########.fr       */
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
		/*ft_printf("* %d, weighing %d bytes, "%s" ("%s") !\n", elem->plr->num_plyr,
		  elem->plr->prog_size, elem->plr->prog_name, elem->plr->comment);*/
		ft_printf("* %d, weighing %u bytes, "" ("") !\n", elem->plr->num_plyr,
				elem->plr->prog_size);
		elem = elem->next;
	}
}
