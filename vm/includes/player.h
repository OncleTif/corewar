/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:31:38 by djoly             #+#    #+#             */
/*   Updated: 2016/04/29 14:43:23 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "corewar.h"

typedef struct s_player	t_player;
struct s_player
{
	int		num_plyr;
	char	name[PROG_NAME_LENGTH];
	char	comment[COMMENT_LENGTH];
	char	program[CHAMP_MAX_SIZE];
};

typedef struct      s_bin
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		program[CHAMP_MAX_SIZE + 1];
}                   t_bin;

typedef struct s_list_player	t_list_player;
struct s_list_player
{
	t_bin		*player;
	t_list_player	*next;
};

typedef struct s_base_player	t_base_player;
struct s_base_player
{
	int				nb_plyr; //nombre de player
	t_list_player	**lst_plyr;
};

#endif
