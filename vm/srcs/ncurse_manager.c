/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:43:04 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/12 18:05:43 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		reset_color(unsigned short color_code)
{
	unsigned char	color;

	color = color_code & 255;
	if (color == 1)
		attroff(COLOR_PAIR(1));
	else if (color == 2)
		attroff(COLOR_PAIR(2));
	else if (color == 3)
		attroff(COLOR_PAIR(3));
	else if (color == 4)
		attroff(COLOR_PAIR(4));
}

static int		setup_color(unsigned short color_code)
{
	unsigned char	color;

	color = color_code & 255;
	if (color == 1)
		attron(COLOR_PAIR(1));
	else if (color == 2)
		attron(COLOR_PAIR(2));
	else if (color == 3)
		attron(COLOR_PAIR(3));
	else if (color == 4)
		attron(COLOR_PAIR(4));
	else
		return (0);
	return (1);
}

void			ncur_print_char(int cursor, int font, int move)
{
	static int	enable = 1;

	enable = (cursor == -1) ? 0 : enable;
	if (enable == 1 && move != -10)
	{
		move(cursor * 3 / (64 * 3) + 1, cursor * 3 % (64 * 3) + 1);
		if (font == 0)
		{
			if (setup_color(g_data->vm_color[cursor]))
			{
				printw("%02x ", g_data->vm[cursor]);
				reset_color(g_data->vm_color[cursor]);
			}
			else
			{
				attron(COLOR_PAIR(6));
				printw("%02x ", g_data->vm[cursor]);
				attroff(COLOR_PAIR(6));
			}
		}
		else
		{
			attron(COLOR_PAIR(7));
			printw("%02x", g_data->vm[cursor]);
			attroff(COLOR_PAIR(7));
		}
		refresh();
	}
}

static void		print_vm(void)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	move(1, 200);
	printw("Cycles :");
	move(2, 200);
	printw("Processes :");
	move(3, 200);
	printw("Cycles die :");
	move(4, 200);
	printw("Check left :");
	move(5, 200);
	printw("Cycles par seconds :");
	move(j, 1);
	while (i < MEM_SIZE)
	{
		if (setup_color(g_data->vm_color[i]))
		{
			printw("%02x ", g_data->vm[i]);
			reset_color(g_data->vm_color[i]);
		}
		else
		{
			attron(COLOR_PAIR(6));
			printw("%02x ", g_data->vm[i]);
			attroff(COLOR_PAIR(6));
		}
		if (i % 64 == 63)
			move(++j, 1);
		i++;
		refresh();
	}
}

void			create_ncurse(int enabled)
{
	WINDOW * boite;
	if (enabled == 1)
	{
		initscr();
		curs_set(0);
		ncur_init_color();
		attron(COLOR_PAIR(5));
		boite = subwin(stdscr, 66, 64 * 3 + 2, 0, 0);
		wborder(boite, '*', '*', '*', '*', '*', '*', '*', '*');
		attroff(COLOR_PAIR(5));
		wrefresh(boite);
		ncur_print_data(0);
		refresh();
		print_vm();
	}
	else
		ncur_print_char(-1, -1, -1);
}
