/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:07:57 by ssicard           #+#    #+#             */
/*   Updated: 2016/04/28 10:01:19 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static	void	get_name(char *line)
{




}

void		read_s_file(t_champ *c, char *file)
{
	char	*line;

	if (!(c->fd = open(file, O_RDONLY)))
	{
		printf("Open failed.\n");
		return ;
	}
	else
	{
		while (get_next_line(c->fd, &line))
		{
			tmp = ft_strtrim(line);
			if (ft_strncmp(".name", tmp, 5) == 0)
				get_name(tmp);
			else if (ft_strncmp(".comment", tmp, 8) == 0)
				get_comment(tmp);
			free(tmp);
			// suite lecture
		}
	}
}
