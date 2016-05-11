/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:43:04 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/11 18:20:15 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	reset_color(unsigned short color_code)
{
	unsigned char	color;
	unsigned char	ligth;

	color = color_code & 255;
	ligth = color_code >> 8;
	if (color == 1 && ligth == 0)
		attroff(COLOR_PAIR(1));
	else if (color == 1 && ligth == 1)
		attroff(COLOR_PAIR(1) | A_BOLD);
	else if (color == 2 && ligth == 0)
		attroff(COLOR_PAIR(2));
	else if (color == 2 && ligth == 1)
		attroff(COLOR_PAIR(2) | A_BOLD);
	else if (color == 3 && ligth == 0)
		attroff(COLOR_PAIR(3));
	else if (color == 3 && ligth == 1)
		attroff(COLOR_PAIR(3) | A_BOLD);
}

static int	setup_color(unsigned short color_code)
{
	unsigned char	color;
	unsigned char	ligth;

	color = color_code & 255;
	ligth = color_code >> 8;
	if (color == 1 && ligth == 0)
		attron(COLOR_PAIR(1));
	else if (color == 1 && ligth == 1)
		attron(COLOR_PAIR(1) | A_BOLD);
	else if (color == 2 && ligth == 0)
		attron(COLOR_PAIR(2));
	else if (color == 2 && ligth == 1)
		attron(COLOR_PAIR(2) | A_BOLD);
	else if (color == 3 && ligth == 0)
		attron(COLOR_PAIR(3));
	else if (color == 3 && ligth == 1)
		attron(COLOR_PAIR(3) | A_BOLD);
	else
		return(0);
	return (1);
}

void	ncur_print_char(int cursor, int font, int move_to_cursor)
{
	if (move_to_cursor == 1)
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

void	update_print_vm(void)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
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

void	create_ncurse(void)
{
	WINDOW	*boite;

	initscr();
	curs_set(0);
	start_color();
	init_color(COLOR_MAGENTA, 500, 500, 500);
	init_color(COLOR_WHITE, 750, 750, 750);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_BLUE, 0, 0, 1000);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(5));
	boite = subwin(stdscr, 66, 64*3 + 2, 0, 0);
    wborder(boite, '*', '*', '*', '*', '*', '*', '*', '*');
	attroff(COLOR_PAIR(5));
    wrefresh(boite);
	refresh();
	update_print_vm();
}
