/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:19:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/05 18:06:48 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_st(t_process *proc, t_vm *vm)
{
	if (proc->ir.code_args[1] == T_IND)
		put_mem(vm, proc->pc, proc->ir.args[1],
				proc->reg[proc->ir.args[0] - 1]);
	else
		proc->reg[proc->ir.args[1] - 1] = proc->reg[proc->ir.args[0] - 1];
	proc->carry = !proc->reg[proc->ir.args[0] - 1];
}

void	ft_sti(t_process *proc, t_vm *vm)
{
	int	val;
	int	off;
	int	mod;

	if (proc->ir.code_args[0] == T_IND)
		off = get_mem(vm, proc->pc, proc->ir.args[0]);
	else if (proc->ir.code_args[0] == T_REG)
		off = proc->reg[proc->ir.args[0] - 1];
	else
		off = proc->ir.args[0];
	if (proc->ir.code_args[1] == T_REG)
		mod = proc->reg[proc->ir.args[1] - 1];
	else
		mod = proc->ir.args[1];

	val = get_mem(vm, proc->pc, off + mod);
	proc->reg[proc->ir.args[1] - 1] = val;
	proc->carry = !val;
}
