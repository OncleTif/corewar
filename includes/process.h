/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:26:12 by djoly             #+#    #+#             */
/*   Updated: 2016/04/28 13:31:54 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct s_process	t_process;
struct s_process
{
	int		plyr;
	int		pc;
	int		reg[16];
	int		carry;
	int		num;  // numero du processus
};

typedef struct s_list_process	t_list_process;
struct s_list_process
{
	t_process	*proc;
	t_list_process *next;
};

typedef struct s_base_process	t_base_process;
struct s_base_process
{
	int		nb_proc;
	t_list_process	**beg_list; // liste des processs
};
