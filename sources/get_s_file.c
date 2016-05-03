/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:07:57 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/03 15:26:19 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../vm/includes/reverse_octet.h"

char		**ft_get_lbl(char **tab, t_champ *cmp)
{
	int		i;
	char	*end;

	i = 1;
	if ((end = ft_strchr(tab[0], ':')))
	{
		ft_add_label(cmp, ft_strsub(tab[0], 0, end - tab[0]));
		if (!tab[0][(int)end - (int)tab[0] + 1])
		{
			tab[0][0] = 0;
			while (tab[i])
			{
				tab[i - 1] = tab[i];
				tab[i] = 0;
				i++;
			}
		}
		else
			tab[0] = ft_strtrim(end + 1);
	}
	return (tab);
}

void		get_inst(int i, char **tmp, t_champ *cmp)
{
	cmp->bin[cmp->pos] = (char)g_op_tab[i].opcode;
	cmp->inst_pos = cmp->pos;
	cmp->pos++;
	tmp++;
}

int			ret_type(char *str)
{
	if (str[0] == DIRECT_CHAR)
		return (T_DIR);
	else if (str[0] == 'r')
		return (T_REG);
	return (T_IND);
}

void			get_dir(t_champ *c, char *str, int i)
{
	union u_4o	dir;
	int			k;

	k = 3;
	if (g_op_tab[i].index)
		k = 1;
	if (str[0] == LABEL_CHAR)
	{
		ft_add_miss(c, str + 1, k + 1);
		c->pos = c->pos + k + 1;
	}
	else
	{
		dir.i = ft_atoi(str);
		while (k >= 0)
		{
			c->bin[c->pos] = dir.c[k];
			k--;
			c->pos++;
		}
	}
}

void			get_reg(t_champ *c, char *str)
{
	int			reg;

	reg = ft_atoi(str);
	if (reg <= 0 || reg > 16)
		ft_error("Reg does not exist.");
	c->bin[c->pos] = (char)reg;
	c->pos++;
}

void			get_ind(t_champ *c, char *str)
{
	union u_2o	ind;
	int			i;
	int			prov;

	if (str[0] == LABEL_CHAR)
	{
		ft_add_miss(c, str + 1, 2);
		c->pos = c->pos + IND_SIZE;
	}
	else
	{
		prov = ft_atoi(str);
		ind.i = (short int)(prov);
		i = 0;
		while (i < IND_SIZE)
		{
			c->bin[c->pos] = ind.c[IND_SIZE - i - 1];
			i++;
			c->pos++;
		}
	}
}

void		get_attr(int i, char **tab, t_champ *c)
{
	int		j;
	int		ret;

	j = 1;
	while (tab[j])
	{
		ret = ret_type(tab[j]);
		if (ret == T_DIR)
			get_dir(c, tab[j] + 1, i);
		else if (ret == T_IND)
			get_ind(c, tab[j]);
		else if (ret == T_REG)
			get_reg(c, tab[j] + 1);
		j++;
	}
}

void		op_types_read(int i, char **tab, t_champ *c)
{
	int		j;
	int		ret;
	char	ocp;

	ocp = 0;
	j = 1;
	get_inst(i, tab, c);
	while (tab[j])
	{
		ret = ret_type(tab[j]);
		if (!(g_op_tab[i].att[j - 1] & ret))
			ft_error("Wrong attribute type.");
		ocp = (ret == T_IND) ? (ocp | (3 << (8 - j * 2))) :
			(ocp | ((char)ret << (8 - j * 2)));
		j++;
	}
	if (g_op_tab[i].carry)
	{
		c->bin[c->pos] = ocp;
		c->pos++;
	}
	get_attr(i, tab, c);
}

void		find_instr(t_champ *c, char *tmp)
{
	char	**tab;
	int		i;
	size_t	len;

	tab = ft_strsplit(ft_strreplace_char(tmp, 9, ' '), ' ');
	len = ft_strlen(tab[0]);
	i = 0;
	tab = ft_get_lbl(tab, c);
	while (i < 16 && ft_strncmp(g_op_tab[i].name, tab[0], len))
		i++;
	if (i < 16)
		op_types_read(i, tab, c);
}

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
	i = 0;
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
		while (*line)
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
		ft_error("Open failed.");
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
				find_instr(c, tmp);
		}
	}
}
