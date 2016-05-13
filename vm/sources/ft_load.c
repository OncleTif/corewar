/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:26:25 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/13 15:31:34 by djoly            ###   ########.fr       */
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
	int			val;
	int	off;
	int	mod;

	if (proc->ir.code_args[0] == T_IND)
		off = get_mem_idx(vm, proc->pc, proc->ir.args[0]);
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
	//short int	r;

	if (proc->ir.code_args[0] == T_IND)
		off = get_mem_idx(vm, proc->pc, proc->ir.args[0]); // lldi avec un int plus grand que max short int ? zaz
	else if (proc->ir.code_args[0] == T_REG)
		off = proc->reg[proc->ir.args[0]];
	else
		off = proc->ir.args[0];
	if (proc->ir.code_args[1] == T_REG)
		mod = proc->reg[proc->ir.args[1]];
	else
		mod = proc->ir.args[1];
	//r = get_memlong_idx(vm, proc->pc + off + mod);
	//val = get_memlong(vm, proc->pc + r);// off + mod);
	val = get_memlong(vm, proc->pc + off + mod);
//	printf("lldi: %d + %d = %d, val = %x\n", off, mod, off + mod, val);
//	printf("\n            LLDI___________r:%d____off=%d__mod:%x_______________\n", r, off, mod);
	proc->reg[proc->ir.args[2]] = val;
	proc->carry = !val;
}
