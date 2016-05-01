#include "../includes/corewar.h"

/*
checker si cest un ".cor" return 1, sinon 0
*/

int		ft_check_args(char *av)
{
	if (ft_strcmp(ft_strstr(av, ".cor"), ".cor\0") == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
fonction check si le dump et num_plr est bien un nombre
*/

int		ft_is_number(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
fonction recupere le dump et stock dans la T_vm
*/

int		ft_stock_dump(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (ft_is_number(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->dump = ft_itoa(av[*i]);
	return (1);
}

/*
Change les autre num de plr en cas de doublon
*/
void	ft_check_other_num(t_base_player bplr)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((i != bplr.i_plr) && (bplr.tab[bplr.iplr] == bplr.tab[i]))
			bplr.tab[i] = bplr.tmpnum;
		i++;
	}
}

/*
fonction recupere le num du plr et stock dans la T_vm
*/
int		ft_stock_num_plr(char **av, int *i, t_vm *vm)
{

	(*i)++;
	if (ft_is_number(av[*i]) == 0)
		ft_error("ARG is not a number");
	BPLR.tmpnum = BPLR.tab[BPLR.i_plr];
	BPLR.tab[BPLR.i_plr] = ft_itoa(av[*i]);
	BPLR.i_plr += BPLR.i_plr + 1;
	ft_check_other_num(BPLR);
}

/*
fonction pour gerer les bonus
*/

void	ft_handle_bonus(char **av, int *i, t_vm *vm)
{
	if (ft_strcmp("-d", av[*i]) == 0)
		ft_stock_dump(av, i, vm);
	if (ft_strcmp("-n", av[*i]) == 0)
		ft_stock_num_plr(av, i, vm);




}
/*
alloue de la memoire pour une nouvelle cellule et met de l'information dedans,
*/
void	ft_mem_champs(t_base_player *player, char *av)
{
	player->lst_plyr = (t_list_player*)ft_memalloc(sizeof(t_list_player));
	player->lst_plyr->plr = (t_bin *)ft_memalloc(sizeof(t_bin));
	ft_open_champion(av, player->lst_plyr->plr);
	player->lst_plyr = player->lst_plyr->next;
	player->nb_plyr++;
}

/*
gerer chaque arguments, voir si cest un ".cor" (rentre dans les verifs des champions), sinon dans ceux des bonus
*/

void	ft_handle_args(int ac, char **av, t_vm *vm)
{
	int				i;
	t_base_player	*player;

	i = 1;
	player = (t_base_player*)ft_memalloc(sizeof(t_base_player));
	player->nb_plyr = 0;
	while (i < ac)
	{
		if (ft_check_args(av[i]))
		{
			ft_mem_champs(player, av[i]);
		}
		else
		{
			ft_handle_bonus(av, &i, vm);
		}
		i++;
	}
	printf("nombre de joueurs : %d\n", player->nb_plyr);
	if (!(player->nb_plyr > 0 && player->nb_plyr < 5))
		ft_error("Wrong number of players");
}
