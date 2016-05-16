/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:44:26 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/16 14:26:40 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_processes *current)
{
	int			param;
	int			place;
	t_player	player;

	place = current->pc;
	param = (int)char_to_nbr(&place, 4);
	if (param != 0)
	{
		current->cycle_live = 0;
		g_data->t_live++;
	}
	if (-param > 0 && -param <= g_data->nb_player)
	{
		player = g_data->players[-param - 1];
		g_data->last_live = player;
	//	printf("un processus dit que le joueur %d(%s) est en vie %d\n", player.id, player.name, current->live);
	}
	current->pc = place;
	if (g_data->arg & 4)
		ft_printf("P%5d | live %d\n", current->id + 1, (int)param);
	debug_op(current, current->pc, 5);
}
