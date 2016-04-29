#include "../includes/corewar.h"

void print_magic(bin_t plr, char *buff)
{
	int i;

	i = 0;
	putchar('\n');
	while (i < 4)
	{
		printf("|%x|", buff[i]);
		i++;
	}
	printf("\n%x\n", plr.magic);
}

void print_prog_name(bin_t plr)
{
	int i;

	i = 0;
	while (plr.prog_name[i])
	{
		printf("%x", plr.prog_name[i]);
		i++;
	}
	putchar('\n');
}

void print_prog_size(bin_t plr, char *buff)
{
	int i;

	i = 0;
	while (i < 4)
	{
		printf("[%x]", buff[i]);
		i++;
	}
	printf("\n%x\n", plr.prog_size);
}

void print_comment(bin_t plr)
{
	int i;

	i = 0;
	putchar('\n');
	printf("commentaire\n");
	while (i < COMMENT_LENGTH)
	{
		printf("%X", plr.comment[i]);
		i++;
	}
	putchar('\n');
}

void print_prog(bin_t plr)
{
	int i;

	i = 0;
	printf("programme\n");
	while (i < plr.prog_size)
	{
		printf("%0x", plr.program[i]);
		i++;
	}
	putchar('\n');
}

void memrev(char  *buf, size_t count)
{
	char *r;

	r = buf + count - 1;
	while (buf < r)
	{
		*buf ^= *r;
		*r   ^= *buf;
		*buf ^= *r;
		buf++;
		r--;
	}
}

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

void	ft_stock_prog(int fd, bin_t *plr)
{
	int ret;

	if ((ret = read(fd, plr->program, plr->prog_size) == -1)
		printf("error\n");
	plr->program[ret] = '\0';
}

void	ft_read_champion(int fd, bin_t *plr)
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
	ft_stock_prog(fd, plr);
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
