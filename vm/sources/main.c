/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:46:44 by djoly             #+#    #+#             */
/*   Updated: 2016/05/06 17:05:33 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_core(t_vm *vm)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n");
		//printf(" %.2d", core->core[i]);
		printf(" %.2x", vm->core[i]);
		i++;
	}
}
void	ft_print(t_vm *vm)
{
	t_list_player *tmp;
	t_process *tmp2;
	char *buff = NULL;
	int i;

	i = 0;
	printf("__dans VM __\ndump:%d\nverbose:%d\n", vm->dump, vm->verbose);
	printf("__dans bplr__\nnb_plyr:%d\n", vm->bplr.nb_plyr);
	printf("numplr1:%u\nnumplr2:%u\nnumplr3:%u\nnumplr4:%u\n", BPLR.tab[0], BPLR.tab[1],
			BPLR.tab[2], BPLR.tab[3]);
	tmp = BPLR.lst_plyr;
	while (tmp)
	{
		printf("__dans BIN __\nnumplr:%u\n", tmp->plr->num_plyr);
		print_magic(*tmp->plr, buff);
		print_prog_name(*tmp->plr);
		print_prog_size(*tmp->plr, buff);
		print_comment(*tmp->plr);
		print_prog(*tmp->plr);
		tmp = tmp->next;
		i++;
	}
	tmp2 = vm->proc;
	while (tmp2)
	{
		printf("__DANS PROC__\nnum:%d\nnum_plr:%d\npc:%d\nreg0:%d\ncarry:%d\n",
				tmp2->num, tmp2->num_plr, tmp2->pc, tmp2->reg[1], tmp2->carry);
		printf("pcdelta:%d carry:%d ir_error:%d \n", tmp2->pcdelta, tmp2->carry,
			tmp2->ir_error);

		i = 0;
		printf("__IR__\nIR:");
		while (i < 14)
		{
			printf("%.2x ", (unsigned char)tmp2->ir.irstr[i]);
			i++;
		}
		printf("opcode:%d ocp:%x index:%d nb_arg:%d\n", tmp2->ir.opcode,tmp2->ir.ocp,
	 	tmp2->ir.index,tmp2->ir.nb_arg);
		i = 0;
		while (i < 3)
		{
			printf("I = %d, TYPE => %x, CODE => %x, ARGS => %x\n", i, tmp2->ir.types_args[i], tmp2->ir.code_args[i], tmp2->ir.args[i]);
			i++;
		}
		printf("\n");
		tmp2 = tmp2->next;
	}
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

	ft_print(&vm);
//	print_corepc(&vm.bcore);
	printf("\n\n");
//	print_corenum_plr(&vm.bcore);
	printf("\n\n");
	print_core(&vm);
	return (0);
}
