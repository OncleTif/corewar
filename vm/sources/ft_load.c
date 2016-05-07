/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:26:25 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/06 19:59:22 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_ld(t_vm *vm, t_process *proc)
{
	int	val;

	if (proc->ir.code_args[0] == T_IND)
		val = get_mem(vm, proc->pc, proc->ir.args[0]);
	else
		val = proc->ir.args[0];
	proc->reg[proc->ir.args[1]] = val;
	proc->carry = !val;
}

void	ft_lld(t_vm *vm, t_process *proc)
{
	int	val;

	if (proc->ir.code_args[0] == T_IND)
		val = get_memlong(vm, proc->pc + proc->ir.args[0]);
	else
		val = proc->ir.args[0];
	proc->reg[proc->ir.args[1]] = val;
	proc->carry = !val;
}

void	ft_ldi(t_vm *vm, t_process *proc)
{
	int	val;
	int	off;
	int	mod;

	if (proc->ir.code_args[0] == T_IND)
		off = get_mem(vm, proc->pc, proc->ir.args[0]);
	else if (proc->ir.code_args[0] == T_REG)
		off = proc->reg[proc->ir.args[0]];
	else
		off = proc->ir.args[0];
	if (proc->ir.code_args[1] == T_REG)
		mod = proc->reg[proc->ir.args[1]];
	else
		mod = proc->ir.args[1];
	val = get_mem(vm, proc->pc, off + mod);
	proc->reg[proc->ir.args[1]] = val;
	proc->carry = !val;
}

void	ft_lldi(t_vm *vm, t_process *proc)
{
	int	val;
	int	off;
	int	mod;

	if (proc->ir.code_args[0] == T_IND)
		off = get_memlong(vm, proc->pc + proc->ir.args[0]);
	else if (proc->ir.code_args[0] == T_REG)
		off = proc->reg[proc->ir.args[0]];
	else
		off = proc->ir.args[0];
	if (proc->ir.code_args[1] == T_REG)
		mod = proc->reg[proc->ir.args[1]];
	else
		mod = proc->ir.args[1];
	val = get_memlong(vm, proc->pc + off + mod);
	proc->reg[proc->ir.args[1]] = val;
	proc->carry = !val;
}
