/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:50:01 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/19 17:48:49 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_player(t_player *player, char *line, int i, int fd)
{
	player->raw = (unsigned char*)line;
	player->id = -(g_data->n[i]);
	player->pos = i + 1;
	if (close(fd) == -1)
		err_exit("error when close player file");
}

void	check_magic(t_player *player, int i)
{
	if (i == 0)
	{
		if (player->raw[i] == ((COREWAR_EXEC_MAGIC >> 24) & 255) &&
			player->raw[i + 1] == ((COREWAR_EXEC_MAGIC >> 16) & 255) &&
			player->raw[i + 2] == ((COREWAR_EXEC_MAGIC >> 8) & 255) &&
			player->raw[i + 3] == (COREWAR_EXEC_MAGIC & 255))
			return ;
		else
			err_exit("Wrong player file");
	}
}
