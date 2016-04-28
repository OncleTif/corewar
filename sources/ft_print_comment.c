/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:52:54 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/28 12:01:20 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_print_comment(t_champ *chp, int fd)
{
	char	*zero;

	zero = "\0\0\0\0";
	write(fd, &chp->comment, COMMENT_LENGTH);
	write(fd, zero, 4);
}
