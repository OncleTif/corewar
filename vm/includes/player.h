/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:31:38 by djoly             #+#    #+#             */
/*   Updated: 2016/05/01 16:33:34 by eozdek           ###   ########.fr       */
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
struct      s_bin
{
	int		num_plyr; // la VM ou -n attribut un numero au joueur
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		program[CHAMP_MAX_SIZE + 1];
};

struct s_list_player
{

	t_bin			*plr;
	t_list_player	*next;
};

struct s_base_player
{
	int				tmpnum;	// stock le numero du plr qui a etait modifier
	int				i_plr;//tmp
	unsigned int 	tab[4]; // stock les num des champs par defaut
								// peut etre modif par -n ***
	int				nb_plyr; //nombre de player
	t_list_player	*lst_plyr;
};

#endif
