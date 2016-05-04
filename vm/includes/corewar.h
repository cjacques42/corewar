/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:35:32 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/03 18:58:02 by stoussay         ###   ########.fr       */
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

void	store_args(int nb_args, char **args);

/*
**	ncurse_manager.c
*/

void				create_ncurse(void);
void				update_print_vm(void);

/*
**	Global variable
*/

t_data				*g_data;

#endif
