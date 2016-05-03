/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/03 18:51:18 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		check_code(char ocp, int decal)
{
	if (((ocp >> decal) & 3) == 0)
	{
		return (0);
	}
	return(1);
}

int		check_ocp(int *tab, unsigned char *ir)
{
	int				i;
	int				u;

	i = 0;
	while (tab[i] != 0)
	{
		u = 6;
		if (!check_code(ir[1], u))
			return (0);
		i++;
		u -= 2;
	}
	return (1);
}

int		stock_types_args(t_process *proc, int i)
{
	while (i > 0)
	{
		proc->ir.types_args[i - 1] = g_op_tab[proc->ir.opcode - 1].att[i - 1];
		i--;
	}
	return (0);
}

int		decode_ir(t_process *proc)
{
	unsigned char	*ir;

	ir = proc->ir.irstr;
	if (ir[0] < 1 || ir[0] > 16)
	{
		return (0);
	}
	proc->ir.opcode = ir[0];
	stock_types_args(proc, g_op_tab[proc->ir.opcode - 1].att_num);
	if (!check_ocp(proc->ir.types_args, ir))
	{
		return (0);
	}
	printf("\n\n>>>>%d %d %d<<<<<\n\n",proc->ir.types_args[0] ,proc->ir.types_args[1], proc->ir.types_args[2]);
	printf("\n\n>>OK<<\n\n");
	return (1);
}

//  FETCH IR
int		fetch_ir(t_list_process *tmp, unsigned char *core, int pc)
{
	int		i;

	i = 0;
	while (i < 14)
	{
		tmp->proc.ir.irstr[i] = core[(pc + i) % 4096];
		i++;
	}
	decode_ir(&tmp->proc);
	return(0);
}

int		parse_proc(t_vm *vm)
{
	t_list_process	*tmp;
	int		i;

	i = 0;
	tmp = BPROC.lst_proc;
	while (tmp)
	{
		if (tmp->proc.cycle_to_wait == -1)
			fetch_ir(tmp, vm->bcore.core, r4oi(tmp->proc.pc));
		// else if (tmp->proc.cycle_to_wait == 0)
//			run_ir();
		tmp = tmp->next;
	}
	return (0);
}

// RUN
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
