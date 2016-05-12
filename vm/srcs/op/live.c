/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:44:26 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/12 17:34:27 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_processes *current)
{
	int			param;
	int			debug;
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
//	if (g_data->arg >> 2 & 1 && g_data->verbose & 4)
//	printf("P%5d | live %d\n", current->id + 1, param);
	current->pc += 5;
	current->pc %= MEM_SIZE;
//	printf("ADV 5 (%#06x -> %#06x) ", current->pc - 5, current->pc);
	debug = 5;
	while (debug)
	{
//		printf("%02x ", g_data->vm[current->pc - debug]);
		debug--;
	}
//	printf("\n");
}
