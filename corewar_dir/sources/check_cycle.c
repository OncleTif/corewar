/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:22:45 by djoly             #+#    #+#             */
/*   Updated: 2016/05/25 18:07:06 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		plr_live0(t_list_player *lplr)
{
	while (lplr)
	{
		lplr->plr->nbr_live = 0;
		lplr = lplr->next;
	}
}

static int		check_live2(t_vm *vm)
{
	t_cpu			*pcpu;
	t_process		*pproc;

	pcpu = &vm->cpu;
	if ((vm->nbr_live >= NBR_LIVE) || pcpu->nbchecks == MAX_CHECKS)
	{
		pcpu->cycle2die -= CYCLE_DELTA;
		pcpu->nbchecks = 0;
		if (vm->verbose & 2)
			ft_printf("Cycle to die is now %d\n", pcpu->cycle2die);
	}
	pproc = vm->proc;
	while (pproc)
	{
		pproc->live = 0;
		pproc = pproc->next;
	}
	plr_live0(vm->bplr.lst_plyr);
	vm->nbr_live = 0;
	return (0);
}

int				check_cycle(t_vm *vm)
{
	t_cpu	*tmp;

	tmp = &vm->cpu;
	if (tmp->cur_cycle == tmp->cycle_to_check || tmp->cycle2die <= 0)
	{
		if (to_kill_or_not_to_kill_proc(vm))
			return (1);
		tmp->nbchecks++;
		check_live2(vm);
		tmp->cycle_to_check = tmp->cur_cycle + tmp->cycle2die;
	}
	if (vm->dump == tmp->cur_cycle)
		return (1);
	return (0);
}
