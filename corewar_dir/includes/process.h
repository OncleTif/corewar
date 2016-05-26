/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:26:12 by djoly             #+#    #+#             */
/*   Updated: 2016/05/26 15:40:34 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "corewar.h"
# include "ir.h"

struct	s_process
{
	int			num;
	int			num_plr;
	int			cycle_to_wait;
	int			pc;
	int			pcdelta;
	int			reg[17];
	int			carry;
	int			ir_error;
	t_ir		ir;
	t_process	*next;
	int			live;
	int			lst_live;
};
#endif
