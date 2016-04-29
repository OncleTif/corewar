/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:08:32 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/29 11:28:37 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_label		t_label;
typedef struct s_instr		t_instr;
typedef struct s_champ		t_champ;

struct						s_label
{
	char					*name;
	int						pos;
	int						inst_pos;
};

struct						s_champ
{
	char					*file_n;
	char					name[PROG_NAME_LENGTH];
	char					comment[COMMENT_LENGTH];
	char					bin[CHAMP_MAX_SIZE];
	int						pos;
	int						inst_pos;
	t_list					*labels;
	t_list					*miss;
	int						fd;
	t_instr					*instr[17];
};

struct						s_instr
{
char						*name;
unsigned char				opcode;
unsigned char				*tab;
};

/*
** get_s_file.c
*/
void	read_s_file(t_champ *chp, char *str);
int		check_str(t_champ *chp);
/*
** ft_print_champ.c
*/
void	ft_print_champ(t_champ *chp);
void	ft_print_magic(int fd);
void	ft_print_name(t_champ *chp, int fd);
void	ft_print_bin_size(t_champ *chp, int fd);
void	ft_print_comment(t_champ *chp, int fd);
void	ft_print_bin(t_champ *chp, int fd);
/*
** structure.c
*/
void	init_structure(t_champ *chp);
#endif
