/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:25:44 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/06 17:01:55 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	get_mem(t_vm *vm, int idx)
{
	union u_4o	val;
	int			i;

	i = 0;
	while (i < 4)
	{
		val.c[3 - i] = vm->bcore.core[((idx + i) % IDX_MOD) % MEM_SIZE];
		i++;
	}
	return (val.i);
}

int	get_memlong(t_vm *vm, int idx)
{
	union u_4o	val;
	int			i;

	i = 0;
	while (i < 4)
	{
		val.c[3 - i] = vm->bcore.core[(idx + i) % MEM_SIZE];
		i++;
	}
	return (val.i);
}

int	get_mem_idx(t_vm *vm, int idx)
{
	union u_2o	val;
	int			i;

	i = 0;
	while (i < 2)
	{
		val.c[1 - i] = vm->bcore.core[((idx + i) % IDX_MOD) % MEM_SIZE];
		i++;
	}
	return (val.i);
}

int	get_memlong_idx(t_vm *vm, int idx)
{
	union u_2o	val;
	int			i;

	i = 0;
	while (i < 2)
	{
		val.c[1 - i] = vm->bcore.core[(idx + i) % MEM_SIZE];
		i++;
	}
	return (val.i);
}
