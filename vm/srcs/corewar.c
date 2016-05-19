/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:34:59 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/18 17:34:12 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_winner(void)
{
	t_player	winner;

	winner = g_data->last_live;
	ft_printf("Le joueur %d(%s) a gagne\n", -winner.id, winner.name);
}

void			err_exit(char *comment)
{
	ft_putstr("Error : ");
	ft_putstr(comment);
	ft_putstr(" !\n");
	exit(1);
}

void			usage(void)
{
	ft_putstr("Usage: ./corewar [-dump N -n N -v -nc -ha -hl] ");
	ft_putendl("<champion1.cor> <...>");
	ft_putstr("#### TEXT OUTPUT MODE#########################################");
	ft_putstr("#################\n-dump N      : Dumps memory after N cycles ");
	ft_putstr("then exits\n-v           : Show cycles, operations, deaths and");
	ft_putstr(" PC movements (Except for jumps)\n-nc          : Ncurses ");
	ft_putstr("output mode\n-n N         : Put N as the id of the next ");
	ft_putstr("player\n-ha          : Hides output from \"aff\"\n");
	ft_putstr("-hl          : Hides output from \"live\"\n###################");
	ft_putendl("#############################################################");
	exit(1);
}

int				main(int ac, char **av)
{
	if (ac == 1)
		usage();
	if (!(g_data = (t_data *)ft_memalloc(sizeof(t_data))))
		err_exit("malloc error");
	g_data->pause = 0;
	g_data->ncurse = 0;
	g_data->cycle_seconds = 200;
	init_player(ac - 1, av);
	g_data->last_live = g_data->players[0];
	create_ncurse(g_data->ncurse);
	game();
	if (g_data->arg & 1 && g_data->nb_processes != 0)
		print();
	else
		print_winner();
	if (g_data->ncurse)
	{
		timeout(-1);
		getch();
		endwin();
	}
	return (0);
}
