/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:49:26 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/06 09:43:28 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	put_mem(t_vm *vm, int idx, int val)
{
	union u_4o	tmp;
	int			i;

	tmp.i = val;
	i = 0;
	while (i < 4)
	{
		vm->bcore.core[((idx + i) % IDX_MOD) % MEM_SIZE] = tmp.c[3 - i];
		i++;
	}
}

void	put_memlong(t_vm *vm, int idx, int val)
{
	union u_4o	tmp;
	int			i;

	tmp.i = val;
	i = 0;
	while (i < 4)
	{
		vm->bcore.core[(idx + i) % MEM_SIZE] = tmp.c[3 - i];
		i++;
	}
}
