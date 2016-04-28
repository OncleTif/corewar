/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:02:52 by djoly             #+#    #+#             */
/*   Updated: 2016/04/28 17:16:03 by djoly            ###   ########.fr       */
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

void	vm_init(t_vm *vm)
{
	core_zero(vm->core);


}
