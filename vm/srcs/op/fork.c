/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:50:45 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/13 14:21:33 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_processes *current)
{
	int		addr;

	addr = ft_char_to_short(&g_data->vm[current->pc + 1]);
	addr %= IDX_MOD;
	addr += current->pc;
	addr %= MEM_SIZE;
	while (addr < 0)
		addr += MEM_SIZE;
	ft_lstadd(&g_data->processes,
	ft_lstnew(create_process(addr, current, NULL, 0),
	sizeof(t_processes)));
	if (g_data->arg & 4)
		ft_printf("P%5d | fork %d\n", current->id + 1, addr);
	debug_op(current, current->pc + 2, 3);
}
