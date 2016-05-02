/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:26:12 by djoly             #+#    #+#             */
/*   Updated: 2016/05/01 19:17:55 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "corewar.h"
# include "ir.h"

struct s_process
{
	int		num;  // numero du processus

	int		num_plr; // num du plyr ou
//	t_bin		*plr; // pointeur sur son player, num du plr dedans
	int		cycle_to_wait;
	int		pc;
	int		reg[16];
	int		carry;
	t_ir	ir;
};

struct s_list_process
{
	t_process	proc;
	t_list_process *next;	//
};

struct s_base_process
{
	int		nb_proc;
	t_list_process	*lst_proc; // liste des processs
};
#endif
