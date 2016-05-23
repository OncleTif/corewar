/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_champion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:55:00 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/23 10:55:25 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_magic(t_bin plr, char *buff)
{
	int	i;

	i = 0;
	(void)buff;
	printf("\n%x\n", plr.magic);
}

void	print_prog_name(t_bin plr)
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

void	print_prog_size(t_bin plr, char *buff)
{
	int i;

	i = 0;
	(void)buff;
	printf("\n%x\n", plr.prog_size);
}

void	print_comment(t_bin plr)
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

void	print_prog(t_bin plr)
{
	int i;

	i = 0;
	printf("programme\n");
	while (i < r4oi(plr.prog_size))
	{
		printf("%0x", plr.program[i]);
		i++;
	}
	putchar('\n');
}
