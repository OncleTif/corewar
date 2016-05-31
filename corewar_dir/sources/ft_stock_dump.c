/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 22:00:08 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/31 09:23:05 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		ft_stock_color(t_vm *vm)
{
	vm->color = 1;
	return (1);
}

int		ft_stock_aff(t_vm *vm)
{
	vm->aff = 1;
	return (1);
}

int		ft_stock_verb(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->verbose = vm->verbose | (ft_atoi_strict(av[*i]) & 63);
	return (1);
}

int		ft_stock_step(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->step = ft_atoi_strict(av[*i]);
	if (vm->step < 1)
		ft_error("step can't be fewer than 1");
	return (1);
}

int		ft_stock_dump(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (!av[*i] || ft_isnumber(av[*i]) == 0)
		ft_error("ARG is not a number");
	vm->dump = ft_atoi_strict(av[*i]);
	if (vm->dump < 1)
		ft_error("dump can't be fewer than 1");
	return (1);
}
