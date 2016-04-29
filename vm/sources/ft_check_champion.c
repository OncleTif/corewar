#include "../includes/corewar.h"

static void	ft_read_champion(int fd, bin_t *plr)
{
	char	*buff;
	int		ret;

	buff = malloc(sizeof(char) * 4 + 1);
	ft_stock_magic(fd, buff, plr);
	print_magic(*plr, buff);
	ft_stock_name(fd, buff, plr);
	print_prog_name(*plr);
	ft_stock_prog_size(fd, buff, plr);
	print_prog_size(*plr, buff);
	ft_stock_comment(fd, buff, plr);
	ret = read(fd, buff, 4);
	if ((*((int *)buff)) || !ret)
		printf("error\n");
	print_comment(*plr);
	ft_stock_program(fd, plr);
	print_prog(*plr);
}

void	ft_open_champion(char *line, bin_t *plr)
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
	int		fd;
	int		ret;
	bin_t	*plr;
	char	*buff;

	plr = (bin_t *)malloc(sizeof(bin_t));
	(void)argc;
	ft_open_champion(argv[1], plr);
	return (0);
}
