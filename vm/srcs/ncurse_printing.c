/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:28:09 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/12 15:58:22 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_data(void)
{
	move(2, 222);
	printw("%-8d", g_data->nb_processes);
	move(3, 222);
	printw("%-5d", g_data->cycle_die);
	move(4, 222);
	printw("%-2d", g_data->check_left);
	move(5, 222);
	printw("%-5d", g_data->cycle_seconds);
}

static void		check_input(void)
{
	char	c;

	c = getch();
	if (c == ' ')
		g_data->pause = 1;
	if (c == '+')
		g_data->cycle_seconds++;
	if (c == '-')
		g_data->cycle_seconds--;
	print_data();
}

void			ncur_init_color(void)
{
	start_color();
	init_color(COLOR_MAGENTA, 850, 850, 850);
	init_color(COLOR_WHITE, 300, 300, 300);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_BLUE, 0, 0, 1000);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
}

void			ncur_print_data(int cycles)
{
	if (g_data->ncurse == 1)
	{
		timeout(1000 / g_data->cycle_seconds);
		move(0, 200);
		check_input();
		while (g_data->pause == 1)
		{
			if (getch() == 'p')
				g_data->pause = 0;
			check_input();
			move(0, 200);
		}
		move(1, 222);
		printw("%-d", cycles);
		print_data();
	}
}
