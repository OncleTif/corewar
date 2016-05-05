/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/05 09:13:24 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		get_1_arg(t_process *proc)
{
	int		j;

	j = 0;
	while (j < g_op_tab[proc->ir.opcode - 1].att_num)
	{
		if (proc->ir.code_args[j] == T_REG)
			stock_reg(proc, j);
		else if (proc->ir.code_args[j] == T_DIR)
			stock_dir(proc, j);
		else if (proc->ir.code_args[j] == T_IND)
			stock_ind(proc, j);
		else
			proc->ir_error = 1;
		j++;
	}
	return (0);
}

int		decode_ir(t_process *proc)
{
	unsigned char	*ir;

	ir = proc->ir.irstr;
	if (ir[0] < 1 || ir[0] > 16)
	{
		proc->ir_error = 1;
		return (0);
	}
	proc->ir.opcode = ir[0];
	proc->ir.index = g_op_tab[proc->ir.opcode - 1].index;
	proc->pcdelta += 1;
	//if (ig_op_tab[proc->ir.opcode - 1].att_numr[0] == 12 || ir[0] == 1 || ir[0] == 15 || ir[0] == 9)
	if (!g_op_tab[proc->ir.opcode - 1].carry)
		proc->ir.code_args[0] = g_op_tab[proc->ir.opcode - 1].att[0];
	else
	{
	//	stock_types_args(proc, g_op_tab[proc->ir.opcode - 1].att_num);
		if (!check_ocp(ir, &proc->ir))
		{
			proc->ir_error = 1;
			return (0);
		}
		proc->pcdelta += 1;
	}
	get_1_arg(proc);
	//printf("\n\n>>>>%d %d %d<<<<<\n\n",proc->ir.types_args[0] ,proc->ir.types_args[1], proc->ir.types_args[2]);
	//printf("\n\n>>OK<<\n\n");
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
int		check_cycle(t_vm *vm)
{
	vm->cpu.nbchecks += 1;
	if ((vm->cpu.cur_delta >= vm->cpu.cycle2die && vm->alllive >= NBR_LIVE)
		|| vm->cpu.nbchecks == MAX_CHECKS)
	{
		vm->cpu.nbchecks = 0;
		vm->cpu.cycle2die -= CYCLE_DELTA;
		vm->cpu.cur_delta = 0;
	}
	return (/*BSQ*/);
}

int		run()
{
	// pseudo code
	cycle_to_wait = -1;
	pc += pcdelta;
	execute fonction[opcode];
	modifie t_octet data[i].num_plr data[i].pc au core[i] modifier  // POUR SDL
	return (/*BSQ*/);
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
			if (vm->cpu.cur_cycle != 0 && tmp->proc.cycle_to_wait == vm->cpu.cur_cycle)
				run(/* BSQ */); // init cycle_to_wait = -1; pc += pcdelta;
			fetch_ir(tmp, vm->bcore.core, tmp->proc.pc);
			decode_ir(&tmp->proc);
		}
		tmp = tmp->next;
	}
	return (0);
}

	proc->pc += proc->pcdelta;
	proc->pcdelta = 0;

//Chooo-Chooo
int		cpu(t_vm *vm)
{
	CPU.cur_cycle = 0;

	while ((vm->cpu.cycle2die != 0) && (vm->dump != vm->cpu.cur_cycle))
	{
		CPU.cur_cycle += 1;
		CPU.cur_delta += 1;
		parse_proc(vm);
		check_cycle(); // modifie cur_delta cycle2die nbchecks dans T_cpu
	}
	return (0);
}
