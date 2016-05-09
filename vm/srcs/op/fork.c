/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 21:20:13 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/09 18:32:35 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_processes *current)
{
	int		addr;

//	printf("current->id === %d\n", current->id);
	addr = ft_char_to_short(&g_data->vm[current->pc + 1]);
	addr %= IDX_MOD;
	addr += current->pc;
	addr %= MEM_SIZE;
	while (addr < 0)
		addr += MEM_SIZE;
	ft_lstadd(&g_data->processes,
	ft_lstnew(create_process(addr, current, NULL, 0),
	sizeof(t_processes)));
//	printf("fork %d\n", addr);
	current->pc += 3;
//	printf("(%#06x -> %#06x)\n", current->pc - 3, current->pc);
}
