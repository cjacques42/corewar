/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:16 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/02 14:57:39 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_processes *current)
{
	short		addr;

	addr = ft_char_to_short(&g_data->vm[current->pc + 1]);
	if (current->carry == 1)
		current->pc += addr;
	else
		current->pc += 1;
}
