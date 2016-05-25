/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:29:43 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/25 18:10:53 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_kill_proc(t_vm *vm, t_process *proc)
{
	t_process	**ptr;

	ptr = &vm->proc;
	if (vm->verbose & 8)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", proc->num,
				vm->cpu.cur_cycle - proc->lst_live, vm->cpu.cycle2die);
	while (*ptr && *ptr != proc)
		ptr = &((*ptr)->next);
	if (*ptr)
		*ptr = proc->next;
	vm->data[proc->pc].pc--;
	ft_memdel((void**)&proc);
}

int		to_kill_or_not_to_kill_proc(t_vm *vm)
{
	t_process	*ptr;

	ptr = vm->proc;
	while (ptr)
	{
		if (ptr->live < 1)
			ft_kill_proc(vm, ptr);
		ptr = ptr->next;
	}
	if (vm->proc == NULL)
		return (1);
	return (0);
}
