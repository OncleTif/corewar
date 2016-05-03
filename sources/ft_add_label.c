/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:38:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/03 12:12:37 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../vm/includes/reverse_octet.h"

void	ft_fill_lbl(t_label *miss, t_label *lbl, t_champ *chp)
{
	union u_4o	u;
	int			i;

	i = 0;
	u.i = miss->inst_pos - lbl->pos;
	while (i < miss->att_type)
	{
		chp->bin[miss->pos + miss->att_type - i - 1] = u.c[i];
		i++;
	}
}

void	ft_find_labels(t_champ *chp)
{
	t_list	*elem_miss;
	t_list	*elem;

	ft_putendl("find lbl");
	elem_miss = chp->miss;
	while (elem_miss)
	{
	ft_putendl("find miss");
		elem = chp->labels;
	ft_putstr((*(t_label**)elem->content)->name);
	ft_putendl("*");
		while (elem && !(ft_strequ((*(t_label**)elem->content)->name, (*(t_label**)elem_miss->content)->name)))
		{
	ft_putendl("test");
	ft_putendl((*(t_label**)elem->content)->name);
			elem = elem->next;
		}
		if (!elem)
		{
	ft_putendl((*(t_label**)elem_miss->content)->name);
			ft_error("missing label");

		}
	ft_putendl("found miss");
		ft_fill_lbl((*(t_label**)elem_miss->content), (*(t_label**)elem->content), chp);
		elem_miss = elem_miss->next;
	}
}

void	ft_add_miss(t_champ *chp, char *lbl, int i)
{
	t_label	*label;

	label = (t_label*)ft_memalloc(sizeof(t_label));
	label->name = ft_strreplace_char(lbl, ',', 0);
	label->pos = chp->pos;
	label->inst_pos = chp->inst_pos;
	label->att_type = i;
	ft_lstadd(&chp->miss, ft_lstnew(&label, sizeof(t_label*)));
}

void		check_lbl(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL)
			ft_error("Label syntax is wrong.");
		i++;
	}
}

void	ft_add_label(t_champ *chp, char *lbl)
{
	t_list	*elem;
	t_label	*label;

	check_lbl(lbl);
	elem = chp->labels;
	while (elem)
	{
		if (ft_strequ((*(t_label**)elem->content)->name, lbl))
			ft_error("duplicate label");
		elem = elem->next;
	}
	label = (t_label*)ft_memalloc(sizeof(t_label));
	label->name = lbl;
	label->pos = chp->pos;
	label->inst_pos = chp->pos;
	ft_lstadd(&chp->labels, ft_lstnew(&label, sizeof(t_label*)));
}
