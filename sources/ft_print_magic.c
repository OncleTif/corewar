/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_magic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:21:35 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/28 10:48:24 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_print_magic(int fd)
{
	int	i;

	i = COREWAR_EXEC_MAGIC;
	write(fd, &i, sizeof(COREWAR_EXEC_MAGIC));
}
