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
fonction pour gerer les bonus
*/

void	ft_handle_bonus(char *av)
{
	(void)av;
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

void	ft_handle_args(int ac, char **av)
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
			ft_handle_bonus(av[i]);
		}
		i++;
	}
	printf("nombre de joueurs : %d\n", player->nb_plyr);
	if (!(player->nb_plyr > 0 && player->nb_plyr < 5))
		ft_error("Wrong number of players");
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_handle_args(argc, argv);
	}
	else
	{
		ft_error("Not enough arguments");
	}
	return (0);
}
