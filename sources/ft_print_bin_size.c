/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bin_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:55:06 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/28 12:02:13 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_print_bin_size(t_champ *chp, int fd)
{
	char	nbr[4];

	nbr[0] = chp->pos / 256 / 256 / 256;
	nbr[1] = chp->pos / 256 / 256 % 256;
	nbr[2] = chp->pos / 256 % 256;
	nbr[3] = chp->pos % 256;
	write(fd, nbr, 4);
}
