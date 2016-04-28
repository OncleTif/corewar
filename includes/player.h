/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:31:38 by djoly             #+#    #+#             */
/*   Updated: 2016/04/28 13:35:42 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_player	t_player;
struct s_player
{
	int		num_plyr;
	char	name[PROG_NAME_LENGTH];
	char	comment[COMMENT_LENGTH];
	char	program[CHAMP_MAX_SIZE];
}
