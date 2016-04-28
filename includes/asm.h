/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:08:32 by tmanet            #+#    #+#             */
/*   Updated: 2016/04/28 15:00:25 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_label		t_label;
typedef struct s_champ		t_champ;

struct						s_label
{
	char					*name;
	int						pos;
};

struct						s_champ
{
	char					*file_n;
	char					name[PROG_NAME_LENGTH];
	char					comment[COMMENT_LENGTH];
	char					bin[CHAMP_MAX_SIZE];
	int						pos;
	t_list					*labels;
	t_list					*miss;
	int						fd;
};

void	read_s_file(t_champ *chp, char *str);
void	ft_print_champ(t_champ *chp);
void	ft_print_magic(int fd);
void	ft_print_name(t_champ *chp, int fd);
void	ft_print_bin_size(t_champ *chp, int fd);
void	ft_print_comment(t_champ *chp, int fd);
void	ft_print_bin(t_champ *chp, int fd);

#endif
