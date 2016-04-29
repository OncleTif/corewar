#include "../includes/corewar.h"

void	ft_stock_magic(int fd, char *buff, bin_t *plr)
{
	int ret;

	if ((ret = read(fd, buff, 4)) == -1)
		printf("error\n");
	buff[ret] = '\0';
	memrev(buff, 4);
	plr->magic = (*((int *)buff));
}

void	ft_stock_name(int fd, char *buff, bin_t *plr)
{
	int ret;

	if ((ret = read(fd, plr->prog_name, PROG_NAME_LENGTH)) == -1)
		printf("error\n");
	plr->prog_name[ret] = '\0';
	ret = read(fd, buff, 4);
	buff[ret] = '\0';
}

void	ft_stock_prog_size(int fd, char *buff, bin_t *plr)
{
	int ret;

	if ((ret = read(fd, buff, 4) == -1))
		printf("error\n");
	buff[ret] = '\0';
	memrev(buff, 4);
	plr->prog_size = (*((int *)buff));
}

void	ft_stock_comment(int fd, char *buff, bin_t *plr)
{
	int ret;

	if ((ret = read(fd, plr->comment, COMMENT_LENGTH)) == -1)
		printf("error\n");
	plr->comment[ret] = '\0';
}

void	ft_stock_program(int fd, bin_t *plr)
{
	int ret;

	if ((ret = read(fd, plr->program, plr->prog_size) == -1)
		printf("error\n");
	plr->program[ret] = '\0';
}
