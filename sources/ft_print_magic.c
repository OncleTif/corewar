/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_magic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:21:35 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/28 12:40:12 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_print_magic(int fd)
{
	char	magic[4];

	magic[0] = COREWAR_EXEC_MAGIC / 256 / 256 / 256 % 256;
	magic[1] = COREWAR_EXEC_MAGIC / 256 / 256 % 256;
	magic[2] = COREWAR_EXEC_MAGIC / 256 % 256;
	magic[3] = COREWAR_EXEC_MAGIC % 256;
	write(fd, magic, sizeof(COREWAR_EXEC_MAGIC));
}
