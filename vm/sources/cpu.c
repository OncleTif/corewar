/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/03 20:41:59 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		check_code(unsigned char ocp, int decal)
{
	if (((ocp >> decal) & 3) == 0)
	{
		return (0);
	}
	return(1);
}

int 	stock_code_args(t_ir *pir, unsigned char ocp, int u, int i)
{
	pir->code_args[i] = ((ocp >> u) & 3);
	return (0);
}

int		stock_dir(t_ir *pir, int i, int j)
{
	union u_4o tmp;
	int k;

	k = 0;
	while (k < 4)
	{
		tmp.c[k] = pir->irstr[j];
		k++;
		j++;
	}
	pir->args[i] = tmp.i;
	return (0x00);
}

int		stock_ind(t_process *proc, t_vm *vm, int i, int j)
{
	int			k;
	union u_2o	tmp;
	union u_4o	tmp1;

	k = 0;
	while (k < 2)
	{
		tmp.c[k] = proc->ir.irstr[j];
		k += 0x01;
		j += 0x01;
	}
	k = 0;
	while (k < 4)
	{
		tmp1.c[k] = vm->bcore.core[(r4oi(proc->pc) + r4oi(tmp.i) + k) % MEM_SIZE];
		k++;
	}
	proc->ir.args[i] = tmp.i;
	return (0x00);
}

int 	j_init(int i, t_ir *pir, int *j)
{
	int a;

	a = 0;
	if (pir->args[i] == 0x01)
	{
		a = 1;
	}
	if (pir->args[i] == 0x02)
	{
		a = 4;
	}
	if (pir->args[i] == 0x03)
	{
		a = 2;
	}
	*j += a;
	return (0);
}

int 	get_args(t_process *proc, t_vm *vm)
{
	int i;
	int j;

	i = 0;
	j = 2;
	while (i < 3)
	{
		//j_init(i, ir, &j);
		if (proc->ir.code_args[i] == 0x02)
		{
			stock_dir(&proc->ir, i, j);
			j += 4;
		}
		else if (proc->ir.code_args[i] == 0x03)
		{
			stock_ind(proc, vm, i, j);
			j += 2;
		}
		// else if (pir->code_args[i] == 0x04)
		// {
		// 	stock_reg();
		// }
		i++;
	}
	return (0);
}

int		check_ocp(int *tab, unsigned char *ir, t_ir *pir)
{
	int		i;
	int		u;

	i = 0;
	while (tab[i] != 0 && i < 3)
	{
		u = 6;
		if (!check_code(ir[1], u))
		{
			return (0);
		}
		else
		{
			stock_code_args(pir, ir[1], u, i);
		}
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

int		decode_ir(t_process *proc, t_vm *vm)
{
	unsigned char	*ir;

	ir = proc->ir.irstr;
	if (ir[0] < 1 || ir[0] > 16)
	{
		return (0);
	}
	proc->ir.opcode = ir[0];
	stock_types_args(proc, g_op_tab[proc->ir.opcode - 1].att_num);
	if (!check_ocp(proc->ir.types_args, ir, &proc->ir))
	{
		return (0);
	}
	get_args(proc, vm);
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
			fetch_ir(tmp, vm->bcore.core, r4oi(tmp->proc.pc));
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
