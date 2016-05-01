#include "../includes/corewar.h"

/*
checker si cest un ".cor" return 1, sinon 0
*/

int		ft_check_args(char *av)
{
	char *str;

	ft_putstr(av);
	str = ft_strstr(av, ".cor");
	if (!str)
		return (0);
	if (ft_strcmp(str, ".cor\0") == 0)
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
	vm->dump = ft_atoi(av[*i]);
	return (1);
}
/*
fonction recupere le verbose et stock dans la T_vm
*/

int		ft_stock_verbose(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (ft_is_number(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->verbose = ft_atoi(av[*i]);
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
		if ((i != bplr.i_plr) && (bplr.tab[bplr.i_plr] == bplr.tab[i]))
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
	BPLR.tmpnum = BPLR.tab[BPLR.nb_plyr];
	BPLR.tab[BPLR.nb_plyr] = ft_atoi(av[*i]);
	BPLR.i_plr += 1;
	ft_check_other_num(BPLR);
	return (0);
}

/*
fonction pour gerer les bonus et ARGS
*/

void	ft_handle_bonus(char **av, int *i, t_vm *vm)
{
	if (ft_strcmp("-d", av[*i]) == 0){
		ft_putstr(">>DANS -D<<");
		ft_stock_dump(av, i, vm);
	}
	if (ft_strcmp("-n", av[*i]) == 0)
	{
		ft_putstr(">>DANS -N<<");


		ft_stock_num_plr(av, i, vm);
	}
	if (ft_strcmp("-v", av[*i]) == 0)
	{
		ft_putstr(">>DANS -V<<");
		ft_stock_verbose(av, i, vm);
}}

/*
INIT numero du plr
*/
void	ft_init_num_plr(t_base_player *player, t_list_player *tmp)
{
	tmp->plr->num_plyr = player->tab[player->nb_plyr];
}

/*
alloue de la memoire pour une nouvelle cellule et met de l'information dedans,
*/
void	ft_mem_champs(t_base_player *player, char *av)
{
	t_list_player	*tmp;
	t_list_player	*tmp2;

	tmp = (t_list_player*)ft_memalloc(sizeof(t_list_player));
	tmp->plr = (t_bin *)ft_memalloc(sizeof(t_bin));
	ft_open_champion(av, tmp->plr);
	if (!player->lst_plyr)
	{
		player->lst_plyr = tmp;
	}
	else
	{
		tmp2 = player->lst_plyr;
		player->lst_plyr = tmp;
		tmp->next = tmp2;
	}
	ft_init_num_plr(player, tmp);
//	player->nb_plyr = player->nb_plyr + 1;
}

/*
gerer chaque arguments, voir si cest un ".cor" (rentre dans les verifs des champions), sinon dans ceux des bonus
*/

void	ft_handle_args(int ac, char **av, t_vm *vm)
{
	int				i;
//	t_base_player	*player;

	i = 1;
//	player = (t_base_player*)ft_memalloc(sizeof(t_base_player));
	BPLR.nb_plyr = 0;
			ft_putstr(">>WTF<<\n");
	while (i < ac)
	{
		if (ft_check_args(av[i]))
		{
			ft_putstr(">>WTF<<\n");
			ft_mem_champs(&(BPLR), av[i]);
			vm->bplr.nb_plyr += 1;
			printf("nombre de joueurs : %d\n", vm->bplr.nb_plyr);
			if (BPLR.nb_plyr > 4)
				ft_error("Wrong number of players");
		}
		else
		{
			ft_putstr(">>GO IN HANDE BONUS<<\n");
			ft_handle_bonus(av, &i, vm);
		}
		i++;
	}
	if (BPLR.nb_plyr <= 0)
		ft_error("Wrong number of players");
			ft_putstr(">>FIN<<\n");
}
