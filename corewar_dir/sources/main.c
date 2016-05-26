/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:46:44 by djoly             #+#    #+#             */
/*   Updated: 2016/05/26 16:58:01 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		main(int argc, char **argv)
{
	t_vm	vm;
	t_sdl	sdl;

	vm_init(&vm);
	if (argc > 1)
	{
		ft_handle_args(argc, argv, &vm);
	}
	else
	{
		print_options();
		return (0);
	}
	ft_init_arena(&vm);
	ft_init_lst_proc(&vm);
	ft_print_header(&vm);
	init_struct_sdl(&sdl);
	cpu(&vm, &sdl);
	print_finish(&vm);
	return (0);
}
