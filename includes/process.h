/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:26:12 by djoly             #+#    #+#             */
/*   Updated: 2016/04/28 14:58:46 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "corewar.h"

typedef struct s_process	t_process;
struct s_process
{
	int		num;  // numero du processus
	int		plyr; // num du plyr
	int		pc;
	int		reg[16];
	int		carry;
	t_ir	ir;
};

typedef struct s_list_process	t_list_process;
struct s_list_process
{
	t_process	*proc;
	t_list_process *next;
};

typedef struct s_base_process	t_base_process;
struct s_base_process
{
	int		nb_proc;
	t_list_process	**beg_list; // liste des processs
};
#endif
