/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:29:43 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/10 10:53:50 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_kill_proc(t_vm *vm, t_process *proc)
{
	t_process	**ptr;

	ptr = &vm->proc;
	while (*ptr)
	{
		if (*ptr == proc)
		{
			*ptr = proc->next;
			ft_memdel((void**)&proc);
		}
		ptr = &((*ptr)->next);
	}
}

int	to_kill_or_not_to_kill_proc(t_vm *vm)
{
	t_process	ptr;
	
	ptr = vm->proc; 
	while (ptr)
	{
		if (ptr->live < 1)
			ft_kill_proc(vm, ptr);
		else
			ptr->live = 0;
		ptr = ptr->next;
	}
	// QUOI SI TOUS LES PROC SONT MORT ?
	//FIN 
	return (0);
}
