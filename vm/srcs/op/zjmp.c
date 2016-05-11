/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:16 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/11 15:52:58 by jcornill         ###   ########.fr       */
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
		current->pc %= MEM_SIZE;
		//printf("currentpc == %x\n", current->pc);
//		printf("P%5d | zjmp %d OK\n", current->id + 1, addr);
//		printf("zjmp %d\n", addr);
	}
	else
	{
		current->pc += 3;
		current->pc %= MEM_SIZE;
//		printf("zjmp %d failed\n", addr);
//		printf("(%#06x -> %#06x)\n", current->pc - 3, current->pc);
	}
}
