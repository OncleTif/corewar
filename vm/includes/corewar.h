/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:03:13 by djoly             #+#    #+#             */
/*   Updated: 2016/05/01 18:11:43 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../../libft/libft.h"
# include "struct_types.h"
# include "op.h"
# include "process.h"
# include "reverse_octet.h"
# include "player.h"
# include "ir.h"
# include "vm_init.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BPLR vm->bplr

void print(void);

struct s_cpu
{
	//int		ir; //instruction registre
	int		current_cycle; // cycle en cours
	int		cycle2die; // cylcle to die a decrementer
						//	tout les CYCLE_DELTA OU MAX_CHECKS
						//
};

struct s_octet
{
	int		plyr; // numero du dernier player a ecrire
	int		pc; // bool, pc sur loctet ou non
};

struct s_base_core
{
	unsigned char	core[MEM_SIZE];
	t_octet data[MEM_SIZE];
};

struct s_vm
{
	int				dump; //  -dump aff et exit apres nbr cycles
	int				verbose; //  -v affiche les action
	t_cpu			cpu;
	t_base_process	proc;
	t_base_core		bcore;
	t_base_player	bplr;
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

/*
	ft_init_arena
*/
int		ft_init_arena(t_vm *vm);

/*
	ft_check_champion.c
*/

void	ft_open_champion(char *line, t_bin *plr);

/*
	ft_stock_champion.c
*/

void	ft_stock_program(int fd, t_bin *plr);
void	ft_stock_comment(int fd, t_bin *plr);
void	ft_stock_prog_size(int fd, char *buff, t_bin *plr);
void	ft_stock_name(int fd, t_bin *plr);
void	ft_stock_magic(int fd, char *buff, t_bin *plr);

/*
	ft_handle.c
*/

void	ft_handle_args(int ac, char **av, t_vm *vm);
int		ft_check_args(char *av);
void	ft_handle_bonus(char **av, int *i, t_vm *vm);
void	ft_mem_champs(t_base_player *player, char *av);

/*
	ft_memrev.c
*/

void	memrev(char  *buf, size_t count);

/*
ft_print_champion.c
*/

void print_prog(t_bin plr);
void print_magic(t_bin plr, char *buff);
void print_prog_name(t_bin plr);
void print_prog_size(t_bin plr, char *buff);
void print_comment(t_bin plr);

#endif
