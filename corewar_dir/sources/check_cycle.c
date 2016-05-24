/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:22:45 by djoly             #+#    #+#             */
/*   Updated: 2016/05/20 18:40:28 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		check_live(t_vm *vm)
{
	t_cpu	*tmp;
	t_process	*ptr;

	tmp = &vm->cpu;
	ptr = vm->proc;

	while (ptr)
	{
		//ft_putnbrendl(ptr->live);
		if (ptr->live >= NBR_LIVE || tmp->nbchecks == MAX_CHECKS)
		{
			tmp->cycle2die -= CYCLE_DELTA;
			vm->nbr_live = 0;
			tmp->nbchecks = 0;
			//to_kill_or_not_to_kill_proc(vm);
			if (vm->verbose & 2)
				ft_printf("Cycle to die is now %d\n", tmp->cycle2die);
			break;
		}
		ptr->live = 0;
		ptr = ptr->next;
	}
	ptr = vm->proc;
	while (ptr)
	{
		ptr->live = 0;
		ptr = ptr->next;
	}
	return (0);
}

int		check_live2(t_vm *vm)
{
	t_cpu			*tmp;
	t_list_player	*ptr;
	t_process		*ptr2;
	int				i;

	i = 1;
	ptr = vm->bplr.lst_plyr;
	tmp = &vm->cpu;
	while (ptr)
	{
		//ft_putnbrendl(ptr->live);
		if ((ptr->plr->nbr_live >= NBR_LIVE || tmp->nbchecks == MAX_CHECKS) && i)
		{
			i = 0;
			tmp->cycle2die -= CYCLE_DELTA;
			vm->nbr_live = 0;
			tmp->nbchecks = 0;
			//to_kill_or_not_to_kill_proc(vm);
			if (vm->verbose & 2)
				ft_printf("Cycle to die is now %d\n", tmp->cycle2die);
			break;
		}
		ptr->plr->nbr_live = 0;
		ptr = ptr->next;
	}
	ptr2 = vm->proc;
	while (ptr2)
	{
		ptr2->live = 0;
		ptr2 = ptr2->next;
	}
	return (0);



}

int		check_cycle(t_vm *vm)
{
	t_cpu	*tmp;

	tmp = &vm->cpu;
	if (tmp->cur_cycle == tmp->cycle_to_check)
	{
		if (to_kill_or_not_to_kill_proc(vm))
			return (1);
		tmp->nbchecks++;
		check_live2(vm);
		tmp->cycle_to_check = tmp->cur_cycle + tmp->cycle2die;
	}
	if (tmp->cycle2die <= 0 || vm->dump == tmp->cur_cycle)
		return (1);
	return (0);
}
