/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_winner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 19:14:49 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/22 19:15:25 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_bin		*who_win(t_vm *vm)
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

void		print_options(void)
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
	ft_printf("Contestant %d (%s), has won !\n", tmp, win->prog_name); // merde si on a fait un -n
	if (vm->verbose & 32 || vm->dump > 0)
	{
		//print_t_cpu(vm);
		print_core(vm);
//		print_t_proc(vm);
	}
}
