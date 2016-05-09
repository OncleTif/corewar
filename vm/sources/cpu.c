/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/09 12:35:09 by eozdek           ###   ########.fr       */
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
			printf("ERROR0");
		proc->ir_error = 1;
			printf(" ir0:%d  pc:%d irerror:%d ", ir[0], proc->pc, proc->ir_error);
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
			printf("ERROR1");
			printf("pc:%d irerror:%d ", proc->pc, proc->ir_error);
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
int		fetch_ir(t_process *tmp, unsigned char *core)
{
	int		i;
	i = 0;
	while (i < 14)
	{
		tmp->ir.irstr[i] = core[(tmp->pc + i) % MEM_SIZE];
		i++;
	}
	return(0);
}

void	run(t_vm *vm, t_process *proc)
{
	int	opcode;

ft_putnbrendl(proc->ir.irstr[0]);
	opcode = proc->ir.irstr[0];
	vm->ftab[proc->ir.irstr[0]](vm, proc);
}

int		parse_proc(t_vm *vm)
{
	t_process	*tmp;
	int		i;

	i = 0;
	tmp = vm->proc;
	ft_putendl("debut cycle");
	while (tmp)
	{
		ft_putnbrendl((int)tmp);
		ft_putendl("debut proc");
		if (tmp->cycle_to_wait == vm->cpu.cur_cycle) // 1520 = 1520
		{
			ft_putchar('a');
			ft_putendl("\n\n__________DANS DECODE_______\n\n");
			fetch_ir(tmp, vm->core);
			ft_putendl("a");
			decode_ir(tmp);
			ft_putendl("b");
			//ft_print(vm);
			run(vm, tmp);
			ft_putendl("c");
			i = 0;
			while (i < 17)
			{
				printf("____reg[%d]: %d\n", i, tmp->reg[i]);
				i++;
			}
			ft_putendl("d");

			//ft_print(&vm);
			ft_putendl("\n\n_________FIN DECODE_________\n\n");
		}
		if (tmp->cycle_to_wait <= vm->cpu.cur_cycle)
		{
			ft_putchar('b');
			ft_fetch_next(vm, tmp);
		}
		ft_putendl("fin while");
		tmp = tmp->next;
	}
	ft_putendl("fin cycle");
	return (0);
}

	//proc->pc += proc->pcdelta;
	//proc->pcdelta = 0;

//Chooo-Chooo
int		cpu(t_vm *vm)
{
	CPU.cur_cycle = 0;
	int i;

	i = 0;
	while ((vm->cpu.cycle2die != 0) && (vm->dump != vm->cpu.cur_cycle))
	{
		CPU.cur_cycle += 1;
		CPU.cur_delta += 1;
		parse_proc(vm);
//		if (i == 4)
//		break ;
//		i++;
	//	check_cycle(); // modifie cur_delta cycle2die nbchecks dans T_cpu
	}
	return (0);
}
