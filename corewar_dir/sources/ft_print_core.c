/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 17:28:06 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/25 19:05:20 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_t_ir(t_ir *tir)
{
	int	i;

	i = 0;
	ft_printf("\n__IR__\nirstr:");
	while (i < 14)
	{
		ft_printf("%.2x ", (unsigned char)tir->irstr[i]);
		i++;
	}
	ft_printf("opcode:%d ocp:%x index:%d nb_arg:%d\n", tir->opcode, tir->ocp,
			tir->index, tir->nb_arg);
	i = 0;
	while (i < 3)
	{
		ft_printf("I = %d, TYPE => %x, CODE => %x, ARGS => %x\n", i,
					tir->types_args[i], tir->code_args[i], tir->args[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_print(t_vm *vm)
{
	print_t_vm(vm);
	print_t_bplr(&vm->bplr);
	print_t_plr(vm->bplr.lst_plyr);
}
