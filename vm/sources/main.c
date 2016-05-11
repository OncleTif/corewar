/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:46:44 by djoly             #+#    #+#             */
/*   Updated: 2016/05/11 18:03:54 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
void	print_core(t_vm *vm)
{
	int i;
	int	printed;
	t_process	*proc;
	i = 0;
system("clear");
	while (i < MEM_SIZE)
	{
		proc = vm->proc;
		printed = 0;
		if (i == 0)
			printf("0x0000 :");
		if (i % 64 == 0 && i != 0)
			printf(" \n%#.4x :", i);
		//printf(" %.2d", core->core[i]);

		while (proc && !printed)
		{
			if (proc->pc == i)
			{
				printf(" \033[36m%.2x\033[00m", vm->core[i]);
				printed = 1;
			}
			proc = proc->next;
		}
		if (!printed)
		{
			if (vm->data[i].num_plr == -4)
				printf(" \033[31m%.2x\033[00m", vm->core[i]);
			else if (vm->data[i].num_plr == -3)
				printf(" \033[32m%.2x\033[00m", vm->core[i]);
			else if (vm->data[i].num_plr == -2)
				printf(" \033[33m%.2x\033[00m", vm->core[i]);
			else if (vm->data[i].num_plr == -1)
				printf(" \033[34m%.2x\033[00m", vm->core[i]);
			else
				printf(" %.2x", vm->core[i]);
		}
		i++;
	}
}

void	print_t_vm(t_vm *vm)
{
	printf("__dans VM __\ndump:%d\nverbose:%d\n", vm->dump, vm->verbose);
}

void	print_t_plr(t_list_player *lplr)
{
	t_list_player *tmp;
	tmp = lplr;
	char *buff;

	buff= NULL;
	while (tmp)
	{
		printf("__dans BIN __\nnumplr:%u\n", tmp->plr->num_plyr);
		print_magic(*tmp->plr, buff);
		print_prog_name(*tmp->plr);
		print_prog_size(*tmp->plr, buff);
		print_comment(*tmp->plr);
		print_prog(*tmp->plr);
		tmp = tmp->next;
	}
}

void	print_t_bplr(t_base_player *bplr)
{
	printf("\n__dans bplr__\nnb_plyr:%d\n", bplr->nb_plyr);
	printf("numplr1:%d\nnumplr2:%d\nnumplr3:%d\nnumplr4:%d\n", bplr->tab[0], bplr->tab[1],
			bplr->tab[2], bplr->tab[3]);
}

void	print_t_ir(t_ir *tir)
{
	int	i;

	i = 0;
	printf("\n__IR__\nirstr:");
	while (i < 14)
	{
		printf("%.2x ", (unsigned char)tir->irstr[i]);
		i++;
	}
	printf("opcode:%d ocp:%x index:%d nb_arg:%d\n", tir->opcode, tir->ocp,
			tir->index, tir->nb_arg);
	i = 0;
	while (i < 3)
	{
		printf("I = %d, TYPE => %x, CODE => %x, ARGS => %x\n", i, tir->types_args[i], tir->code_args[i], tir->args[i]);
		i++;
	}
	printf("\n");
}

void	print_t_proc(t_vm *vm)
{
	t_process *tmp2;
	int			i;

	tmp2 = vm->proc;
	while (tmp2)
	{
		printf("__DANS PROC__\nnum:%d\nnum_plr:%d\npc:%d\nreg0:%d\ncarry:%d\n cycle_to_wait:%d \n",
				tmp2->num, tmp2->num_plr, tmp2->pc, tmp2->reg[1], tmp2->carry,
				tmp2->cycle_to_wait);
		printf("\n________arene[pc]=");
		i = 0;
		while (i < 14)
		{
			printf("%.2x", vm->core[tmp2->pc + i]);
			i++;
		}
		printf("\n\npcdelta:%d carry:%d ir_error:%d \n", tmp2->pcdelta, tmp2->carry,
				tmp2->ir_error);
		i = 1;
		while (i < 17)
		{
			printf("__reg%d=%x\n", i, tmp2->reg[i]);
			i++;
		}
		print_t_ir(&tmp2->ir);
		tmp2 = tmp2->next;
	}
}
void	print_t_cpu(t_vm *vm)
{
	printf("___CPU___\ncur_cycle:%d\tcycle_to_check:%d\tcycle2die:%d\tnbchecks:%d\n",
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
			printf("\n");
		//printf(" %.2d", core->core[i]);
		printf(" %.2d", core[i].num_plr);
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
int		main(int argc, char **argv)
{
	t_vm	vm;

	vm_init(&vm);
	if (argc > 1)
	{
		ft_handle_args(argc, argv, &vm);
	}
	else
	{
		ft_error("Not enough arguments");
	}
	ft_init_arena(&vm);
	ft_init_lst_proc(&vm);
	cpu(&vm);

//	print_t_proc(&vm);
//	print_t_cpu(&vm);
	print_core(&vm);
	return (0);
}
