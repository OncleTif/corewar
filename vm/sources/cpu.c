/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/19 23:31:10 by eozdek           ###   ########.fr       */
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
	if (ir[0] < 1 || ir[0] > 16)
	{
		proc->ir_error = 1;
	if (!g_op_tab[proc->ir.opcode - 1].carry)
			proc->pcdelta = ft_pcdelta_badocp(ir, ir[0]);
		return (0);
	}
	proc->ir.opcode = ir[0];
	proc->ir.index = g_op_tab[proc->ir.opcode - 1].index;
	proc->pcdelta += 1;
	if (!g_op_tab[proc->ir.opcode - 1].carry)
		proc->ir.code_args[0] = g_op_tab[proc->ir.opcode - 1].att[0];
	else
	{
		if (!check_ocp(ir, &proc->ir))
		{
			proc->pcdelta = ft_pcdelta_badocp(ir, ir[0]);
			proc->ir_error = 1;
			//proc->carry = 0;
			return (0);
		}
		proc->pcdelta += 1;
	}
	get_1_arg(proc);
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
	int	i;

	i = 0;
	opcode = proc->ir.irstr[0];
	if (opcode > 0 && opcode < 17)
		vm->ftab[proc->ir.irstr[0]](vm, proc);
}

int		parse_proc(t_vm *vm)
{
	t_process	*tmp;
	int		i;

	i = 0;
	tmp = vm->proc;
	//	ft_putendl("debut cycle");
	while (tmp)
	{
		//		ft_putnbrendl((int)tmp);
		//		ft_putendl("debut proc                        ");
		//		ft_putstr("                                         ");
		//		ft_putnbrendl((int)tmp->cycle_to_wait);

		if (tmp->cycle_to_wait == vm->cpu.cur_cycle) // 1520 = 1520
		{
			//			ft_putendl("\n\n__________DANS DECODE_______\n\n");
			fetch_ir(tmp, vm->core);
			//			ft_putnbrendl((int)vm->core[tmp->pc]);
			if (decode_ir(tmp))
				run(vm, tmp);
			//ft_print(vm);
		}
		if (tmp->cycle_to_wait <= vm->cpu.cur_cycle)
		{
			//			ft_putchar('b');
			ft_fetch_next(vm, tmp);
		}

		//		ft_putendl("fin while");
		tmp = tmp->next;
	}

	//ft_putendl("fin cycle");
	return (0);
}

//proc->pc += proc->pcdelta;
//proc->pcdelta = 0;

//Chooo-Chooo
int		cpu(t_vm *vm, t_sdl *sdl)
{
	if (vm->visu == 1) // option -visu pour la SDL
		init_sdl(sdl);
	while ((vm->cpu.cycle2die != 0) && (vm->dump != vm->cpu.cur_cycle))
	{
		CPU.cur_cycle += 1;
		if (vm->verbose & 2)
			ft_printf("It is now cycle %d\n", vm->cpu.cur_cycle);
		parse_proc(vm);
		if (vm->visu == 1)
		disp(sdl, vm);
		//print_t_proc(vm);
		//ft_printf(">>%d<<", vm->cpu.cycle2die);
		if (check_cycle(vm)) // modifie cur_delta cycle2die nbchecks dans T_cpu
			break ;
		if ((vm->step) && (vm->cpu.cur_cycle % vm->step == 0))
		{
			print_core(vm);
			ft_wait();
		}
	}
	if (vm->visu == 1)
	{
		// display_winner(sdl->window, sdl->renderer, vm);
		quit(sdl);
	}
	return (0);
}
