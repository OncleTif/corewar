/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:02:52 by djoly             #+#    #+#             */
/*   Updated: 2016/05/03 14:17:26 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	core_zero(t_base_core *bcore)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		bcore->core[i] = 0;
		bcore->data[i].num_plr = 0; // ou -1 si un player est le numero 0
		bcore->data[i].pc = 0;
		printf(">%d\t%d\t%d< ", i, bcore->core[i], bcore->data[i].pc);
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
