#include "../includes/corewar.h"

void	ft_stock_magic(int fd, char *buff, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, buff, 4)))
		printf("error READ magic\n");
	buff[ret] = '\0';
	memrev(buff, 4);
	plr->magic = (*((int *)buff));
	if (plr->magic ^ COREWAR_EXEC_MAGIC)
		ft_error("error wrong magic\n");
}

void	ft_stock_name(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->prog_name, PROG_NAME_LENGTH)))
		ft_error("error READ name\n");
	plr->prog_name[ret] = '\0';
}

void	ft_stock_prog_size(int fd, char *buff, t_bin *plr)
{
	int ret;

	if ((ret = read(fd, buff, 4) == -1))
		ft_error("error READ prog_size\n");
	buff[ret] = '\0';
	memrev(buff, 4);
	plr->prog_size = (*((int *)buff));
}

void	ft_stock_comment(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->comment, COMMENT_LENGTH)))
		ft_error("error READ comment\n");
	plr->comment[ret] = '\0';
}

void	ft_stock_program(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->program, plr->prog_size)))
		ft_error("error READ program\n");
	if (ret ^ plr->prog_size)
		ft_error("Wrong prog");
	plr->program[ret] = '\0';
}
