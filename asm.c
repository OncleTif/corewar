/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:55:31 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/03 19:11:27 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static char *epur_file_name(char *str)
{
	size_t len;

	len = ft_strlen(str);
	if (str[len - 1] == 's' && str[len - 2] == '.')
		str = ft_strsub(str, 0, len - 2);
	return (str);
}

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
		ft_print_champ(&chp);
	}
	else
		ft_putendl("Bad parameters");
	return (0);
}
