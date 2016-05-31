/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 09:57:34 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/31 10:00:45 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		ft_stock_num_plr(char **av, int *i, t_vm *vm)
{
	int		not0;

	(*i)++;
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	if ((not0 = ft_atoi_strict(av[*i])) == 0)
		ft_error("ARG 0 is not a number valid to number player");
	if (av[(*i) + 1] == NULL)
		ft_error("ARG not even exist");
	if (ft_check_args(av[(*i) + 1]) == 0)
		ft_error("ERROR ARGV");
	BPLR.tab[BPLR.nb_plyr] = not0;
	BPLR.modif[BPLR.nb_plyr] = 1;
	BPLR.i_plr += 1;
	return (0);
}

void	ft_handle_bonus(char **av, int *i, t_vm *vm)
{
	if (ft_strcmp("-v", av[*i]) == 0)
		ft_stock_verb(av, i, vm);
	else if ((ft_strcmp("-d", av[*i]) == 0) ||
			(ft_strcmp("-dump", av[*i]) == 0))
		ft_stock_dump(av, i, vm);
	else if (ft_strcmp("-a", av[*i]) == 0)
		ft_stock_aff(vm);
	else if (ft_strcmp("--color", av[*i]) == 0)
		ft_stock_color(vm);
	else if (ft_strcmp("-s", av[*i]) == 0)
		ft_stock_step(av, i, vm);
	else if (ft_strcmp("-n", av[*i]) == 0)
		ft_stock_num_plr(av, i, vm);
	else if (ft_strcmp("-l", av[*i]) == 0)
		ft_stock_l_core(av, i, vm);
	else if (ft_strcmp("--visu", av[*i]) == 0)
		vm->visu = 1;
	else
		ft_error("ERROR ARGV");
	ft_check_bonus(vm);
}

void	ft_init_num_plr(t_base_player *player)
{
	t_list_player	*lplr;
	int				i;
	int				j;

	i = 0;
	ft_check_other_num(player);
	lplr = player->lst_plyr;
	while (lplr)
	{
		lplr->plr->num_plyr = player->tab[i++];
		lplr = lplr->next;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != j && player->tab[i] == player->tab[j])
				ft_error("Error same number player");
			j++;
		}
		i++;
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
	tmp->plr->index_plyr = player->nb_plyr + 1;
	tmp->plr->nbr_live = 0;
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
