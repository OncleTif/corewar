/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 22:02:12 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/25 18:22:41 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_process	*ft_add_link(t_process *beg, int plr, int pc, t_process *father)
{
	t_process *tmp;

	if (!(tmp = (t_process*)ft_memalloc(sizeof(t_process))))
		ft_error("malloc error in new cell creating");
	if (tmp)
	{
		ft_memcpy(tmp->reg, father->reg, sizeof(father->reg));
		tmp->cycle_to_wait = -1;
		tmp->num_plr = plr;
		tmp->pc = pc;
		tmp->carry = father->carry;
		tmp->next = beg;
		tmp->live = father->live;
		tmp->lst_live = father->lst_live;
	}
	return (tmp);
}

void		ft_init_pc(int plr, int pc, t_vm *vm, t_process *proc)
{
	vm->proc = ft_add_link(vm->proc, plr, pc, proc);
	vm->proc->num = vm->nb_proc++;
}
