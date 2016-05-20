/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:33:39 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/20 14:26:45 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	ft_wait(void)
{
	char	*ptr;

	ptr = NULL;
	if (get_next_line(0, &ptr) < 0)
		ft_error("fail to wait");
	ft_memdel((void**)&ptr);
	return (1);
}
