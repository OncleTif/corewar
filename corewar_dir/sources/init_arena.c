/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 17:19:24 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/25 18:36:45 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		ft_init_lst_proc(t_vm *vm)
{
	t_process		*tmp;
	t_list_player	*lst_play;

	lst_play = vm->bplr.lst_plyr;
	while (lst_play)
	{
		if (!(tmp = (t_process*)ft_memalloc(sizeof(t_process))))
			ft_error("error malloc");
		ft_init_proc(lst_play->plr, tmp);
		tmp->num = vm->nb_proc;
		vm->nb_proc += 1;
		tmp->next = vm->proc;
		vm->proc = tmp;
		lst_play = lst_play->next;
	}
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
		i++;
		j++;
	}
	plr->size = size;
	return (0);
}

int		ft_init_arena(t_vm *vm)
{
	int				n_plyr;
	int				pos_delta;
	t_list_player	*l_plyr;

	n_plyr = 0;
	pos_delta = MEM_SIZE / vm->bplr.nb_plyr;
	l_plyr = vm->bplr.lst_plyr;
	while (l_plyr)
	{
		copy_plr(vm, l_plyr->plr, n_plyr * pos_delta);
		n_plyr++;
		l_plyr = l_plyr->next;
	}
	return (0);
}
