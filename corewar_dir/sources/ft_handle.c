/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:09:31 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/26 15:14:12 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

// int		ft_stock_num_plr(char **av, int *i, t_vm *vm)
// {
// 	(*i)++;
// 	if (!av[*i] || ft_is_number(av[*i]) == 0)
// 		ft_error("ARG is not a number");
// 	BPLR.tmpnum = BPLR.tab[BPLR.nb_plyr];
// 	BPLR.tab[BPLR.nb_plyr] = ft_atoi(av[*i]);
// 	BPLR.tab[BPLR.nb_plyr] = BPLR.tab[BPLR.nb_plyr]
// 	BPLR.i_plr += 1;
// 	ft_check_other_num(BPLR);
// 	return (0);
// }

int		ft_stock_num_plr(char **av, int *i, t_vm *vm)
{
	int		not0;

	(*i)++;
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	if ((not0 = ft_atoi(av[*i])) == 0)
		ft_error("ARG 0 is not a number valid to number player");
	BPLR.tab[BPLR.nb_plyr] = not0;
	BPLR.modif[BPLR.nb_plyr] = 1;
	BPLR.i_plr += 1;
	//ft_check_other_num(BPLR);
	return (0);
}

void	ft_handle_bonus(char **av, int *i, t_vm *vm)
{
	if (ft_strcmp("-v", av[*i]) == 0)
		ft_stock_verb(av, i, vm);
	else if (ft_strcmp("-d", av[*i]) == 0)
		ft_stock_dump(av, i, vm);
	else if (ft_strcmp("-a", av[*i]) == 0)
		ft_stock_aff(vm);
	else if (ft_strcmp("--color", av[*i]) == 0)
		ft_stock_color(vm);
	else if (ft_strcmp("-s", av[*i]) == 0)
		ft_stock_step(av, i, vm);
	else if (ft_strcmp("-n", av[*i]) == 0)
		ft_stock_num_plr(av, i, vm);
	else if (ft_strcmp("--visu", av[*i]) == 0)
		vm->visu = 1;
	else
		exit(ft_printf("ERROR ARGV\n"));
}

// void	ft_init_num_plr(t_base_player *player, t_list_player *tmp)
// {
// 	tmp->plr->num_plyr = player->tab[player->nb_plyr];
// 	tmp->plr->nbr_live = 0;
// }

void	ft_init_num_plr(t_base_player *player)
{
	t_list_player	*lplr;
	int				i;

	i = 0;
	ft_check_other_num(player);					 //
	lplr = player->lst_plyr;
	while (lplr)
	{
		lplr->plr->num_plyr = player->tab[i++];
		ft_printf("index_plyr %d num_plyr %d\n", lplr->plr->index_plyr, lplr->plr->num_plyr);
		lplr = lplr->next;
	}
}

void	ft_mem_champs(t_base_player *player, char *av)
{
	t_list_player	*tmp;
	t_list_player	*lplr;

	tmp = (t_list_player*)ft_memalloc(sizeof(t_list_player));
	tmp->plr = (t_bin *)ft_memalloc(sizeof(t_bin));
	ft_open_champion(av, tmp->plr);
	lplr = player->lst_plyr;
	while (lplr && lplr->next)
		lplr = lplr->next;
	if (!lplr)
		player->lst_plyr = tmp;
	else
		lplr->next = tmp;
	tmp->plr->index_plyr = player->nb_plyr + 1; //
	tmp->plr->nbr_live = 0;//
	//ft_check_other_num(player);					 //
	//ft_init_num_plr(player, tmp);
}

void	ft_handle_args(int ac, char **av, t_vm *vm)
{
	int				i;

	i = 1;
	BPLR.nb_plyr = 0;
	while (i < ac)
	{
		if (ft_check_args(av[i]))
		{
			ft_mem_champs(&(BPLR), av[i]);
			vm->bplr.nb_plyr += 1;
			if (BPLR.nb_plyr > 4)
				ft_error("Wrong number of players");
		}
		else
			ft_handle_bonus(av, &i, vm);
		i++;
	}
	ft_init_num_plr(&vm->bplr);
	if (BPLR.nb_plyr <= 0)
		ft_error("Wrong number of players");
}
