/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:31:38 by djoly             #+#    #+#             */
/*   Updated: 2016/05/01 11:38:10 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "corewar.h"
/*
typedef struct s_player	t_player;
struct s_player
{
	int		num_plyr;
	char	name[PROG_NAME_LENGTH];
	char	comment[COMMENT_LENGTH];
	char	program[CHAMP_MAX_SIZE];
};
*/
typedef struct      s_bin
{
	int		num_plyr; // la VM ou -n attribut un numero au joueur
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		program[CHAMP_MAX_SIZE + 1];
}                   t_bin;

typedef struct s_list_player	t_list_player;
struct s_list_player
{

	t_bin			*plr;
	t_list_player	*next;
};

typedef struct s_base_player	t_base_player;
struct s_base_player
{
	int		i_plr;
	int 			tab_num[4]; // stock les num des champs par defaut
								// peut etre modif par -n ***
	int				nb_plyr; //nombre de player
	t_list_player	*lst_plyr;
};

#endif
