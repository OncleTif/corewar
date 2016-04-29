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
