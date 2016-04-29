#include "../includes/corewar.h"

void	ft_stock_magic(int fd, char *buff, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, buff, 4)))
		printf("error READ magic");
	buff[ret] = '\0';
	memrev(buff, 4);
	plr->magic = (*((int *)buff));
	print_magic(*plr, buff);
	if (plr->magic ^ COREWAR_EXEC_MAGIC)
		ft_error("error wrong magic");
}

void	ft_stock_name(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->prog_name, PROG_NAME_LENGTH)))
		ft_error("error READ name");
	plr->prog_name[ret] = '\0';
	print_prog_name(*plr);
}

void	ft_stock_prog_size(int fd, char *buff, t_bin *plr)
{
	int ret;

	if ((ret = read(fd, buff, 4) == -1))
		ft_error("error READ prog_size");
	buff[ret] = '\0';
	memrev(buff, 4);
	plr->prog_size = (*((int *)buff));
	print_prog_size(*plr, buff);
}

void	ft_stock_comment(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->comment, COMMENT_LENGTH)))
		ft_error("error READ comment");
	plr->comment[ret] = '\0';
	print_comment(*plr);
}

void	ft_stock_program(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->program, plr->prog_size)))
		ft_error("error READ program");
	if (ret ^ plr->prog_size)
		ft_error("Wrong prog");
	plr->program[ret] = '\0';
	print_prog(*plr);
}
