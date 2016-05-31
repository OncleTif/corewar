/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:00:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/31 10:19:07 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		ft_stock_l_core(char **av, int *i, t_vm *vm)
{
	int		not0;

	(*i)++;
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	if ((not0 = ft_atoi_strict(av[*i])) <= 0)
		ft_error("ARG is not a number valid for l_dump");
	vm->l_core = not0;
	return (0);
}
