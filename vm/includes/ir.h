/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ir.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:59:35 by djoly             #+#    #+#             */
/*   Updated: 2016/05/03 15:23:08 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IR_H
# define IR_H
# include	"corewar.h"

struct s_ir
{
	char	ir[14]; // ou char ir[14]  14 octet max
	int		opcode;
	int		ocp;
	int		nb_arg;
	char	types_args[3]; //decalage bin sur ocp pour definir 01 10 11 ou 00
	int		*args[3];
};

#endif
