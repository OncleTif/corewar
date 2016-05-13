/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:37:24 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/13 18:29:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_live(t_vm *vm, t_process *proc)
{
	t_list_player	*plr;

	plr = vm->bplr.lst_plyr;
	while (plr && plr->plr->num_plyr != proc->ir.args[0])
		plr = plr->next;
	if (plr)
	{
		plr->plr->last_live = vm->cpu.cur_cycle;
		if (vm->verbose & 1)
		{
			ft_printf("Player %d (%s) is said to be alive\n", (-1 * proc->ir.args[0]), plr->plr->prog_name);
		/*	ft_putstr("un processus dit que le joueur ");
			ft_putnbr((-1 * proc->ir.args[0]));
			//ft_putnbr((((-1 * proc->ir.args[0]) % 4) + 1));
			ft_putstr(" (");
			ft_putstr(plr->plr->prog_name);
			ft_putstr(") est en vie\n");*/
		}
		plr->plr->last_live = vm->cpu.cur_cycle;
	}
	vm->nbr_live++;
	proc->live++;
}
