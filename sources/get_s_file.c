/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:07:57 by ssicard           #+#    #+#             */
/*   Updated: 2016/04/28 14:44:19 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static	void	get_str(t_champ *c, char *tmp, char *str)
{
	char	*line;
	int		indic;
	int		i;

	i = 0;
	indic = 0;
	tmp = ft_strchr(tmp, '"');
		tmp++;
	while (*tmp)
	{
		if (*tmp == '"')
		{
			indic = 1;
			break ;
		}
		str[i++] = *tmp++;
	}
	while (!indic)
	{
		get_next_line(c->fd, &line);
		str[i++] = '\n';
		while(*line)
		{
			if (*line == '"')
				indic = 2;
			else
				str[i++] = *line;
			line++;
		}
	}
	str[i] = '\0';
}

void		read_s_file(t_champ *c, char *file)
{
	char	*line;
	char	*tmp;

	if ((c->fd = open(file, O_RDONLY)) == -1)
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
				get_str(c, tmp, c->name);
			else if (ft_strncmp(".comment", tmp, 8) == 0)
				get_str(c, tmp, c->comment);
			// suite lecture
		}
	}
	printf("C_NAME = -->%s<--\n", c->name);
	printf("C_COMMENT = -->%s<--\n", c->comment);
}
