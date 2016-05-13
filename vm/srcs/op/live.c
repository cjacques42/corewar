/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:44:26 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/13 14:23:07 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_processes *current)
{
	int			param;
	t_player	player;

	param = ft_char_to_int(&g_data->vm[current->pc + 1]);
	current->live = current->live + 1;
	g_data->t_live++;
	if (-param > 0 && -param <= g_data->nb_player)
	{
		player = g_data->players[-param - 1];
		g_data->last_live = player;
	//	printf("un processus dit que le joueur %d(%s) est en vie %d\n", player.id, player.name, current->live);
	}
	if (g_data->arg & 4)
		ft_printf("P%5d | live %d\n", current->id + 1, param);
	debug_op(current, current->pc + 4, 5);
}
