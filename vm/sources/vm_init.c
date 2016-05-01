/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:02:52 by djoly             #+#    #+#             */
/*   Updated: 2016/05/01 11:37:54 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	core_zero(t_base_core core)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		core.core[i] = 0;
		core.data[i].plyr = 0; // ou -1 si un player est le numero 0
		core.data[i].pc = 0;
		i++;
	}
}

static void	cpu_init(t_cpu)
{
	current_cycle = 0;
	cycle2die = CYCLE_TO_DIE;
}

void		vm_init(t_vm *vm)
{

	vm->bplr.i_plr = 0;
	vm->bplr.tab[0] = 1;
	vm->bplr.tab[1] = 2;
	vm->bplr.tab[2] = 3;
	vm->bplr.tab[3] = 4;


	cpu_init(vm->cpu);
	core_zero(vm->core);
	core_posplyer(vm);


}
