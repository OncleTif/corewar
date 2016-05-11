/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:07:14 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/11 19:24:15 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_add(t_vm *vm, t_process *proc)
{
	(void)vm;
	int	res;

	res = proc->reg[proc->ir.args[0]] + proc->reg[proc->ir.args[1]];
	proc->reg[proc->ir.args[2]] = res;
	proc->carry = !(res);
}

void	ft_sub(t_vm *vm, t_process *proc)
{
	(void)vm;
	int	res;

	res = proc->reg[proc->ir.args[0]] - proc->reg[proc->ir.args[1]];
	proc->reg[proc->ir.args[2]] = res;
	proc->carry = !(res);
}

void	ft_or(t_vm *vm, t_process *proc)
{
	int	i[2];
	int	j;

	j = 0;
	while (j < 2)
	{
		if (proc->ir.code_args[j] == T_IND)
			i[j] = get_mem(vm, proc->pc, proc->ir.args[j]);
		else if (proc->ir.code_args[j] == T_DIR)
			i[j] = proc->ir.args[j];
		else if (proc->ir.code_args[j] == T_REG)
			i[j] = proc->reg[proc->ir.args[j]];
		j++;
	}
	proc->reg[proc->ir.args[2]] = i[0] | i[1];
	proc->carry = !(proc->reg[proc->ir.args[2]]);
}

void	ft_xor(t_vm *vm, t_process *proc)
{
	int	i[2];
	int	j;

	j = 0;
	while (j < 2)
	{
		if (proc->ir.code_args[j] == T_IND)
			i[j] = get_mem(vm, proc->pc, proc->ir.args[j]);
		else if (proc->ir.code_args[j] == T_DIR)
			i[j] = proc->ir.args[j];
		else if (proc->ir.code_args[j] == T_REG)
			i[j] = proc->reg[proc->ir.args[j]];
		j++;
	}
	proc->reg[proc->ir.args[2]] = i[0] ^ i[1];
	proc->carry = !(proc->reg[proc->ir.args[2]]);
}

void	ft_and(t_vm *vm, t_process *proc)
{
	int		i[2];
	int		j;

	j = 0;
	while (j < 2)
	{
		if (proc->ir.code_args[j] == T_IND)
			i[j] = get_mem(vm, proc->ir.args[j], 0);
		else if (proc->ir.code_args[j] == T_DIR)
			i[j] = proc->ir.args[j];
		else if (proc->ir.code_args[j] == T_REG)
			i[j] = proc->reg[proc->ir.args[j]];
		j++;
	}
	proc->reg[proc->ir.args[2]] = i[0] & i[1];
	proc->carry = !(proc->reg[proc->ir.args[2]]);
}
