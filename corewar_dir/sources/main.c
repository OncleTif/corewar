/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:46:44 by djoly             #+#    #+#             */
/*   Updated: 2016/05/25 18:51:33 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_core(t_vm *vm)
{
	int i;
	int	printed;
	t_process	*proc;

	i = 0;
	while (i < MEM_SIZE)
	{
		proc = vm->proc;
		printed = 0;
		if (i == 0)
			ft_printf("0x0000 : ");
		else if (i % 64 == 0)
			ft_printf("\n%#.4x : ", i);
		if (!vm->color)
			ft_printf("%.2x ", vm->core[i]);
		else if(vm->data[i].pc)
			ft_printf("\033[36m%.2x\033[00m ", vm->core[i]);
		else if (vm->data[i].num_plr == (int)vm->bplr.tab[0])
			ft_printf("\033[31m%.2x\033[00m ", vm->core[i]);
		else if (vm->data[i].num_plr == (int)vm->bplr.tab[1])
			ft_printf("\033[32m%.2x\033[00m ", vm->core[i]);
		else if (vm->data[i].num_plr == (int)vm->bplr.tab[2])
			ft_printf("\033[33m%.2x\033[00m ", vm->core[i]);
		else if (vm->data[i].num_plr == (int)vm->bplr.tab[3])
			ft_printf("\033[34m%.2x\033[00m ", vm->core[i]);
		else
			ft_printf("%.2x ", vm->core[i]);
		i++;
	}
	ft_putchar('\n');
}

void	print_t_vm(t_vm *vm)
{
	ft_printf("__dans VM __\ndump:%d\nverbose:%d\n", vm->dump, vm->verbose);
}

void	print_t_plr(t_list_player *lplr)
{
	t_list_player *tmp;
	tmp = lplr;
	char *buff;

	buff= NULL;
	while (tmp)
	{
		ft_printf("__dans BIN __\nnumplr:%u\nnom%s\nlast live:%d\n", tmp->plr->num_plyr,
		tmp->plr->prog_name, tmp->plr->last_live);
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
	ft_printf("\n__dans bplr__\nnb_plyr:%d\n", bplr->nb_plyr);
	ft_printf("numplr1:%d\nnumplr2:%d\nnumplr3:%d\nnumplr4:%d\n", bplr->tab[0], bplr->tab[1],
			bplr->tab[2], bplr->tab[3]);
}

void	print_corenum_plr(t_octet *core)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("\n");
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
			ft_printf("\n");
		ft_printf(" %u", core[i].pc);
		i++;
	}
}
t_bin	*who_win(t_vm *vm)
{
	t_list_player	*lplr;
	t_bin			*tmp;
	int				i;

	lplr = vm->bplr.lst_plyr;
	tmp = lplr->plr;
	i = 0;
	while (i < vm->bplr.nb_plyr)
	{
		if (lplr->plr->last_live > tmp->last_live)
			tmp = lplr->plr;
		lplr = lplr->next;
		i++;
	}
	return (tmp);
}

void	print_options(void)
{
	ft_printf("____ OPTION _____\n\n-d n\t\tdump la memoire au cycle n\n");
	ft_printf("-s n\t\tprint la memoire au cycle n et attend touche entre\n");
	ft_printf("-n n chp.cor\t\tinit le numero du joueur a n n\n");
	ft_printf("--visu : lance la version graphique\n");
	ft_printf("--color : lance le mode couleur\n");
	ft_printf("-v n\t\tverbose mode:\n");
	ft_printf("\t\t\t\t1 : affiche les lives\n");
	ft_printf("\t\t\t\t2 : affiche les cycles\n");
	ft_printf("\t\t\t\t4 : affiche la memoire\n");
	ft_printf("\t\t\t\t16 : affiche deplacement du pc\n");
}

void		print_finish(t_vm *vm)
{
	t_bin	*win;
	int		tmp;

	win = who_win(vm);
	if (win->num_plyr < 0)
		tmp = (-1 * win->num_plyr);
	else
		tmp = win->num_plyr;
	if (vm->dump != vm->cpu.cur_cycle)
		ft_printf("Contestant %d, \"%s\", has won !\n", tmp, win->prog_name); // merde si on a fait un -n
	if (vm->dump == vm->cpu.cur_cycle)
		print_core(vm);
}

int		main(int argc, char **argv)
{
	t_vm	vm;
	t_sdl 	sdl;

	vm_init(&vm);
	if (argc > 1)
	{
		ft_handle_args(argc, argv, &vm);
	}
	else
	{
		print_options();
		return(0);
	}
	ft_init_arena(&vm);
	ft_init_lst_proc(&vm);
	ft_print_header(&vm);
	init_struct_sdl(&sdl);
	cpu(&vm, &sdl);
	print_finish(&vm);
	return (0);
}
