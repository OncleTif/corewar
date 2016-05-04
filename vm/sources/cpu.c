/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/04 16:40:22 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"


int		stock_types_args(t_process *proc)
{
	//while (i > 0)
	//{
		proc->ir.code_args[0] = g_op_tab[proc->ir.opcode - 1].att[0];
	//	i--;
	//}
	return (0);
}

int		get_1_arg(t_process *proc, t_vm *vm)
{
	int		j;

	j = 0;
	while (j < g_op_tab[proc->ir.opcode - 1].att_num)
	{
		if (proc->ir.code_args[j] == T_REG)
			stock_reg(proc, j);
		else if (proc->ir.code_args[j] == T_DIR)
			stock_dir(proc, vm, j);
		else if (proc->ir.code_args[j] == T_IND)
			stock_ind(proc, vm, j);
		else
			proc->ir_error = 1;
		j++;
	}
	return (0);
}

int		decode_ir(t_process *proc, t_vm *vm)
{
	unsigned char	*ir;

	ir = proc->ir.irstr;
	if (ir[0] < 1 || ir[0] > 16)
	{
		return (0);
	}
	proc->ir.opcode = ir[0];
	proc->ir.index = g_op_tab[proc->ir.opcode - 1].index;
	proc->pcdelta += 1;
	//if (ig_op_tab[proc->ir.opcode - 1].att_numr[0] == 12 || ir[0] == 1 || ir[0] == 15 || ir[0] == 9)
	if (!g_op_tab[proc->ir.opcode - 1].carry)
		stock_types_args(proc);
	//	get_1_arg(ir[0], proc, vm );
	else
	{
	//	stock_types_args(proc, g_op_tab[proc->ir.opcode - 1].att_num);
		if (!check_ocp(proc->ir.types_args, ir, &proc->ir))
		{
			proc->ir_error = 1;
			return (0);
		}
		proc->pcdelta += 1;
		get_args(proc, vm);
	}
		get_1_arg(ir[0], proc, vm );
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
		tmp->proc.ir.irstr[i] = core[(pc + i) % MEM_SIZE];
		i++;
	}
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
		{
			fetch_ir(tmp, vm->bcore.core, tmp->proc.pc);
			decode_ir(&tmp->proc, vm);
		}
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
