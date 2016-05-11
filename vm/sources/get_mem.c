/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:25:44 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/11 18:02:00 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	get_mem(t_vm *vm, int idx, int off)
{
	union u_4o	val;
	int			i;
	int			j;

	i = 0;
		j = idx + off % IDX_MOD;
	while (i < 4)
	{
		val.c[3 - i] = vm->core[(j + i) % MEM_SIZE];
		i++;
	}
	return (val.i);
}

int	get_memlong(t_vm *vm, int idx)
{
	union u_4o	val;
	int			i;
	int			j;

	i = 0;
	val.i = 0;
	while (i < 4)
	{
		j = (idx + i) % MEM_SIZE;
		printf("__idx:%d_j:%d___", idx, j);
		val.c[3 - i] = vm->core[j];
		i++;
	}
	printf("________getmemlong=%x_%.2x_%.2x_%.2x_%.2x___", val.i, val.c[0], val.c[1], val.c[2], val.c[3]);
	return (val.i);
}

short int	get_mem_idx(t_vm *vm, short int idx, short int off)
{
	union u_2o	val;
	int			i;

	i = 0;
	while (i < 2)
	{
		val.c[1 - i] = vm->core[(idx + (off + i) % IDX_MOD) % MEM_SIZE];
		i++;
	}
	return (val.i);
}

short int	get_memlong_idx(t_vm *vm, short int idx)
{
	union u_2o	val;
	int			i;

	i = 0;
	val.i = 0;
	while (i < 2)
	{
		val.c[1 - i] = vm->core[(idx + i) % MEM_SIZE];
		i++;
	}
	//ft_putnbrendl(r2oi(val.i));
	return (val.i);
}
