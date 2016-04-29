#include "../includes/corewar.h"

static void	ft_read_champion(int fd, t_bin *plr)
{
	char	*buff;
	int		ret;

	buff = malloc(sizeof(char) * 4 + 1);
	ft_stock_magic(fd, buff, plr);
	print_magic(*plr, buff);
	ft_stock_name(fd, plr);
	print_prog_name(*plr);
	ret = read(fd, buff, 4);
	if ((*((int *)buff)) || !ret)
		printf("error wrong first SEPARATOR\n");
	ft_stock_prog_size(fd, buff, plr);
	print_prog_size(*plr, buff);
	ft_stock_comment(fd, plr);
	print_comment(*plr);
	ret = read(fd, buff, 4);
	if ((*((int *)buff)) || !ret)
		printf("error wrong second SEPARATOR\n");
	ft_stock_program(fd, plr);
	print_prog(*plr);
}

void	ft_open_champion(char *line, t_bin *plr)
{
	int		fd;

	plr->magic = 0;
	plr->prog_size = 0;
	if ((fd = open(line, O_RDONLY)) == -1)
		printf("error\n");
	ft_read_champion(fd, plr);
}

int		main(int argc, char **argv)
{
	t_bin	*plr;

	plr = (t_bin *)malloc(sizeof(t_bin));
	(void)argc;
	ft_open_champion(argv[1], plr);
	return (0);
}
