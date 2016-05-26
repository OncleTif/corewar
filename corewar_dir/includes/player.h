/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:31:38 by djoly             #+#    #+#             */
/*   Updated: 2016/05/26 15:49:46 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "corewar.h"

struct		s_bin
{
	int					pc_tmp;
	int					index_plyr;
	int					num_plyr;
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		program[CHAMP_MAX_SIZE + 1];
	int					last_live;
	int					nbr_live;
	char				*name;
	char				*com;
	int					size;
};

struct		s_list_player
{
	t_bin			*plr;
	t_list_player	*next;
};

struct		s_base_player
{
	int				tmpnum;
	int				i_plr;
	unsigned int	tab[4];
	unsigned int	modif[4];
	int				nb_plyr;
	t_list_player	*lst_plyr;
};

#endif
