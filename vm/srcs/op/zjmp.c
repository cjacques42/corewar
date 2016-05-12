/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:16 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/12 17:34:27 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_processes *current)
{
	short		addr;
	int			debug;

	addr = ft_char_to_short(&g_data->vm[current->pc + 1]);
	if (current->carry == 1)
	{
		current->pc += addr;
		while (current->pc >= MEM_SIZE)
			current->pc -= MEM_SIZE;
		while (current->pc < 0)
			current->pc += MEM_SIZE;
//		printf("P%5d | zjmp %d OK\n", current->id + 1, addr);
	}
	else
	{
		current->pc += 3;
		current->pc %= MEM_SIZE;
//		printf("P%5d | zjmp %d FAILED\n", current->id + 1, addr);
//		printf("ADV 3 (%#06x -> %#06x) ", current->pc - 3, current->pc);
		debug = 3;
		while (debug)
		{
//			printf("%02x ", g_data->vm[current->pc - debug]);
			debug--;
		}
//		printf("\n");
	}
}
