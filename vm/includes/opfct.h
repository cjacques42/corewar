/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opfct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:58:06 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/17 18:12:21 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPFCT_H
# define OPFCT_H
# include "struct.h"

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

#endif
