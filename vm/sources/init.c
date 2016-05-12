/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 09:25:36 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/12 09:44:40 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
ajout au debut de t_proc
*/
t_process	*ft_add_link(t_process *proc, int plr, int pc)
{
	t_process *tmp;


	if (!(tmp = (t_process*)ft_memalloc(sizeof(t_process))))
		ft_error("malloc error in new cell creating");
	if (tmp)
	{
		tmp->cycle_to_wait = -1;
		tmp->num_plr = plr;
		tmp->pc = pc;
		tmp->reg[1] = plr;
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
//		ft_putendl("\n__SORTIE_____\n");
	return (0);
}

int		copy_plr(t_vm *vm, t_bin *plr, int i)
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
