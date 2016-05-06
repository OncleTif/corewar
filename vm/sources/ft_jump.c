/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:12:54 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/06 16:57:58 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			ft_jump(t_vm *vm, t_process *proc)
{
	if (proc->carry)
		proc->pc = (proc->pc + proc->ir.args[0]) % MEM_SIZE;
}

void			ft_fork(t_vm *vm, t_process *proc)
{
	int			new_pc;
	int			new_plr;
	t_process	*new_proc;

	new_plr = proc->num_plr;
	new_pc = (proc->pc + (proc->ir.args[0] % IDX_MOD)) % MEM_SIZE;
	new_proc = ft_init_pc(new_plr, new_pc, vm);
	//manque le push front
}

void			ft_lfork(t_vm *vm, t_process *proc)
{
	int			new_pc;
	int			new_plr;
	t_process	*new_proc;

	new_plr = proc->num_plr;
	new_pc = (proc->pc + (proc->ir.args[0])) % MEM_SIZE;
	new_proc ft_init_pc(new_plr, new_pc, vm);
	//manque le push front
}
