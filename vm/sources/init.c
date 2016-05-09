/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 09:25:36 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/09 16:06:45 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	core_zero(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->core[i] = 0;
		vm->data[i].num_plr = 0; // ou -1 si un player est le numero 0
		vm->data[i].pc = 0;
	//	printf(">%d\t%d\t%d< ", i, bcore->core[i], bcore->data[i].pc);
	//	if (i == 3687)
	//	printf("\nDAVID%d %d %d<<<\n", i, bcore.core[i],  bcore.data[i].pc);
		i++;
	}
}
//
// static void	cpu_init(t_cpu *)
// {
// 	current_cycle = 0;
// 	cycle2die = CYCLE_TO_DIE;
// }
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

void		vm_init(t_vm *vm)
{
	vm->dump = -1;
	vm->nb_proc = 0;
	vm->cpu.cycle2die = CYCLE_TO_DIE;
	vm->bplr.lst_plyr = NULL;
	vm->bplr.i_plr = 0;
	vm->bplr.tab[0] = -1;
	vm->bplr.tab[1] = -2;
	vm->bplr.tab[2] = -3;
	vm->bplr.tab[3] = -4;
	vm->proc = NULL;

	// cpu_init(vm->cpu);
	ftab_init(vm);
	core_zero(vm);
	// core_posplyer(vm);
}

int		ft_init_proc(t_bin	*plr, t_process *proc)
{
	int i;

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
	return(0);
}

/*
ajout au debut de t_proc
*/
t_process	*ft_add_link(t_process *proc, int plr, int pc)
{
	t_process *tmp;

	tmp = (t_process*)ft_memalloc(sizeof(t_process));
	if (tmp)
	{
		proc->cycle_to_wait = -1;
		proc->num_plr = plr;
		proc->pc = pc;
		proc->reg[1] = plr;
		tmp->next = proc;
	}
	return (tmp);
}

void	ft_init_pc(int plr, int pc, t_vm *vm)
{
	vm->proc = ft_add_link(vm->proc, plr, pc);
}

int		ft_init_lst_proc(t_vm *vm)
{
	t_process	*tmp;
	t_list_player	*lst_play;

	lst_play = vm->bplr.lst_plyr;
	while (lst_play)
	{
		tmp = (t_process*)ft_memalloc(sizeof(t_process));
		ft_init_proc(lst_play->plr, tmp);
		fflush(stdout);
		ft_fetch_next(vm, tmp);
		tmp->num = vm->nb_proc;
		vm->nb_proc += 1;

		tmp->next = vm->proc;
		vm->proc = tmp;


		lst_play = lst_play->next;
	}
		ft_putendl("\n__SORTIE_____\n");
	return (0);
}

int	copy_plr(t_vm *vm, t_bin *plr, int i)
{
	int		j;
	int		size;

	size = r4oi(plr->prog_size);
	j = 0;
	plr->pc_tmp = i;
	vm->data[i].pc = 1;
	while (j < size)
	{
		vm->core[i] = plr->program[j];
		vm->data[i].num_plr = plr->num_plyr;
		//printf(">%d\t%d\t%d< ", i, vm->core[i], vm->data[i].pc);
		//if (i == 3687)
		//printf(">>>>%d %d %d<<<", i, vm->core[i],  vm->data[i].pc);
		i++;
		j++;
	}
	return (0);
}

int		ft_init_arena(t_vm *vm)
{
	t_list_player *tmp;
	tmp = vm->bplr.lst_plyr;
	if (vm->bplr.nb_plyr == 2)
	{
		copy_plr(vm, tmp->next->plr, 0);
		copy_plr(vm, tmp->plr, 2048);
	}
	else if (vm->bplr.nb_plyr == 3)
	{
		copy_plr(vm, tmp->next->next->plr, 0);
		copy_plr(vm, tmp->next->plr, 1365);
		copy_plr(vm, tmp->plr, 2730);
	}
	else if (vm->bplr.nb_plyr == 4)
	{
		copy_plr(vm, tmp->next->next->next->plr, 0);
		copy_plr(vm, tmp->next->next->plr, 1024);
		copy_plr(vm, tmp->next->plr, 2048);
		copy_plr(vm, tmp->plr, 3072);
	}
	return (0);
}
