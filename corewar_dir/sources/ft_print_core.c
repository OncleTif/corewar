/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 17:28:06 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/22 19:16:44 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_t_proc(t_vm *vm)
{
	t_process *tmp2;
	int			i;

	tmp2 = vm->proc;
	while (tmp2)
	{
		ft_printf("__DANS PROC__\nnum:%d\nnum_plr:%d\npc:%d\nreg0:%d\ncarry:%d\n cycle_to_wait:%d \n",
				tmp2->num, tmp2->num_plr, tmp2->pc, tmp2->reg[1], tmp2->carry,
				tmp2->cycle_to_wait);
		ft_printf("\n________arene[pc]=");
		i = 0;
		while (i < 14)
		{
			ft_printf("%.2x", vm->core[tmp2->pc + i]);
			i++;
		}
		ft_printf("\n\npcdelta:%d carry:%d ir_error:%d \n", tmp2->pcdelta, tmp2->carry,
				tmp2->ir_error);
		i = 1;
		while (i < 17)
		{
			ft_printf("__reg%d=%x\n", i, tmp2->reg[i]);
			i++;
		}
		print_t_ir(&tmp2->ir);
		tmp2 = tmp2->next;
	}
}

void	print_t_cpu(t_vm *vm)
{
	ft_printf("___CPU___\ncur_cycle:%d\tcycle_to_check:%d\tcycle2die:%d\tnbchecks:%d\n",
			vm->cpu.cur_cycle, vm->cpu.cycle_to_check, vm->cpu.cycle2die, vm->cpu.nbchecks);

}

void	ft_print(t_vm *vm)
{
	print_t_cpu(vm);
	print_t_vm(vm);
	print_t_bplr(&vm->bplr);
	print_t_plr(vm->bplr.lst_plyr);
	print_t_proc(vm);
}

void	print_corenum_plr(t_octet *core)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("\n");
		//printf(" %.2d", core->core[i]);
		ft_printf(" %.2d", core[i].num_plr);
		i++;
	}
}

void	print_corepc(t_octet *core)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n");
		//printf(" %.2d", core->core[i]);
		printf(" %u", core[i].pc);
		i++;
	}
}
