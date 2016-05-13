/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opfct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:58:06 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/13 13:16:20 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPFCT_H
# define OPFCT_H
# include "struct.h"

int		check_reg(int p);
char	check_type(int ocp, int p_place);
int		check_ocp(int ocp, int place_p, int *place, char dir);
int		get_val_from_addr(int p, char mod, t_processes *current);
void	add(t_processes *current);
void	aff(t_processes *current);
void	and(t_processes *current);
void	ld(t_processes *current);
void	ldi(t_processes *current);
void	lfork(t_processes *current);
void	live(t_processes *current);
void	lld(t_processes *current);
void	lldi(t_processes *current);
void	op_fork(t_processes *current);
void	or(t_processes *current);
void	st(t_processes *current);
void	sti(t_processes *current);
void	sub(t_processes *current);
void	xor(t_processes *current);
void	zjmp(t_processes *current);
void	write_val(int pc, int nbr, int player_id);
void	debug_op(t_processes *current, int place, int adv);

#endif
