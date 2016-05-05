/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:07:14 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/05 16:10:20 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_add(t_vm *vm, t_process *proc)
{
	(void)vm;
	int res;

	res = proc->ir.args[proc->ir.reg[0] - 1] + proc->ir.args[proc->ir.reg[1] - 1];
	proc->ir.args[proc->ir.reg[2] - 1] = res;
	proc->carry = !(res);
}

void	ft_sub(t_vm *vm, t_process *proc)
{
	(void)vm;
	int res;
	res = proc->ir.args[proc->ir.reg[0] - 1] - proc->ir.args[proc->ir.reg[1] - 1];
	proc->ir.args[proc->ir.reg[2] - 1] = res;
	proc->carry = !(res);
}

void	ft_or(t_vm *vm, t_process *proc)
{
	int i[2];
	int j;

	j = 0;
	while (j < 2)
	{
		if (proc->ir.args[j] == T_IND)
			i[j] = get_mem(vm, proc->ir.args[j], 0);
		else if (proc->ir.args[j] == T_DIR)
			i[j] = proc->ir.args[j];
		else if (proc->ir.args[j] == T_REG)
			i[j] = proc->reg[proc->ir.args[j] - 1];
		j++;
	}
	proc->reg[proc->ir.args[2] - 1] = i[0] | i[1];
	proc->carry = !(proc->reg[proc->ir.args[2] - 1]);
}

void	ft_xor(t_vm *vm, t_process *proc)
{
	int i[2];
	int j;

	j = 0;
	while (j < 2)
	{
		if (proc->ir.args[j] == T_IND)
			i[j] = get_mem(vm, proc->ir.args[j], 0);
		else if (proc->ir.args[j] == T_DIR)
			i[j] = proc->ir.args[j];
		else if (proc->ir.args[j] == T_REG)
			i[j] = proc->reg[proc->ir.args[j] - 1];
		j++;
	}
	proc->reg[proc->ir.args[2] - 1] = i[0] ^ i[1];
	proc->carry = !(proc->reg[proc->ir.args[2] - 1]);
}

void	ft_and(t_vm *vm, t_process *proc)
{
	int i[2];
	int j;

	j = 0;
	while (j < 2)
	{
		if (proc->ir.args[j] == T_IND)
			i[j] = get_mem(vm, proc->ir.args[j], 0);
		else if (proc->ir.args[j] == T_DIR)
			i[j] = proc->ir.args[j];
		else if (proc->ir.args[j] == T_REG)
			i[j] = proc->reg[proc->ir.args[j] - 1];
		j++;
	}
	proc->reg[proc->ir.args[2] - 1] = i[0] & i[1];
	proc->carry = !(proc->reg[proc->ir.args[2] - 1]);
}
