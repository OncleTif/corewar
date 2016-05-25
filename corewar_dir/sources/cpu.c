/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:15 by djoly             #+#    #+#             */
/*   Updated: 2016/05/25 18:51:28 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		fetch_ir(t_process *tmp, unsigned char *core)
{
	int		i;

	i = 0;
	while (i < 14)
	{
		tmp->ir.irstr[i] = core[(tmp->pc + i) % MEM_SIZE];
		i++;
	}
	return (0);
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

int		parse_proc(t_vm *vm)
{
	t_process	*tmp;
	int			i;

	i = 0;
	tmp = vm->proc;
	while (tmp)
	{
		if (tmp->cycle_to_wait < vm->cpu.cur_cycle &&
				vm->core[tmp->pc] > 0 && vm->core[tmp->pc] <= 16)
		{
			tmp->cycle_to_wait = vm->cpu.cur_cycle +
				g_op_tab[vm->core[tmp->pc] - 1].cost - 1;
			tmp->ir.opcode = vm->core[tmp->pc];
		}
		if (tmp->cycle_to_wait <= vm->cpu.cur_cycle)
		{
			fetch_ir(tmp, vm->core);
			if (decode_ir(tmp))
				run(vm, tmp);
			ft_fetch_next(vm, tmp);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		cpu(t_vm *vm, t_sdl *sdl)
{
	int		i;

	i = 0;
	ft_simple_sdl(sdl, vm, 0);
	while ((vm->dump != vm->cpu.cur_cycle))
	{
		CPU.cur_cycle += 1;
		if (vm->verbose & 2)
			ft_printf("It is now cycle %d\n", vm->cpu.cur_cycle);
		parse_proc(vm);
		if (check_cycle(vm) || i)
			break ;
		if (vm->cpu.cycle2die <= 0)
			i = 1;
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
