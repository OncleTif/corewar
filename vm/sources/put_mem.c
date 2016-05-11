/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:49:26 by tmanet            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/05/11 14:56:59 by djoly            ###   ########.fr       */
=======
/*   Updated: 2016/05/11 15:01:01 by tmanet           ###   ########.fr       */
>>>>>>> a4b764b82669e2dbda6b30fd179760d45b908088
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	put_mem(t_vm *vm, t_process *proc, int off, int val)
{
	union u_4o	tmp;
	int			i;
	int			k;

	tmp.i = val;
	i = 0;
<<<<<<< HEAD
	/*if (off < 0)
	{
		neg = -1;
		off = -off;
	}*/
	//k = ((idx + (off + IDX_MOD) % (IDX_MOD * 3)) - IDX_MOD) + MEM_SIZE;
	k = idx + (neg * (off % IDX_MOD )) + MEM_SIZE;
=======
	//k = ((idx + (off + IDX_MOD) % (IDX_MOD * 2)) - IDX_MOD) + MEM_SIZE;
	k = proc->pc + (off % IDX_MOD ) + MEM_SIZE;
	ft_putnbrendl(k);
>>>>>>> a4b764b82669e2dbda6b30fd179760d45b908088
	while (i < 4)
	{
		vm->core[(k + i) % MEM_SIZE] = tmp.c[3 - i];
		i++;
	}
}

void	put_memlong(t_vm *vm, t_process *proc, int val)
{
	union u_4o	tmp;
	int			i;

	tmp.i = val;
	i = 0;
	while (i < 4)
	{
		vm->core[(proc->pc + i) % MEM_SIZE] = tmp.c[3 - i];
		i++;
	}
}
