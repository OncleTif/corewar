/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:50:09 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/29 15:36:36 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_print_champ(t_champ *chp)
{
	int	fd;

	if ((fd = open(chp->file_n, O_RDWR | O_CREAT | O_TRUNC, 644)) < 0)
		ft_error(ft_strjoin("error while opening file ", chp->file_n));
	ft_print_magic(fd);
	ft_print_name(chp, fd);
	ft_print_bin_size(chp, fd);
	ft_print_comment(chp, fd);
	ft_print_bin(chp, fd);
	ft_putendl(ft_strjoin("Writing output program to ", chp->file_n));
	close(fd);
}

void	ft_print_name(t_champ *chp, int fd)
{
	char	*zero;

	zero = "\0\0\0\0";
	write(fd, &chp->name, PROG_NAME_LENGTH);
	write(fd, zero, 4);
}

void	ft_print_magic(int fd)
{
	char	magic[4];

	magic[0] = COREWAR_EXEC_MAGIC / 256 / 256 / 256 % 256;
	magic[1] = COREWAR_EXEC_MAGIC / 256 / 256 % 256;
	magic[2] = COREWAR_EXEC_MAGIC / 256 % 256;
	magic[3] = COREWAR_EXEC_MAGIC % 256;
	write(fd, magic, sizeof(COREWAR_EXEC_MAGIC));
}

void	ft_print_comment(t_champ *chp, int fd)
{
	char	*zero;

	zero = "\0\0\0\0";
	printf("C_COMMENT = -->%s<--\n", chp->comment);
	write(fd, &chp->comment, COMMENT_LENGTH);
	write(fd, zero, 4);
}

void	ft_print_bin(t_champ *chp, int fd)
{
	write(fd, &chp->bin, chp->pos);
}

void	ft_print_bin_size(t_champ *chp, int fd)
{
	char	nbr[4];

	nbr[0] = chp->pos / 256 / 256 / 256;
	nbr[1] = chp->pos / 256 / 256 % 256;
	nbr[2] = chp->pos / 256 % 256;
	nbr[3] = chp->pos % 256;
	write(fd, nbr, 4);
}
