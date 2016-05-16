/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:16 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/16 15:26:06 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_processes *current)
{
	int		addr;
	int		place;
	int		paff;

	place = current->pc;
	addr = (int)(short)char_to_nbr(&place, 2);
	paff = addr;
	addr %= IDX_MOD;
	if (current->carry == 1)
	{
		current->pc += addr;
		current->pc %= MEM_SIZE;
		while (current->pc < 0)
			current->pc += MEM_SIZE;
		if (g_data->arg & 4)
			ft_printf("P%5d | zjmp %d OK\n", current->id + 1, paff);
	}
	else
	{
		current->pc = place;
		if (g_data->arg & 4)
			ft_printf("P%5d | zjmp %d FAILED\n", current->id + 1, addr);
		debug_op(current, current->pc + 2, 3);
	}
}
