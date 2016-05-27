/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:19:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/27 12:08:10 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_st(t_vm *vm, t_process *proc)
{
	int	arg[3];

	arg[0] = proc->ir.args[0];
	arg[1] = proc->ir.args[1];
	if (proc->ir.code_args[1] == T_IND)
		put_mem(vm, proc, proc->ir.args[1], proc->reg[proc->ir.args[0]]);
	else
		proc->reg[proc->ir.args[1]] = proc->reg[proc->ir.args[0]];
	if (vm->verbose & 4)
	{
		proc->ir.code_args[1] = T_IND;
		ft_print_operations(proc, arg);
		ft_putchar('\n');
	}
}

void	ft_sti(t_vm *vm, t_process *proc)
{
	int	sum;
	int	arg[3];

	if (proc->ir.code_args[2] == T_REG)
		arg[2] = proc->reg[proc->ir.args[2]];
	else
		arg[2] = proc->ir.args[2];
	if (proc->ir.code_args[1] == T_IND)
		arg[1] = get_mem_idx(vm, proc->pc, proc->ir.args[1]);
	else if (proc->ir.code_args[1] == T_REG)
		arg[1] = proc->reg[proc->ir.args[1]];
	else
		arg[1] = proc->ir.args[1];
	sum = arg[1] + arg[2];
	arg[0] = proc->ir.args[0];
	if (vm->verbose & 4)
	{
		proc->ir.code_args[1] = T_IND;
		proc->ir.code_args[2] = T_IND;
		ft_print_operations(proc, arg);
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
				arg[1], arg[2], sum, ((sum % IDX_MOD) + proc->pc));
	}
	put_mem(vm, proc, sum, proc->reg[proc->ir.args[0]]);
}
