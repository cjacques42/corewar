/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:50:45 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/13 19:19:59 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_processes *current)
{
	int		addr;
	int		place;

	place = current->pc;
	addr = (int)(short)char_to_nbr(&place, 2);
	addr %= IDX_MOD;
	addr += current->pc;
	addr %= MEM_SIZE;
	while (addr < 0)
		addr += MEM_SIZE;
	ft_lstadd(&g_data->processes,
	ft_lstnew(create_process(addr, current, NULL, 0),
	sizeof(t_processes)));
	if (g_data->arg & 4)
		ft_printf("P%5d | fork %d (%d)\n", current->id + 1, addr - current->pc,  addr);
	current->pc = place;
	debug_op(current, current->pc, 3);
}
