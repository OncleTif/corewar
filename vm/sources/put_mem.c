/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:49:26 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/05 17:57:26 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	put_mem(t_vm *vm, int idx, int off, int val)
{
	union u_4o	tmp;
	int			i;

	tmp.i = val;
	i = 0;
	while (i < 4)
	{
// incertitude sur la relativite du i a idx_mode
//
		vm->bcore.core[(idx + (off + i % IDX_MOD)) % MEM_SIZE] = tmp.c[3 - i];
		i++;
	}
}
