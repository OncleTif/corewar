/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:20:06 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/06 17:08:50 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_proc_init(t_vm *vm, t_process *proc)
{
	int i;

	i = 0;
	ft_bzero(&proc->ir, sizeof(t_ir));
	proc->cycle_to_wait = -1;
	proc->pc = (proc->pc + proc->pcdelta) % MEM_SIZE;
	proc->pcdelta = 0;
}

void	ft_fetch_next(t_vm *vm, t_process *proc)
{
	if (proc->pcdelta)
		ft_proc_init(vm, proc);
	else
		proc->pc = (proc->pc + 1) % MEM_SIZE;
	if (vm->bcore.core[proc->pc] > 0 && vm->bcore.core[proc->pc] <= 16)
	{
		proc->cycle_to_wait = vm->cpu.cur_cycle +
			g_op_tab[vm->bcore.core[proc->pc]].cost;
	}
}
