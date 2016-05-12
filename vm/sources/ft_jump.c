/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:12:54 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/12 11:21:50 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			ft_zjmp(t_vm *vm, t_process *proc)
{
	//printf("____pc:%d_____\n", proc->pc);
	(void)vm;
	if (proc->carry)
	{
		proc->pc = ((proc->pc + (proc->ir.args[0] % IDX_MOD)) % MEM_SIZE);
		proc->pcdelta = MEM_SIZE;
	}
		//proc->pcdelta = ((proc->pc + (proc->ir.args[0] % IDX_MOD)) % MEM_SIZE) - proc->pc;
	//printf("____pc:%d_____\n", proc->pc);
}

void			ft_fork(t_vm *vm, t_process *proc)
{
	int			new_pc;
	int			new_plr;

	//t_process	*new_proc;
	new_plr = proc->num_plr;
	new_pc = (proc->pc + (proc->ir.args[0] % IDX_MOD)) % MEM_SIZE;
	ft_init_pc(new_plr, new_pc, vm, proc);
	//manque le push front

}

void			ft_lfork(t_vm *vm, t_process *proc)
{
	int			new_pc;
	int			new_plr;
	//t_process	*new_proc;

	new_plr = proc->num_plr;
	new_pc = (proc->pc + (proc->ir.args[0])) % MEM_SIZE;
//	new_proc = ft_init_pc(new_plr, new_pc, vm);
	ft_init_pc(new_plr, new_pc, vm, proc);
	//manque le push front
}
