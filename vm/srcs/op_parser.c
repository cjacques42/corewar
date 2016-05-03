/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:13:59 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/27 15:43:38 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	exe_op(t_op *op, t_processes *proc)
{
	if (op->opcode == 1)
		live(proc);
	else if (op->opcode == 2)
		ld(proc);
	else if (op->opcode == 3)
		st(proc);
	else if (op->opcode == 4)
		add(proc);
	else if (op->opcode == 5)
		sub(proc);
	else if (op->opcode == 6)
		and(proc);
	else if (op->opcode == 7)
		or(proc);
	else if (op->opcode == 8)
		xor(proc);
	else if (op->opcode == 9)
		zjmp(proc);
	else if (op->opcode == 10)
		ldi(proc);
	else if (op->opcode == 11)
		sti(proc);
	else if (op->opcode == 12)
		op_fork(proc);
	else if (op->opcode == 13)
		lld(proc);
	else if (op->opcode == 14)
		lldi(proc);
	else if (op->opcode == 15)
		lfork(proc);
	else if (op->opcode == 16)
		aff(proc);
}

t_op	*parse_op(int addr)
{
	t_op	*result;

	if (g_data->vm[addr] > 0 && g_data->vm[addr] < 17)
		result = &g_op_tab[g_data->vm[addr] - 1];
	else
		return (NULL);
	return (result);
}
