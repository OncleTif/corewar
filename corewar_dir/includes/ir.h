/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ir.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:59:35 by djoly             #+#    #+#             */
/*   Updated: 2016/05/26 15:36:55 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IR_H
# define IR_H
# include "corewar.h"

struct	s_ir
{
	unsigned char	irstr[14];
	unsigned char	opcode;
	int				ocp;
	int				index;
	int				nb_arg;
	int				types_args[3];
	int				code_args[3];
	int				args[3];
};

#endif
