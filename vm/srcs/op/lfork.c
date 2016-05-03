/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:13:32 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/02 15:00:52 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lfork(t_processes *current)
{
	int		addr;

	addr = ft_char_to_short(&g_data->vm[current->pc + 1]);
	if (addr >= MEM_SIZE)
		addr -= MEM_SIZE;
	else if (addr < 0)
		addr += MEM_SIZE;
	ft_lstadd(&g_data->processes,
	ft_lstnew(create_process(addr, current, NULL, 0),
	sizeof(t_processes)));
	current->pc += 3;
}
