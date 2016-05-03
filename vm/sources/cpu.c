/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/03 15:23:52 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		fetch_ir(unsigned char *core, int pc, char ret[14])
{
	int		i;

	i = 0;
	while (i < 14)
	{
		ret[i] = core[(pc + i) % 4096];
		i++;
	}
	return(0);
}


int		parse_proc(t_vm *vm)
{
	t_list_process	*tmp;
	char	irtmp[14];
	int		i;

	i = 0;
	tmp = BPROC.lst_proc;
	while (tmp)
	{
		if (tmp->proc.cycle_to_wait == 0)
		{
			fetch_ir(vm->bcore.core, r4oi(tmp->proc.pc), irtmp);
		}
		i = 0;
		while (i < 14)
		{
			tmp->proc.ir.ir[i] = irtmp[i];
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		cpu(t_vm *vm)
{
	CPU.cur_cycle = 0;

	while (1)
	{
		parse_proc(vm);

		CPU.cur_cycle += 1;
		break ;
	}


	return (0);
}
