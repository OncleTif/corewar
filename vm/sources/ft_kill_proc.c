/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:29:43 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/17 18:05:01 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_kill_proc(t_vm *vm, t_process *proc)
{
	t_process	**ptr;
	//ft_printf("\n\n_________BEG KILL____________\n\n");

	ptr = &vm->proc;
	//ft_printf("\n\n_________INTER KILL____________\n\n");
	while (*ptr)
	{
		if (*ptr == proc)
		{
			*ptr = proc->next;
			ft_memdel((void**)&proc);
			break ; // pourquoi ca segfault sans break: no idea
		}
		ptr = &((*ptr)->next);
	}
	//ft_printf("\n\n_________END KILL____________\n\n");
}

int	to_kill_or_not_to_kill_proc(t_vm *vm)
{
	t_process	*ptr;
	//ft_printf("\n\n_________BEG____________\n\n");
	ptr = vm->proc;
	while (ptr)
	{
		if (ptr->live < 1)
			ft_kill_proc(vm, ptr);
		else
			ptr->live = 0;
		ptr = ptr->next;
	}
	if (vm->proc == NULL)
		return (1);
	// QUOI SI TOUS LES PROC SONT MORT ?
	//FIN
	return (0);
}
