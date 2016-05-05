/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:26:25 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/05 14:49:29 by tmanet           ###   ########.fr       */
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
	proc->reg[proc->ir.args[1]] = val;
	proc->carry = !val;
}
