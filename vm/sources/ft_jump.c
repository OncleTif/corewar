/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:12:54 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/19 16:55:48 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			ft_zjmp(t_vm *vm, t_process *proc)
{
	int	arg[3];

	arg[0] = proc->ir.args[0];
	//printf("____pc:%d_____\n", proc->pc);
	if (proc->carry)
	{
		//vm->data[proc->pc].pc--; //degeu ; pb car pc modifier ici
		//proc->pc;
		proc->pcdelta = arg[0] % IDX_MOD;
		//vm->data[proc->pc].pc++; //degeu ; pb car pc modifier ici
		//proc->pcdelta = MEM_SIZE;
		if (vm->verbose & 4)
		{
			ft_print_operations(proc, arg);
			ft_printf(" OK\n");
		}
	}
	else if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
	}

	ft_fetch_next(vm, proc);
	//proc->pcdelta = ((proc->pc + (proc->ir.args[0] % IDX_MOD)) % MEM_SIZE) - proc->pc;
	//printf("____pc:%d_____\n", proc->pc);
}

void			ft_fork(t_vm *vm, t_process *proc)
{
	int			new_pc;
	int			new_plr;
	int			arg[3];

	arg[0] = proc->ir.args[0];
	//t_process	*new_proc;
	new_plr = proc->num_plr;
	new_pc = (proc->pc + (proc->ir.args[0] % IDX_MOD)) % MEM_SIZE;
	ft_init_pc(new_plr, new_pc, vm, proc);
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_printf(" (%d)\n", new_pc);
	}
	//manque le push front

}

void			ft_lfork(t_vm *vm, t_process *proc)
{
	int			new_pc;
	int			new_plr;
	int			arg[3];
	//t_process	*new_proc;

	arg[0] = proc->ir.args[0];
	new_plr = proc->num_plr;
	new_pc = (proc->pc + (proc->ir.args[0])) % MEM_SIZE;
	//	new_proc = ft_init_pc(new_plr, new_pc, vm);
	ft_init_pc(new_plr, new_pc, vm, proc);
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_printf(" (%d)\n", new_pc);
	}
	//manque le push front
}
