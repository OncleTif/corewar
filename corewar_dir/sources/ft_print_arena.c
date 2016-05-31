/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 19:17:03 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/31 09:59:08 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void			print_color(t_vm *vm, int i)
{
	if (vm->data[i].pc)
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
}

void				print_core(t_vm *vm)
{
	int				i;
	int				printed;
	t_process		*proc;

	i = 0;
	while (i < MEM_SIZE)
	{
		proc = vm->proc;
		printed = 0;
		if (i == 0)
			ft_printf("0x0000 : ");
		else if (i % vm->l_core == 0)
			ft_printf("\n%#.4x : ", i);
		if (!vm->color)
			ft_printf("%.2x ", vm->core[i]);
		else
			print_color(vm, i);
		i++;
	}
	ft_putchar('\n');
}

void				print_t_vm(t_vm *vm)
{
	ft_printf("__dans VM __\ndump:%d\nverbose:%d\n", vm->dump, vm->verbose);
}

void				print_t_plr(t_list_player *lplr)
{
	t_list_player	*tmp;
	char			*buff;

	tmp = lplr;
	buff = NULL;
	while (tmp)
	{
		ft_printf("__dans BIN __\nnumplr:%u\nnom%s\nlast live:%d\n",
				tmp->plr->num_plyr,
				tmp->plr->prog_name, tmp->plr->last_live);
		print_magic(*tmp->plr, buff);
		print_prog_name(*tmp->plr);
		print_prog_size(*tmp->plr, buff);
		print_comment(*tmp->plr);
		print_prog(*tmp->plr);
		tmp = tmp->next;
	}
}

void				print_t_bplr(t_base_player *bplr)
{
	ft_printf("\n__dans bplr__\nnb_plyr:%d\n", bplr->nb_plyr);
	ft_printf("numplr1:%d\nnumplr2:%d\nnumplr3:%d\nnumplr4:%d\n",
			bplr->tab[0], bplr->tab[1], bplr->tab[2], bplr->tab[3]);
}
