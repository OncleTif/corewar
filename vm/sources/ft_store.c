/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:19:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/13 11:28:25 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_st(t_vm *vm, t_process *proc)
{
	if (proc->ir.code_args[1] == T_IND)
		put_mem(vm, proc, proc->ir.args[1],
				proc->reg[proc->ir.args[0]]);
	else
		proc->reg[proc->ir.args[1]] = proc->reg[proc->ir.args[0]];
	proc->carry = !proc->reg[proc->ir.args[0]];
}

void	ft_sti(t_vm *vm, t_process *proc)
{
	//	int	val;
	int	off;
	int	mod;
	int	sum;

	ft_putendl("pc sti:");
	ft_putnbrendl(proc->pc);
	if (proc->ir.code_args[2] == T_REG)
		mod = proc->reg[proc->ir.args[2]];
	else
		mod = proc->ir.args[2];
	if (proc->ir.code_args[1] == T_IND)
		off = get_mem_idx(vm, proc->pc, proc->ir.args[1]);
	else if (proc->ir.code_args[1] == T_REG)
		off = proc->reg[proc->ir.args[1]];
	else
		off = proc->ir.args[1];
	sum = mod + off;
	ft_putstr("                            ");
	ft_putnbr(proc->ir.args[1]);
	ft_putstr(" & ");
	ft_putnbr(off);
	ft_putstr(" & ");
	ft_putnbr(mod);
	ft_putstr(" & ");
	ft_putnbr((off) + (mod));
	ft_putstr(" & ");
	ft_putnbrendl(sum % 512);
	put_mem(vm, proc, sum,
			proc->reg[proc->ir.args[0]]);
	proc->carry = !proc->reg[proc->ir.args[0]];
}

//-255
