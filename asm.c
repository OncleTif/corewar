/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:55:31 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/29 09:30:47 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		main(int argc, char **argv)
{
	t_champ	chp;

	//init_structure(&chp);
	if (argc == 2 && argv[1])
	{
		read_s_file(&chp, argv[1]);
		chp.file_n = ft_strjoin(argv[1], ".cor");
		ft_print_champ(&chp);
	}
	else
		ft_putendl("Bad parameters");
	return (0);
}
