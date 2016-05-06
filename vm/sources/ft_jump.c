/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:12:54 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/06 16:28:14 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_jump(t_vm *vm, t_process *proc)
{
	if (proc->carry && proc->ir.args[1] == T_DIR)
	{
		put_mem(vm, proc->pc + proc->ir.args[1], proc->reg[proc->ir.args[1] - 1]);

	}
}
