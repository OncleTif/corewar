/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:03:13 by djoly             #+#    #+#             */
/*   Updated: 2016/04/27 17:16:26 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

typedef struct s_process	t_process;
struct s_process
{
	int		pc;
	int		registre[16];
	int		carry;
	int		num_process;
};


typedef struct s_list_process	t_list_process;
struct s_list_process
{
	t_process	*process;
	t_list_process *next;
};

typedef struct s_base_process	t_base_process;
struct s_base_process
{
	int		nb_process;
	t_list_process 	*beg_list;
};


