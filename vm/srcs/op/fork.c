/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:50:45 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/12 17:34:27 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_processes *current)
{
	int		addr;
	int		debug;

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
//	printf("P%5d | fork %d\n", current->id + 1, addr);
//	printf("fork %d\n", addr);
	current->pc += 3;
	current->pc %= MEM_SIZE;
//	printf("(%#06x -> %#06x) ", current->pc - 3, current->pc);
	debug = 3;
	while (debug)
	{
//		printf("%02x ", g_data->vm[current->pc - debug]);
		debug--;
	}
//	printf("\n");
}
