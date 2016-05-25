/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:07:14 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/25 18:10:42 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_add(t_vm *vm, t_process *proc)
{
	int	res;
	int	arg[3];

	arg[0] = proc->ir.args[0];
	arg[1] = proc->ir.args[1];
	arg[2] = proc->ir.args[2];
	(void)vm;
	res = proc->reg[proc->ir.args[0]] + proc->reg[proc->ir.args[1]];
	proc->reg[proc->ir.args[2]] = res;
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_putchar('\n');
	}
	proc->carry = !(res);
}

void	ft_sub(t_vm *vm, t_process *proc)
{
	int	res;
	int	arg[3];

	(void)vm;
	arg[0] = proc->ir.args[0];
	arg[1] = proc->ir.args[1];
	arg[2] = proc->ir.args[2];
	res = proc->reg[proc->ir.args[0]] - proc->reg[proc->ir.args[1]];
	proc->reg[proc->ir.args[2]] = res;
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_putchar('\n');
	}
	proc->carry = !(res);
}

void	ft_or(t_vm *vm, t_process *proc)
{
	int	j;
	int	arg[3];

	arg[2] = proc->ir.args[2];
	j = 0;
	while (j < 2)
	{
		if (proc->ir.code_args[j] == T_IND)
			arg[j] = get_mem(vm, proc->pc, proc->ir.args[j]);
		else if (proc->ir.code_args[j] == T_DIR)
			arg[j] = proc->ir.args[j];
		else if (proc->ir.code_args[j] == T_REG)
			arg[j] = proc->reg[proc->ir.args[j]];
		proc->ir.code_args[j] = T_IND;
		j++;
	}
	proc->reg[proc->ir.args[2]] = arg[0] | arg[1];
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_putchar('\n');
	}
	proc->carry = !(proc->reg[proc->ir.args[2]]);
}

void	ft_xor(t_vm *vm, t_process *proc)
{
	int	j;
	int	arg[3];

	arg[2] = proc->ir.args[2];
	j = 0;
	while (j < 2)
	{
		if (proc->ir.code_args[j] == T_IND)
			arg[j] = get_mem(vm, proc->pc, proc->ir.args[j]);
		else if (proc->ir.code_args[j] == T_DIR)
			arg[j] = proc->ir.args[j];
		else if (proc->ir.code_args[j] == T_REG)
			arg[j] = proc->reg[proc->ir.args[j]];
		proc->ir.code_args[j] = T_IND;
		j++;
	}
	proc->reg[proc->ir.args[2]] = arg[0] ^ arg[1];
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_putchar('\n');
	}
	proc->carry = !(proc->reg[proc->ir.args[2]]);
}

void	ft_and(t_vm *vm, t_process *proc)
{
	int	j;
	int	arg[3];

	arg[2] = proc->ir.args[2];
	j = 0;
	while (j < 2)
	{
		if (proc->ir.code_args[j] == T_IND)
			arg[j] = get_mem(vm, proc->pc, proc->ir.args[j]);
		else if (proc->ir.code_args[j] == T_DIR)
			arg[j] = proc->ir.args[j];
		else if (proc->ir.code_args[j] == T_REG)
			arg[j] = proc->reg[proc->ir.args[j]];
		proc->ir.code_args[j] = T_IND;
		j++;
	}
	proc->reg[proc->ir.args[2]] = arg[0] & arg[1];
	if (vm->verbose & 4)
	{
		ft_print_operations(proc, arg);
		ft_putchar('\n');
	}
	proc->carry = !(proc->reg[proc->ir.args[2]]);
}
