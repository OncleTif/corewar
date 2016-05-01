/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:46:44 by djoly             #+#    #+#             */
/*   Updated: 2016/05/01 15:45:26 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_print(t_vm *vm)
{
	t_list_player *tmp;
	char *buff = NULL;
	int i;
	i = 0;

	printf("__dans VM __\ndump:%d\nverbose:%d\n", vm->dump, vm->verbose);
	printf("__dans BPLR __\nnb_plyr:%d\n", vm->bplr.nb_plyr);
	printf("numplr1:%d\n numplr2:%d\nnumplr3:%d\nnumplr4:%d\n", BPLR.tab[0], BPLR.tab[1],
			BPLR.tab[2], BPLR.tab[3]);
	tmp = BPLR.lst_plyr;
	while (tmp)
	{
		printf("__dans BIN __\nnumplr:%d\n", tmp->plr->num_plyr);
		print_magic(*tmp->plr, buff);
		print_prog_name(*tmp->plr);
		print_prog_size(*tmp->plr, buff);
		print_comment(*tmp->plr);
		print_prog(*tmp->plr);
		tmp = tmp->next;
		i++;
	}
	printf("I=%d\n", i);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	if (argc > 1)
	{
		ft_handle_args(argc, argv, &vm);
	}
	else
	{
		ft_error("Not enough arguments");
	}
	ft_print(&vm);
	return (0);
}
