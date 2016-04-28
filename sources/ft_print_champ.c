/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:50:09 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/28 10:09:36 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_print_champ(t_champ *chp)
{
	int	fd;

	if ((fd = open(chp->file_n, O_WRONLY)) < 0)
		ft_error(ft_strjoin("error while opening file ", chp->file_n));
	ft_print_magic(fd);
	ft_print_name(chp, fd);
	ft_print_bin_size(chp, fd);
	ft_print_comment(chp, fd);
	ft_print_bin(chp, fd);
	ft_putendl(ft_strjoin("Writing output program to ", chp->file_n));
}
