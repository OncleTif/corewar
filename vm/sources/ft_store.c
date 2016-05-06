/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:19:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/06 17:20:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_st(t_process *proc, t_vm *vm)
{
	if (proc->ir.code_args[1] == T_IND)
		put_mem(vm, proc->pc + proc->ir.args[1],
				proc->reg[proc->ir.args[0]]);
	else
		proc->reg[proc->ir.args[1]] = proc->reg[proc->ir.args[0]];
	proc->carry = !proc->reg[proc->ir.args[0]];
}

void	ft_sti(t_process *proc, t_vm *vm)
{
//	int	val;
	int	off;
	int	mod;

	if (proc->ir.code_args[1] == T_IND)
		off = get_mem(vm, proc->pc + proc->ir.args[1]);
	else if (proc->ir.code_args[1] == T_REG)
		off = proc->reg[proc->ir.args[1]];
	else
		off = proc->ir.args[1];
	if (proc->ir.code_args[2] == T_REG)
		mod = proc->reg[proc->ir.args[2]];
	else
		mod = proc->ir.args[2];
	put_mem(vm, proc->pc + off + mod,
			proc->reg[proc->ir.args[0]]);
	proc->carry = !proc->reg[proc->ir.args[0]];
}
