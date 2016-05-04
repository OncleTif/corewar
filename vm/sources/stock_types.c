/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:31:53 by djoly             #+#    #+#             */
/*   Updated: 2016/05/04 16:01:44 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		stock_dir(t_process *proc, int i)
{
	union u_4o tmp4;
	int k;

	tmp4.i = 0;
	k = 3 - (2 * (proc->ir.index));
	while (k >= 0)
	{
		tmp4.c[k] = proc->ir.irstr[proc->pcdelta];
		k--;
		proc->pcdelta += 1;
	}
	proc->ir.args[i] = tmp4.i;
	return (0);
}

int		stock_reg(t_process *proc, int i)
{
	int		reg;

	reg = proc->ir.irstr[proc->pcdelta] - 1;
	proc->pcdelta += 1;
	if (reg < 0 || reg > 15)
	{
		proc->ir_error = 1;
		return (0);
	}
	proc->ir.args[i] = proc->reg[reg];
	return (1);
}

int		stock_ind(t_process *proc, int i)
{
	int			k;
	union u_2o	tmp2;

	k = 0;
	while (k < 2)
	{
		tmp2.c[k] = proc->ir.irstr[proc->pcdelta];
		k += 1;
		proc->pcdelta += 1;
	}
	proc->ir.args[i] = r2oi(tmp2.i);
	return (0);
}
