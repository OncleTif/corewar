/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 09:25:36 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/05 18:25:37 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	core_zero(t_base_core *bcore)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		bcore->core[i] = 0;
		bcore->data[i].num_plr = 0; // ou -1 si un player est le numero 0
		bcore->data[i].pc = 0;
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

void		vm_init(t_vm *vm)
{
	vm->dump = -1;

	vm->cycle2die = CYCLE_TO_DIE;

	vm->bplr.i_plr = 0;
	vm->bplr.tab[0] = 0xffffffff;
	vm->bplr.tab[1] = 0xfffffffe;
	vm->bplr.tab[2] = 0xfffffffd;
	vm->bplr.tab[3] = 0xfffffffc;
	vm->bproc.lst_proc = NULL;

	// cpu_init(vm->cpu);
	core_zero(&vm->bcore);
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
	proc->reg[0] = proc->num_plr;
	proc->carry = 0;
	return(0);
}

int		ft_addr(t_vm *vm)
{
	t_list_process *tmp;
	int i;

	tmp = vm->bproc->lst_proc;
	i = tmp->num;
	while (tmp->next != NULL)
	{
		if (tmp->num < i)
			i = tmp->num;
		tmp = tmp->next;
	}
	return (i);
}

t_process	*ft_init_pc(int plr, int pc, t_vm *vm)
{
	t_process	*proc;

	proc = (t_process*)ft_memalloc(sizeof(t_process));

	proc->cycle_to_wait = -1;
	proc->num_plr = plr;
	proc->pc = pc;
	proc->reg[0] = ft_addr(vm);
	return (proc);
}

int		ft_init_lst_proc(t_vm *vm)
{
	t_list_process	*tmp;
	t_list_player	*lst_play;

	lst_play = vm->bplr.lst_plyr;
	while (lst_play)
	{
		tmp = (t_list_process*)ft_memalloc(sizeof(t_list_process));
		ft_init_proc(lst_play->plr, &tmp->proc);
		tmp->proc.num = BPROC.nb_proc;
		BPROC.nb_proc += 1;
		tmp->next = BPROC.lst_proc;
		BPROC.lst_proc = tmp;
		lst_play = lst_play->next;
	}
	return (0);
}

int	copy_plr(t_vm *vm, t_bin *plr, int i)
{
	int		j;
	int		size;

	size = r4oi(plr->prog_size);
	j = 0;
	plr->pc_tmp = i;
	BCOR.data[i].pc = 1;
	while (j < size)
	{
		vm->bcore.core[i] = plr->program[j];
		BCOR.data[i].num_plr = plr->num_plyr;
		//printf(">%d\t%d\t%d< ", i, BCOR.core[i], BCOR.data[i].pc);
		//if (i == 3687)
		//printf(">>>>%d %d %d<<<", i, BCOR.core[i],  BCOR.data[i].pc);
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
