/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:08:32 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/27 20:17:54 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft/libft.h"
# include "includes/op.h"

typedef struct s_label		t_label;
typedef struct s_champ		t_champ;

struct						s_label
{
	char					*name;
	int						pos;
};

struct						s_champ
{
char						name[PROG_NAME_LENGTH];
char						comment[COMMENT_LENGTH];
int							pos;
};



#endif
