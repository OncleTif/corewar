/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:46:44 by djoly             #+#    #+#             */
/*   Updated: 2016/05/26 12:25:42 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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

void	print_finish(t_vm *vm)
{
	t_bin	*win;
	int		tmp;

	win = who_win(vm);
	if (win->num_plyr < 0)
		tmp = (-1 * win->num_plyr);
	else
		tmp = win->num_plyr;
	if (vm->dump != vm->cpu.cur_cycle)
		ft_printf("Contestant %d, \"%s\", has won !\n", tmp, win->prog_name);
	if (vm->dump == vm->cpu.cur_cycle)
		print_core(vm);
}

int		main(int argc, char **argv)
{
	t_vm	vm;
	t_sdl	sdl;

	vm_init(&vm);
	if (argc > 1)
	{
		ft_handle_args(argc, argv, &vm);
	}
	else
	{
		print_options();
		return (0);
	}
	ft_init_arena(&vm);
	ft_init_lst_proc(&vm);
	ft_print_header(&vm);
	init_struct_sdl(&sdl);
	cpu(&vm, &sdl);
	print_finish(&vm);
	return (0);
}
