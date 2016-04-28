/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:03:13 by djoly             #+#    #+#             */
/*   Updated: 2016/04/28 13:31:18 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "op.h"
#include "process.h"
#include <stdio.h>

void print(void);


typedef struct s_vm	t_vm;
struct s_vm
{
	t_cpu			cpu;
	t_base_process	proc;
	t_base_core		core;
	int				nb_plyr; //nombre de player
	


};


typedef struct s_cpu	t_cpu;
struct s_cpu
{
	//int		ir; //instruction registre
	int		current_cycle; // cycle en cours

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


typedef struct s_octet	t_octet;
struct s_octet
{
	int		plyr; // numero du player
	int		pc; // bool
};

typedef struct s_base_core	t_base_core;
struct s_base_core
{
	char	core[MEM_SIZE];
	t_octet data[MEM_SIZE];
};
