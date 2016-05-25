/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/25 11:15:41 by tmanet           ###   ########.fr       */
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

int		ft_pcdelta_badocpi2(unsigned char *ir, int op)
{
	int	i;
	int	ret;
	int	ocp;
	int	except;

	i = 0;
	ret = 3;
	except = 0;
	while (i < g_op_tab[op - 1].att_num)
	{
		ocp = (ir[1] >> (6 - (2 * i))) & 3;
		if (ocp & IND_CODE && g_op_tab[op - 1].att[i] & T_IND)
			ret = ret + 2;
		else if (ocp & DIR_CODE && g_op_tab[op - 1].att[i] & T_DIR)
			ret = ret + 2 + (2 * !(g_op_tab[op - 1].index));
		else if (ocp & REG_CODE && g_op_tab[op - 1].att[i] & T_REG)
			ret++;
		else
			except = -1;
		i++;
	}
	return (ret + except);
}

int		ft_pcdelta_badocp(unsigned char *ir, int op)
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
	return (ret);
}

int		decode_ir(t_process *proc)
{
	unsigned char	*ir;

	ir = proc->ir.irstr;
	if (proc->ir.irstr[0] < 1 || proc->ir.irstr[0] > 16)
	{
		proc->ir_error = 1;
		if (proc->ir.opcode > 0 && proc->ir.opcode <= 16 && g_op_tab[proc->ir.opcode - 1].carry)
		{
			proc->pcdelta = 2;
//		ft_printf("opcode : %d, irstr0 : %d, pcdelta: %d\n",proc->ir.opcode, proc->ir.irstr[0], proc->pcdelta);
		}
			else
			{
			proc->pcdelta = 0;
//		ft_printf("opcode : %d, irstr0 : %d, pcdelta: %d\n",proc->ir.opcode, proc->ir.irstr[0], proc->pcdelta);
			}
		return (0);
	}
	//proc->ir.opcode = ir[0];
	proc->ir.index = g_op_tab[proc->ir.opcode - 1].index;
	proc->pcdelta += 1;
	if (!g_op_tab[proc->ir.opcode - 1].carry)
		proc->ir.code_args[0] = g_op_tab[proc->ir.opcode - 1].att[0];
	else
	{
		if (!check_ocp(ir, &proc->ir))
		{
			proc->pcdelta = ft_pcdelta_badocp(ir, proc->ir.opcode);
			proc->ir_error = 1;
			return (0);
		}
		proc->pcdelta += 1;
	}
	get_1_arg(proc);
	return (1);
}

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
	int	i;

	i = 0;
	opcode = proc->ir.irstr[0];
	if (proc->ir.opcode > 0 && proc->ir.opcode < 17)
		vm->ftab[proc->ir.opcode](vm, proc);
}

void	get_ops(t_vm *vm)
{
	t_process	*tmp;

	tmp = vm->proc;
	while (tmp)
	{
		if (tmp->cycle_to_wait < vm->cpu.cur_cycle &&
				vm->core[tmp->pc] > 0 && vm->core[tmp->pc] <= 16)
		{
			tmp->cycle_to_wait = vm->cpu.cur_cycle +
				g_op_tab[vm->core[tmp->pc] - 1].cost - 1;
			tmp->ir.opcode = vm->core[tmp->pc];
//			ft_printf("found a %s at pc %d\n", g_op_tab[vm->core[tmp->pc] - 1].name, tmp->pc);
		}
//		else
//			ft_printf("not found cause cycle to wait is %d and cur cycle is %d\n",tmp->cycle_to_wait, vm->cpu.cur_cycle);
		tmp = tmp->next;
	}
}

int		parse_proc(t_vm *vm)
{
	t_process	*tmp;
	int		i;

	i = 0;
	tmp = vm->proc;
	get_ops(vm);
	while (tmp)
	{
		if (tmp->cycle_to_wait < vm->cpu.cur_cycle &&
				vm->core[tmp->pc] > 0 && vm->core[tmp->pc] <= 16)
		{
			tmp->cycle_to_wait = vm->cpu.cur_cycle +
				g_op_tab[vm->core[tmp->pc] - 1].cost - 1;
			tmp->ir.opcode = vm->core[tmp->pc];
//			ft_printf("found a %s at pc %d\n", g_op_tab[vm->core[tmp->pc] - 1].name, tmp->pc);
		}
		if (tmp->cycle_to_wait <= vm->cpu.cur_cycle)
		{
			fetch_ir(tmp, vm->core);
			if (decode_ir(tmp))
				run(vm, tmp);
			ft_fetch_next(vm, tmp);
		}
//		else
//			ft_printf("cycle %d, pc : %d, opcode : %d, cycle to wait : %d\n", vm->cpu.cur_cycle, tmp->pc, vm->core[tmp->pc], tmp->cycle_to_wait);
		tmp = tmp->next;
	}
	return (0);
}

int		cpu(t_vm *vm, t_sdl *sdl)
{
	ft_simple_sdl(sdl, vm, 0);
//	get_ops(vm);
//	ft_putendl("after op init");
	while ((vm->cpu.cycle2die != 0) && (vm->dump != vm->cpu.cur_cycle))
	{
		CPU.cur_cycle += 1;
		if (vm->verbose & 2)
			ft_printf("It is now cycle %d\n", vm->cpu.cur_cycle);
		parse_proc(vm);
		if (check_cycle(vm))
			break ;
		if ((vm->step) && (vm->cpu.cur_cycle % vm->step == 0))
		{
			print_core(vm);
			ft_wait();
		}
		if (vm->visu == 1)
			ft_disp(sdl, vm);
	}
	ft_simple_sdl(sdl, vm, 1);
	return (0);
}
