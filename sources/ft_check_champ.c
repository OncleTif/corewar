/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:21:09 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/09 11:24:31 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_check_champ(t_champ *chp)
{
	if (!chp->name[0])
		ft_error("missing champ name");
	if (!chp->comment[0])
		ft_error("missing comment");
	if (!chp->bin[0])
		ft_error("missing instructions");
}
