/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:43:10 by djoly             #+#    #+#             */
/*   Updated: 2016/05/03 14:45:37 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		ft_init_proc(t_bin	*plr, t_process *proc)
{
	proc->num_plr = plr->num_plyr;
	proc->pc = plr->pc_tmp;
	proc->reg[0] = proc->num_plr;
	proc->carry = 0;
	return(0);
}

int		ft_init_lst_proc(t_vm *vm)
{
	t_list_process	*tmp;
	t_list_player	*lst_play;

	lst_play = vm->bplr.lst_plyr;
	while (lst_play)
	{
		tmp = (t_list_process*)ft_memalloc(sizeof(t_list_process));
		ft_init_proc(lst_play->plr, &tmp->proc);
		tmp->proc.num = BPROC.nb_proc;
		BPROC.nb_proc += 1;
		tmp->next = BPROC.lst_proc;
		BPROC.lst_proc = tmp;
		lst_play = lst_play->next;
	}
	return (0);
}
