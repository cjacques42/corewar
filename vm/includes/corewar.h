/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:35:32 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/19 19:30:21 by jcornill         ###   ########.fr       */
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
**	init_player_utils.c
*/

void				create_player(t_player *player, char *line, int i, int fd);
void				check_magic(t_player *player, int i);

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
**	args2.c
*/

void				verbose(int *nb_args, int *i);
void				hide(int *nb_args, int *i, char *str);

/*
**	utils.c
*/

int					check_reg(int p);
char				check_type(int ocp, int p_place);
int					check_ocp(int ocp, int n_param, int *adv,
					t_processes *current);
int					get_val_from_addr(int p, char mod, t_processes *current);
void				write_val(int pc, int nbr, int player_id);

/*
**	utils2.c
*/

unsigned char		get_vm_value(int *adv, int add, int pc);
int					char_to_nbr(int *adv, const int len, int pc);
int					test_ocp(t_op *op, int ocp);
int					check_all_reg(int ocp, int p[4]);
void				debug_op(t_processes *current, int adv);

/*
**	utils3.c
*/

int					change_carry(int val);
void				lstiter(t_list *lst, t_list *(*f)(t_list *elem));

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
void				setup_print_data(int j);
/*
**	Global variable
*/

t_data				*g_data;

#endif
