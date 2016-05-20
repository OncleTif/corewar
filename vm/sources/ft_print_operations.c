/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:10:04 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/20 17:28:24 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_print_operations(t_process *proc, int arg[3])
{
	int	i;

	i = 0;
	ft_printf("P%5d | %s", proc->num, g_op_tab[proc->ir.opcode - 1].name);
	while (i < g_op_tab[proc->ir.opcode - 1].att_num)
	{
		ft_putchar(' ');
		if (proc->ir.code_args[i] == T_REG && (proc->ir.opcode != 10 || i == 2))
			ft_putchar('r');
		ft_putnbr(arg[i]);
		i++;
	}
}
