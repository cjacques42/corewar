/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:52:49 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/19 18:56:13 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		load_player(t_player *player)
{
	int		i;
	int		player_pos;
	int		j;

	player_pos = MEM_SIZE / (g_data->nb_player) * ((player->pos) - 1);
	i = player_pos;
	j = 0;
	while (i < player->size + player_pos)
	{
		g_data->vm[i] = player->raw[j];
		g_data->vm_color[i] = -player->id;
		i++;
		j++;
	}
	ft_lstadd(&g_data->processes,
	ft_lstnew(create_process(player_pos, NULL, NULL, player->id),
	sizeof(t_processes)));
}

static void		malloc_player(t_player *player)
{
	if (!(player->name = (char *)ft_memalloc(PROG_NAME_LENGTH + 1)))
		err_exit("malloc error");
	if (!(player->comment = (char *)ft_memalloc(COMMENT_LENGTH + 1)))
		err_exit("malloc error");
}

static void		setup_player(t_player *player, int r)
{
	int		i;

	i = -1;
	malloc_player(player);
	while (++i < r)
		if (i < 4)
			check_magic(player, i);
		else if (i < 4 + PROG_NAME_LENGTH)
			player->name[i - 4] = player->raw[i];
		else if (i < 4 + PROG_NAME_LENGTH + 8)
			player->size = (i == 4 + PROG_NAME_LENGTH + 4) ?
			ft_char_to_int(&player->raw[i]) : player->size;
		else if (i < 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH)
			player->comment[i - 4 - PROG_NAME_LENGTH - 8] = player->raw[i];
		else if (i < 16 + PROG_NAME_LENGTH + COMMENT_LENGTH)
			i = i + 0;
		else
		{
			player->raw = &player->raw[i];
			break ;
		}
	if (player->size > CHAMP_MAX_SIZE)
		err_exit("One of the players is too heavy to play");
	load_player(player);
}

static void		parse_args(char ***players)
{
	while (**players && (!ft_strcmp(**players, "-dump") ||
	!ft_strcmp(**players, "-n") || !ft_strcmp(**players, "-v") ||
	!ft_strcmp(**players, "-nc") || !ft_strcmp(**players, "-hl") ||
	!ft_strcmp(**players, "-ha")))
	{
		if (**players && !ft_strcmp(**players, "-dump"))
			*players += 2;
		if (**players && !ft_strcmp(**players, "-n"))
			*players += 2;
		if (**players)
			*players += (!ft_strcmp(**players, "-v")) ? 1 : 0;
		if (**players)
			*players += (!ft_strcmp(**players, "-nc")) ? 1 : 0;
		if (**players)
			*players += (!ft_strcmp(**players, "-hl")) ? 1 : 0;
		if (**players)
			*players += (!ft_strcmp(**players, "-ha")) ? 1 : 0;
	}
}

void			init_player(int nb_player, char **players)
{
	int			i;
	int			fd;
	t_player	player;
	char		line[5000];
	int			r;

	i = 0;
	store_args(&nb_player, players);
	g_data->nb_player = nb_player;
	if (nb_player > MAX_PLAYERS)
		err_exit("Too many players");
	while (*(++players))
	{
		parse_args(&players);
		if (!*players)
			break ;
		if ((fd = open(*players, O_RDONLY)) == -1)
			err_exit("Can't read source file");
		if ((r = read(fd, line, 5000)) == -1)
			err_exit("read error");
		create_player(&player, line, i, fd);
		setup_player(&player, r);
		g_data->players[i++] = player;
	}
}
