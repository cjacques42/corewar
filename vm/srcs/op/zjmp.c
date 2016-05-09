/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:16 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/09 18:32:16 by stoussay         ###   ########.fr       */
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
		//printf("currentpc == %x\n", current->pc);
//		printf("zjmp %d\n", addr);
	}
	else
	{
		current->pc += 3;
//		printf("zjmp %d failed\n", addr);
	}
}
