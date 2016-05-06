/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:34:59 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/04 16:30:31 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_winner(void)
{
	t_player	winner;

	winner = g_data->last_live;
	printf("The winner is player %d, %s : %s\n", -winner.id, winner.name, winner.comment);
}

void			err_exit(char *comment)
{
	ft_putstr("Error : ");
	ft_putstr(comment);
	ft_putstr(" !\n");
	exit(1);
}

int				main(int ac, char **av)
{
	if (!(g_data = (t_data *)ft_memalloc(sizeof(t_data))))
		err_exit("malloc error");
	init_player(ac - 1, av);
	g_data->last_live = g_data->players[0];
//	create_ncurse();
	game();
	print();
	print_winner();
//	getch();
//	endwin();
	return (0);
}
