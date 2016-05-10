/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:16 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/10 14:46:12 by stoussay         ###   ########.fr       */
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
		printf("zjmp %d\n", addr);
	}
	else
	{
		current->pc += 3;
		current->pc %= MEM_SIZE;
		printf("zjmp %d failed\n", addr);
		printf("(%#06x -> %#06x)\n", current->pc - 3, current->pc);
	}
}
