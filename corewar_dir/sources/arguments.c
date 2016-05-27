/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:49:49 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/27 10:46:59 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		get_1_arg(t_process *proc)
{
	int		j;
	int		ret;

	j = 0;
	ret = 1;
	while (j < g_op_tab[proc->ir.opcode - 1].att_num)
	{
		if (proc->ir.code_args[j] == T_REG)
			ret = stock_reg(proc, j) && ret;
		else if (proc->ir.code_args[j] == T_DIR)
			stock_dir(proc, j);
		else if (proc->ir.code_args[j] == T_IND)
			stock_ind(proc, j);
		else
			ret = 0;
		j++;
	}
	return (ret);
}

int		ft_pcdelta_badocp(unsigned char *ir, int op, t_process *proc)
{
	int	i;
	int	ret;
	int	ocp;

	i = 0;
	ret = 2;
	while (i < g_op_tab[op - 1].att_num)
	{
		ocp = (ir[1] >> (6 - (2 * i))) & 3;
		if (ocp == IND_CODE)
			ret = ret + 2;
		else if (ocp == DIR_CODE)
			ret = ret + 2 + (2 * (1 - g_op_tab[op - 1].index));
		else if (ocp == REG_CODE)
			ret++;
		i++;
	}
	proc->pcdelta = ret;
	proc->ir_error = 1;
	return (0);
}

int		decode_ir(t_process *proc)
{
	unsigned char	*ir;

	ir = proc->ir.irstr;
	if (proc->ir.opcode < 1 || proc->ir.opcode > 16)
	{
		proc->ir_error = 1;
		if (proc->ir.opcode > 0 && proc->ir.opcode <= 16 &&
				g_op_tab[proc->ir.opcode - 1].carry)
			proc->pcdelta = 2;
		else
			proc->pcdelta = 0;
		return (0);
	}
	proc->ir.index = g_op_tab[proc->ir.opcode - 1].index;
	proc->pcdelta += 1;
	if (!g_op_tab[proc->ir.opcode - 1].carry)
		proc->ir.code_args[0] = g_op_tab[proc->ir.opcode - 1].att[0];
	else
	{
		if (!check_ocp(ir, &proc->ir))
			return (ft_pcdelta_badocp(ir, proc->ir.opcode, proc));
		proc->pcdelta += 1;
	}
	return (get_1_arg(proc));
}
