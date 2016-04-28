/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:03:13 by djoly             #+#    #+#             */
/*   Updated: 2016/04/28 17:08:08 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../../libft/libft.h"
# include "op.h"
# include "process.h"
# include "reverse_octet.h"
# include "player.h"
# include "ir.h"
# include "vm_init.h"
# include <stdio.h>

void print(void);


typedef struct s_cpu	t_cpu;
struct s_cpu
{
	//int		ir; //instruction registre
	int		current_cycle; // cycle en cours
	int		cycle2die; // cylcle to die a decrementer
						//	tout les CYCLE_DELTA OU MAX_CHECKS
						//
};

typedef struct s_octet	t_octet;
struct s_octet
{
	int		plyr; // numero du dernier player a ecrire
	int		pc; // bool, pc sur loctet ou non
};

typedef struct s_base_core	t_base_core;
struct s_base_core
{
	char	core[MEM_SIZE];
	t_octet data[MEM_SIZE];
};

typedef struct s_vm	t_vm;
struct s_vm
{
	t_cpu			cpu;
	t_base_process	proc;
	t_base_core		core;
	t_base_player	plyr;
	int				last_live; // numero du dernier player qui a dit LIVE

};


/*
typedef struct s_octet	t_octet;
struct s_octet
{
	char	val;
	int		plyr; // numero du player
	int		pc; // bool
};

typedef struct s_base_core	t_base_core;
struct s_base_core
{
	t_octet	core[MEM_SIZE];
};
*/
#endif
