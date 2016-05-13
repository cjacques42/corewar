/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:16 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/13 14:26:20 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_processes *current)
{
	short		addr;

	addr = ft_char_to_short(&g_data->vm[current->pc + 1]);
	if (current->carry == 1)
	{
		current->pc += addr;
		while (current->pc >= MEM_SIZE)
			current->pc -= MEM_SIZE;
		while (current->pc < 0)
			current->pc += MEM_SIZE;
		if (g_data->arg & 4)
			ft_printf("P%5d | zjmp %d OK\n", current->id + 1, addr);
	}
	else
	{
		if (g_data->arg & 4)
			ft_printf("P%5d | zjmp %d FAILED\n", current->id + 1, addr);
		debug_op(current, current->pc + 2, 3);
	}
}
