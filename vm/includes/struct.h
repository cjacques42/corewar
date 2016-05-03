/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 14:57:46 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/02 17:22:45 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../../utils/op.h"
# include "../../libft/includes/libft.h"

typedef struct		s_player
{
	unsigned int	id;
	char			*name;
	char			*comment;
	unsigned char	*raw;
	int				size;
}					t_player;

typedef struct		s_data
{
	t_player		players[MAX_PLAYERS];
	t_list			*processes;
	int				nb_player;
	int				nb_processes;
	int				cycle_die;
	int				check_left;
	char			inc;
	unsigned char	vm[MEM_SIZE];
	unsigned short	vm_color[MEM_SIZE];
	t_player		last_live;
}					t_data;

typedef struct		s_processes
{
	int				id;
	int				pc;
	int				player_id;
	t_op			*op;
	int				carry;
	int				reg[REG_NUMBER];
	char			live;
	int				cycle_left;
}					t_processes;

#endif
