/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 17:41:05 by djoly             #+#    #+#             */
/*   Updated: 2016/05/04 17:52:42 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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
	printf("\n\n");
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
