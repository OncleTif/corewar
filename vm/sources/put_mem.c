/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:49:26 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/11 14:50:03 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	put_mem(t_vm *vm, int idx, int off, int val)
{
	union u_4o	tmp;
	int			i;
	int			k;

	tmp.i = val;
	i = 0;
	//k = ((idx + (off + IDX_MOD) % (IDX_MOD * 2)) - IDX_MOD) + MEM_SIZE;
	k = idx + (off % IDX_MOD ) + MEM_SIZE;
	ft_putnbrendl(k);
	while (i < 4)
	{
		vm->core[(k + i) % MEM_SIZE] = tmp.c[3 - i];
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
		vm->core[(idx + i) % MEM_SIZE] = tmp.c[3 - i];
		i++;
	}
}
