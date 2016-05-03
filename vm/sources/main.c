/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:46:44 by djoly             #+#    #+#             */
/*   Updated: 2016/05/03 14:19:34 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_core(t_base_core *bcore)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n");
		//printf(" %.2d", core->core[i]);
		printf(" %.2x", bcore->core[i]);
		i++;
	}
}
void	ft_print(t_vm *vm)
{
	t_list_player *tmp;
	t_list_process *tmp2;
	char *buff = NULL;
	int i;

	i = 0;
	printf("__dans VM __\ndump:%d\nverbose:%d\n", vm->dump, vm->verbose);
	printf("__dans BPLR __\nnb_plyr:%d\n", vm->bplr.nb_plyr);
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
	tmp2 = BPROC.lst_proc;
	while (tmp2)
	{
		printf("__DANS PROC__\nnum:%d\nnum_plr:%d\npc:%d\nreg0:%d\ncarry:%d\n",
				tmp2->proc.num, tmp2->proc.num_plr, tmp2->proc.pc, tmp2->proc.reg[0], tmp2->proc.carry);
		tmp2 = tmp2->next;
	}
}
void	print_corenum_plr(t_base_core *bcore)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n");
		//printf(" %.2d", core->core[i]);
		printf(" %.2d", bcore->data[i].num_plr);
		i++;
	}
}
void	print_corepc(t_base_core *bcore)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n");
		//printf(" %.2d", core->core[i]);
		printf(" %.2d", bcore->data[i].pc);
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
//	ft_print(&vm);
	print_corepc(&vm.bcore);
	printf("\n\n");
	print_corenum_plr(&vm.bcore);
	printf("\n\n");
	print_core(&vm.bcore);
	return (0);
}
