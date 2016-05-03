/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ir.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:59:35 by djoly             #+#    #+#             */
/*   Updated: 2016/05/03 19:11:04 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IR_H
# define IR_H
# include	"corewar.h"

struct s_ir
{
	unsigned char	irstr[14]; // ou char ir[14]  14 octet max
	unsigned char	opcode;
	int		ocp;
	int		nb_arg;
	int		types_args[3]; //t_reg t_dir t_ind decalage bin sur ocp pour definir 001 010 100 ou 00
	int		code_args[3];
	int		args[3];
};

#endif
