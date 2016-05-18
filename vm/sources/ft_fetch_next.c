/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:20:06 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/18 16:14:34 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_proc_init(t_vm *vm, t_process *proc)
{
	int nxt_pc;
	int i;

	proc->cycle_to_wait = 0;
	nxt_pc = (proc->pc + proc->pcdelta) % MEM_SIZE;
	if (vm->verbose & 16 && proc->pcdelta != MEM_SIZE)
	{
		ft_printf("ADV %d (%#0.4x ->", proc->pcdelta, proc->pc);
		ft_printf(" %#0.4x) ", nxt_pc);
		i = 0;
		while (i < proc->pcdelta)
		{
			ft_printf("%0.2x ", proc->ir.irstr[i]);
			i++;
		}
		ft_putchar('\n');
	}
	vm->data[proc->pc].pc--;
	vm->data[nxt_pc].pc++;
	ft_bzero(&proc->ir, sizeof(t_ir));
	//	if (vm->verbose & 16 && proc->pcdelta != MEM_SIZE)
	//		ft_printf(" %#0.4x)\n", proc->pc);
	proc->pc = nxt_pc;
	proc->pcdelta = 0;
}

void	ft_fetch_next(t_vm *vm, t_process *proc)
{
	if (proc->pcdelta)
	{
		ft_proc_init(vm, proc);
	}
	else if (proc->cycle_to_wait != -1)
	{
		vm->data[proc->pc].pc--;
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		vm->data[proc->pc].pc++;
	}
	else
	{
		proc->cycle_to_wait = 0;
	}
	if (vm->core[proc->pc] > 0 && vm->core[proc->pc] <= 16)
	{
		proc->cycle_to_wait = vm->cpu.cur_cycle +
			g_op_tab[vm->core[proc->pc] - 1].cost;
	}
}
