/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:14:48 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/27 12:32:28 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		check_code(unsigned char ocp, int idx)
{
	int	decal;
	int	ret;
	int	arg;

	ret = 0;
	decal = 0;
	while (decal < 8)
	{
		arg = (ocp >> decal) & 3;
		if (arg == DIR_CODE && !idx)
			ret = ret + 4;
		else if (arg == REG_CODE)
			ret = ret + (arg != 0);
		else
			ret = ret + (arg != 0) * 2;
		decal = decal + 2;
	}
	return (ret);
}

int		check_code2(unsigned char *ir, int j, int opcode)
{
	int	i;

	i = (ir[1] >> (6 - (2 * j))) & 3;
	if (i == 3)
		i = 4;
	if (i & g_op_tab[opcode - 1].att[j])
	{
		return (i);
	}
	return (0);
}

int		check_ocp(unsigned char *ir, t_ir *pir)
{
	int	ret;
	int	j;

	j = 0;
	ret = 1;
	while (j < 4 && ret)
	{
		if (j < g_op_tab[pir->opcode - 1].att_num)
		{
			if ((ret = check_code2(ir, j, pir->opcode)))
				pir->code_args[j] = ret;
		}
		else
			ret = !(ir[1] >> (6 - (2 * j)) & 3);
		j++;
	}
	return (ret);
}
