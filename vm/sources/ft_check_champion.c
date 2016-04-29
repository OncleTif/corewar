#include "../includes/corewar.h"

static void	ft_read_champion(int fd, t_bin *plr)
{
	char	*buff;
	int		ret;

	buff = malloc(sizeof(char) * 4 + 1);
	ft_stock_magic(fd, buff, plr);
	ft_stock_name(fd, plr);
	ret = read(fd, buff, 4);
	if ((*((int *)buff)) || !ret)
		printf("error wrong first SEPARATOR");
	ft_stock_prog_size(fd, buff, plr);
	ft_stock_comment(fd, plr);
	ret = read(fd, buff, 4);
	if ((*((int *)buff)) || !ret)
		printf("error wrong second SEPARATOR");
	ft_stock_program(fd, plr);
}

void	ft_open_champion(char *line, t_bin *plr)
{
	int		fd;

	plr->magic = 0;
	plr->prog_size = 0;
	if ((fd = open(line, O_RDONLY)) == -1)
		ft_error("error");
	ft_read_champion(fd, plr);
}

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

void	ft_handle_bonus(char *av)
{
	(void)av;
}

void	ft_mem_champs(t_base_player *player, char *av)
{
	player->lst_plyr = (t_list_player*)ft_memalloc(sizeof(t_list_player));
	player->lst_plyr->plr = (t_bin *)ft_memalloc(sizeof(t_bin));
	ft_open_champion(av, player->lst_plyr->plr);
	player->lst_plyr = player->lst_plyr->next;
	player->nb_plyr++;
}

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
