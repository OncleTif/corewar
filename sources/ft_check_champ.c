/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:21:09 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/09 12:01:20 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_check_champ(t_champ *chp)
{
	if (!chp->name[0])
	{
		ft_putnbrendl((int)chp->name[0]);
		ft_error(ft_strjoin("missing champ name in file ", chp->file_n));
	}
		if (!chp->comment[0])
		ft_error(ft_strjoin("missing comment in file ", chp->file_n));
	if (!chp->bin[0])
		ft_error(ft_strjoin("missing instructions in file ", chp->file_n));
}
