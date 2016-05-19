/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:06:14 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/18 18:03:12 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		copy_tab(int in[16], int out[16])
{
	int		i;

	i = 0;
	while (i < 16)
	{
		out[i] = in[i];
		i++;
	}
}

t_processes		*create_process(int pc, t_processes *parent, t_op *op, int pid)
{
	t_processes		*result;

	if (!(result = (t_processes *)ft_memalloc(sizeof(t_processes))))
		err_exit("malloc error");
	result->pc = pc;
	result->op = op;
	if (((result->print = 0) == 0) && parent != NULL)
	{
		result->carry = parent->carry;
		result->player_id = parent->player_id;
		copy_tab(parent->reg, result->reg);
		result->cycle_live = parent->cycle_live;
	}
	else
	{
		result->player_id = pid;
		result->carry = 0;
		result->reg[0] = result->player_id;
		result->cycle_live = 0;
	}
	result->cycle_left = 0;
	result->id = g_data->id_processes;
	g_data->nb_processes++;
	g_data->id_processes++;
	return (result);
}
