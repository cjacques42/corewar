/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:07:49 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:55:37 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	player_exist(int param)
{
	int		i;
	int		result;

	i = -1;
	result = 0;
	while (++i < g_data->nb_player)
	{
		if (param == g_data->n[i])
			return (i);
	}
	return (-1);
}

void		live(t_processes *current)
{
	int			param;
	int			adv;
	t_player	player;
	int			n_player;

	adv = 0;
	param = (int)char_to_nbr(&adv, 4, current->pc);
	current->cycle_live = 0;
	g_data->t_live++;
	if ((n_player = player_exist(-param)) != -1)
	{
		player = g_data->players[n_player];
		g_data->last_live = player;
		if (!(g_data->arg & 8) && !g_data->ncurse)
			ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
		-player.id, player.name);
	}
	if (g_data->arg & 4 && !g_data->ncurse)
		ft_printf("P%5d | live %d\n", current->id + 1, (int)param);
	debug_op(current, adv);
}
