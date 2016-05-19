/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:16 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:59:21 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_processes *current)
{
	int		addr;
	int		adv;
	int		paff;

	adv = 0;
	addr = (int)(short)char_to_nbr(&adv, 2, current->pc);
	paff = addr;
	addr %= IDX_MOD;
	if (current->carry == 1)
	{
		current->pc += addr;
		current->pc %= MEM_SIZE;
		while (current->pc < 0)
			current->pc += MEM_SIZE;
		if (g_data->arg & 4 && !g_data->ncurse)
			ft_printf("P%5d | zjmp %d OK\n", current->id + 1, paff);
	}
	else
	{
		if (g_data->arg & 4 && !g_data->ncurse)
			ft_printf("P%5d | zjmp %d FAILED\n", current->id + 1, paff);
		debug_op(current, adv);
	}
}
