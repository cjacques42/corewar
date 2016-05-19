/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:13:59 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/18 17:57:17 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	exe_op(t_op *op, t_processes *proc)
{
	void (*op_tab[16])(t_processes *proc);

	op_tab[0] = live;
	op_tab[1] = ld;
	op_tab[2] = st;
	op_tab[3] = add;
	op_tab[4] = sub;
	op_tab[5] = and;
	op_tab[6] = or;
	op_tab[7] = xor;
	op_tab[8] = zjmp;
	op_tab[9] = ldi;
	op_tab[10] = sti;
	op_tab[11] = op_fork;
	op_tab[12] = lld;
	op_tab[13] = lldi;
	op_tab[14] = lfork;
	op_tab[15] = aff;
	if (op->opcode > 0 && op->opcode < 17)
		op_tab[op->opcode - 1](proc);
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
