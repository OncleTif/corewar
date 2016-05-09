/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:55:31 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/09 11:26:00 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		main(int argc, char **argv)
{
	t_champ	chp;

	init_structure(&chp);
	if (argc == 2 && argv[1])
	{
		read_s_file(&chp, argv[1]);
		//argv[1] = epur_file_name(argv[1]);
		chp.file_n = ft_strjoin(argv[1], ".cor");
		ft_find_labels(&chp);
		ft_check_champ(&chp);
		ft_print_champ(&chp);
	}
	else
		ft_putendl("Bad parameters");
	return (0);
}
