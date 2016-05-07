/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:46:44 by djoly             #+#    #+#             */
/*   Updated: 2016/05/06 20:20:54 by djoly            ###   ########.fr       */
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
			printf("%.2x ", (unsigned char)ir->irstr[i]);
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

void	print_t_proc(t_proc *proc)
{
	t_process *tmp2;
	
	tmp2 = proc;
	while (tmp2)
	{
		printf("__DANS PROC__\nnum:%d\nnum_plr:%d\npc:%d\nreg0:%d\ncarry:%d\n cycle_to_wait:%d \n",
				tmp2->num, tmp2->num_plr, tmp2->pc, tmp2->reg[1], tmp2->carry,
				tmp2->cycle_to_wait);
		printf("pcdelta:%d carry:%d ir_error:%d \n", tmp2->pcdelta, tmp2->carry,
			tmp2->ir_error);
		print_t_ir(&tmp->ir);
		tmp2 = tmp2->next;
	}
}

void	ft_print(t_vm *vm)
{
	//print_t_cpu(vm->cpu);
	print_t_vm(vm);
	print_t_bplr(vm->bplr);
	print_t_plr(vm->bplr->lst_plyr);	
	print_t_proc(vm->proc);
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
		ft_putendl("\n__DEBUT CYCLE1 __\n");
	ft_init_arena(&vm);
		ft_putendl("\n__DEBUT CYCLE2 __\n");
	ft_init_lst_proc(&vm);
		ft_putendl("\n__DEBUT CYCLE3 __\n");
	cpu(&vm);
		ft_putendl("\n__DEBUT CYCLE4 __\n");

	ft_print(&vm);
//	print_corepc(&vm.bcore);
	printf("\n\n");
//	print_corenum_plr(&vm.bcore);
	printf("\n\n");
	print_core(&vm);
	return (0);
}
