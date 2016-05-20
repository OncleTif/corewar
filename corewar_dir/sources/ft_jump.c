/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:12:54 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/20 14:22:19 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			ft_zjmp(t_vm *vm, t_process *proc)
{
	int	arg[3];

	arg[0] = proc->ir.args[0];
	if (proc->carry)
	{
		proc->pcdelta = arg[0] % IDX_MOD;
		if (vm->verbose & 4)
		{
			ft_print_operations(proc, arg);
			ft_printf(" OK\n");
		}
	}
	else if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_printf(" FAILED\n");
	}
}

void			ft_fork(t_vm *vm, t_process *proc)
{
	int			new_pc;
	int			new_plr;
	int			arg[3];

	arg[0] = proc->ir.args[0];
	new_plr = proc->num_plr;
	new_pc = (proc->pc + (proc->ir.args[0] % IDX_MOD)) % MEM_SIZE;
	ft_init_pc(new_plr, new_pc, vm, proc);
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_printf(" (%d)\n", new_pc);
	}
}

void			ft_lfork(t_vm *vm, t_process *proc)
{
	int			new_pc;
	int			new_plr;
	int			arg[3];

	arg[0] = proc->ir.args[0];
	new_plr = proc->num_plr;
	new_pc = (proc->pc + (proc->ir.args[0])) % MEM_SIZE;
	ft_init_pc(new_plr, new_pc, vm, proc);
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_printf(" (%d)\n", new_pc);
	}
}
