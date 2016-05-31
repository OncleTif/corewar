/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 19:19:01 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/31 10:01:14 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		core_zero(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->core[i] = 0;
		vm->data[i].num_plr = 0;
		vm->data[i].pc = 0;
		i++;
	}
}

int			ftab_init(t_vm *vm)
{
	vm->ftab[1] = &ft_live;
	vm->ftab[2] = &ft_ld;
	vm->ftab[3] = &ft_st;
	vm->ftab[4] = &ft_add;
	vm->ftab[5] = &ft_sub;
	vm->ftab[6] = &ft_and;
	vm->ftab[7] = &ft_or;
	vm->ftab[8] = &ft_xor;
	vm->ftab[9] = &ft_zjmp;
	vm->ftab[10] = &ft_ldi;
	vm->ftab[11] = &ft_sti;
	vm->ftab[12] = &ft_fork;
	vm->ftab[13] = &ft_lld;
	vm->ftab[14] = &ft_lldi;
	vm->ftab[15] = &ft_lfork;
	vm->ftab[16] = &ft_aff;
	return (0);
}

void		cpu_init(t_vm *vm)
{
	vm->cpu.cycle2die = CYCLE_TO_DIE;
	vm->cpu.cur_cycle = 0;
	vm->cpu.cycle_to_check = CYCLE_TO_DIE;
	vm->cpu.nbchecks = 0;
}

void		vm_init(t_vm *vm)
{
	int		i;

	i = -1;
	cpu_init(vm);
	vm->dump = -1;
	vm->step = 0;
	vm->aff = 0;
	vm->color = 0;
	vm->verbose = 0;
	vm->nb_proc = 1;
	vm->bplr.lst_plyr = NULL;
	vm->bplr.i_plr = 0;
	vm->l_core = 32;
	while (++i < 4)
		vm->bplr.modif[i] = 0;
	i = 0;
	while (++i < 4)
		vm->bplr.tab[i] = 0;
	vm->proc = NULL;
	vm->visu = 0;
	ftab_init(vm);
	core_zero(vm);
}

int			ft_init_proc(t_bin *plr, t_process *proc)
{
	int		i;

	i = 0;
	proc->ir.ocp = 0;
	proc->ir.nb_arg = 0;
	while (i < 3)
	{
		proc->ir.code_args[i] = 0;
		proc->ir.types_args[i] = 0;
		proc->ir.args[i] = 0;
		i++;
	}
	proc->cycle_to_wait = -1;
	proc->num_plr = plr->num_plyr;
	proc->pc = plr->pc_tmp;
	proc->pcdelta = 0;
	proc->reg[1] = proc->num_plr;
	proc->carry = 0;
	return (0);
}
