/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:35:32 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/16 10:58:52 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "opfct.h"
# include <fcntl.h>
# include <unistd.h>
# include <ncurses.h>

/*
**	corewar.c
*/

void				err_exit(char *comment);
void				usage(void);

/*
**	game.c
*/

void				game(void);

/*
**	init_player.c
*/

void				init_player(int nb_player, char **players);

/*
**	processes_manager.c
*/

t_processes			*create_process(int pc,
					t_processes *parent, t_op *op, int pid);

/*
**	op_parser.c
*/

t_op				*parse_op(int addr);
void				exe_op(t_op *op, t_processes *proc);

/*
**	debug.c
*/

void				print(void);

/*
**	args.c
*/

void				store_args(int *nb_args, char **args);

/*
**	utils2.c
*/

int					change_carry(int val);
unsigned char		get_vm_value(int *place, int add);
int					char_to_nbr(int *place, const int len);

/*
**	ncurse_manager.c
*/

void				create_ncurse(int enabled);
void				ncur_print_char(int cursor, int font, int move);

/*
**	ncurse_printing.c
*/

void				ncur_print_data(int cycles);
void				ncur_init_color(void);

/*
**	Global variable
*/

t_data				*g_data;

#endif
