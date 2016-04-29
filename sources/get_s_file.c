/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:07:57 by ssicard           #+#    #+#             */
/*   Updated: 2016/04/29 18:25:55 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		**ft_get_lbl(char **tab, t_champ *cmp)
{
	int		i;
	char	*end;

	i = 1;
	if ((end = ft_strchr(tab[0], ':')))
	{
		ft_putstr("**");
		ft_putstr(tab[0]);
		ft_putstr("**");
				ft_putendl("label!!");
		ft_add_label(cmp, ft_strsub(tab[0], 0, end - tab[0]));
		if (!tab[0][(int)end - (int)tab[0] + 1])
		{
			ft_putchar(tab[0][(int)end - (int)tab[0] + 1]);
				ft_putendl("decal!!");
				tab[0][0] = 0;
			while (tab[i])
			{
				tab[i - 1] = tab[i];
				i++;
			}
		}
		else
			tab[0] = ft_strtrim(end + 1);
	}
	return (tab);
}

void		check_mask(int i, char **tmp, t_champ *cmp)
{
	cmp->bin[cmp->pos] = (char)g_op_tab[i].opcode;
	cmp->pos++;
	tmp++;
}

void		get_instr(t_champ *c, char *tmp)
{
	char	**tab;
	int		i;
	size_t	len;

	tab = ft_strsplit(tmp, ' ');
	len = ft_strlen(tab[0]);
	i = 0;
	tab = ft_get_lbl(tab, c);
	//ft_putendl(ft_strjoin("lecture attr", tab[0]));
	while (i < 16 && ft_strncmp(g_op_tab[i].name, tab[0], len))
		i++;
	if (i < 16)
		check_mask(i, tab, c);
	//else if (tab[0][0] && tab[0][0] != '#' && tab[0][0] != ' ' )
	//	ft_error("wrong format line");
}

int			check_str(t_champ *c)
{
	int		i;

	i = 0;
	while (c->name[i])
	{
		if (ft_strchr(LABEL_CHARS, c->name[i]) == NULL)
			return (0);
		// donc la ca retourne zero c'est pas bon ca veut dire
		i++;
	}
	i = 0;
	/*	while (c->comment[i])
		{
		if (ft_strchr(COMMENT_CHARS, c->comment[i]) == NULL)
		return (0);
	// donc la ca retourne zero c'est pas bon ca veut dire
	i++;
	}*/
	return (1);
}

void		get_str(t_champ *c, char *tmp, char *str)
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
			else if (line[0])
			{
				ft_putendl(ft_strjoin("lecture ligne instruc", line));
				get_instr(c, tmp);
			}
			// suite lecture
		}
		if (!check_str(c))
			ft_error("Error in name or comment");
	}
	printf("C_NAME = -->%s<--\n", c->name);
	printf("C_COMMENT = -->%s<--\n", c->comment);
}
