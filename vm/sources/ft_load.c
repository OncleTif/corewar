/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:26:25 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/05 16:14:53 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_ld(t_process *proc, t_vm *vm)
{
	int	val;

	if (proc->ir.code_args[0] == T_IND)
		val = get_mem(vm, proc->pc, proc->ir.args[0]);
	else
		val = proc->ir.args[0];
	proc->reg[proc->ir.args[1] - 1] = val;
	proc->carry = !val;
}

void	ft_lld(t_process *proc, t_vm *vm)
{
	int	val;

	if (proc->ir.code_args[0] == T_IND)
		val = get_mem(vm, proc->pc + proc->ir.args[0], 0);
	else
		val = proc->ir.args[0];
	proc->reg[proc->ir.args[1] - 1] = val;
	proc->carry = !val;
}

void	ft_ldi(t_process *proc, t_vm *vm)
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

void	ft_lldi(t_process *proc, t_vm *vm)
{
	int	val;
	int	off;
	int	mod;

	if (proc->ir.code_args[0] == T_IND)
		off = get_mem(vm, proc->pc + proc->ir.args[0], 0);
	else if (proc->ir.code_args[0] == T_REG)
		off = proc->reg[proc->ir.args[0] - 1];
	else
		off = proc->ir.args[0];
	if (proc->ir.code_args[1] == T_REG)
		mod = proc->reg[proc->ir.args[1] - 1];
	else
		mod = proc->ir.args[1];

		val = get_mem(vm, proc->pc + off + mod, 0);
	proc->reg[proc->ir.args[1] - 1] = val;
	proc->carry = !val;
}
