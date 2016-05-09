/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:18:32 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/09 10:41:14 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_str(t_champ *c)
{
	int		i;

	i = 0;
	while (c->name[i])
	{
		if (ft_strchr(LABEL_CHARS, c->name[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

void		get_str(t_champ *c, char *tmp, char *str)
{
	char	*line;
	int		indic;
	int		i;

	i = 0;
	indic = 0;
	tmp = ft_strchr(tmp, '"') + 1;
	while (*tmp && *tmp != '"')
		str[i++] = *tmp++;
	if (*tmp == '"')
		indic = 1;
	while (!indic)
	{
		if (get_next_line(c->fd, &line) < 1)
			ft_error("error while reading a name or comment, missing '\"'");
		str[i++] = '\n';
		while (*line && *line != '"')
		{
			str[i++] = *line;
			line++;
		}
		if (*line == '"')
			indic = 2;
		c->line++;
	}
	str[i] = '\0';
}

char		*ft_strtrim_com(char *line)
{
	if (ft_strchr(line, '#'))
		line = ft_strsub(line, 0, ft_strchr(line, '#') - line);
	if (ft_strchr(line, ';'))
		line = ft_strsub(line, 0, ft_strchr(line, ';') - line);
	return (ft_strtrim(line));
}

void		read_s_file(t_champ *c, char *file)
{
	char	*line;
	char	*tmp;

	if ((c->fd = open(file, O_RDONLY)) == -1)
	{
		ft_error("Open failed.");
	}
	else
	{
		while (get_next_line(c->fd, &line) > 0)
		{
			if ((tmp = ft_strtrim_com(line)))
			{
				if (ft_strncmp(".name", tmp, 5) == 0)
					get_str(c, tmp, c->name);
				else if (ft_strncmp(".comment", tmp, 8) == 0)
					get_str(c, tmp, c->comment);
				else if (line[0])
					find_instr(c, tmp);
			}
			c->line++;
		}
	}
}
