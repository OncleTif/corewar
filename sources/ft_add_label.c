/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:38:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/29 17:28:18 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_add_label(t_champ *chp, char *lbl)
{
	t_list	*elem;
	t_label	*label;

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
