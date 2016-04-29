/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:07:57 by ssicard           #+#    #+#             */
/*   Updated: 2016/04/29 15:24:29 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		**ft_get_lbl(char **tab, t_champ *cmp)
{
	int	i;

	i = 1;
	if (ft_strchr(tab[0], ':'))
	{
		while (tab[i])
		{
			tab[i - 1] = tab[i];
			i++;
		}
	}
	cmp++;
	return (tab);
}

void		check_mask(int i, char *tmp, t_champ *cmp)
{
	ft_putnbrendl(g_op_tab[i].opcode);
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
	ft_putendl(tab[0]);
	tab = ft_get_lbl(tab, c);
	while (i < 16 && ft_strncmp(g_op_tab[i].name, tab[0], len))
		i++;
	ft_putendl(tab[0]);
	ft_putnbrendl(i);
	if (i < 16)
	{
		check_mask(i, tmp, c);

	}
//	else if (tab[0][0])
//		ft_error("wrong format line");
	c++;
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
