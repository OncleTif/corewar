/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:22:45 by djoly             #+#    #+#             */
/*   Updated: 2016/05/10 11:13:08 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		check_live(t_vm *vm)
{
	t_cpu	*tmp;

	tmp = &vm->cpu;
	if (vm->nbr_live >= NBR_LIVE || tmp->nbchecks == MAX_CHECKS)
	{
		tmp->cycle2die -= CYCLE_DELTA;
		vm->nbr_live = 0;
		tmp->nbchecks = 0;
	}
	return (0);
}

int		check_cycle(t_vm *vm)
{
	t_cpu	*tmp;

	tmp = &vm->cpu;
	if (tmp->cur_cycle == tmp->cycle_to_check)
	{
		tmp->nbchecks++;
		check_live(vm);
		tmp->cycle_to_check = tmp->cur_cycle + tmp->cycle2die;
	}
	if (tmp->cycle2die <= 0 || vm->dump == tmp->cur_cycle)
		return (1); // I break
	return (0);// NO break
}
