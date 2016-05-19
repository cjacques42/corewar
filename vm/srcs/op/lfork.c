/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:13:32 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:57:17 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lfork(t_processes *current)
{
	int		addr;
	int		adv;
	int		paff;

	adv = 0;
	addr = (int)(short)char_to_nbr(&adv, 2, current->pc);
	addr += current->pc;
	paff = addr;
	addr %= MEM_SIZE;
	ft_lstadd(&g_data->processes,
	ft_lstnew(create_process(addr, current, NULL, 0),
	sizeof(t_processes)));
	if (g_data->arg & 4 && !g_data->ncurse)
		ft_printf("P%5d | lfork %d (%d)\n",
		current->id + 1, paff - current->pc, paff);
	debug_op(current, adv);
}
