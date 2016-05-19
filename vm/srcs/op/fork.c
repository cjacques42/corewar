/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:50:45 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/19 16:56:37 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_processes *current)
{
	int		addr;
	int		adv;

	adv = 0;
	addr = (int)(short)char_to_nbr(&adv, 2, current->pc);
	addr %= IDX_MOD;
	addr += current->pc;
	addr %= MEM_SIZE;
	while (addr < 0)
		addr += MEM_SIZE;
	ft_lstadd(&g_data->processes,
	ft_lstnew(create_process(addr, current, NULL, 0),
	sizeof(t_processes)));
	if (g_data->arg & 4 && !g_data->ncurse)
		ft_printf("P%5d | fork %d (%d)\n", current->id + 1,
		addr - current->pc, addr);
	debug_op(current, adv);
}
