/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:02:31 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/13 13:51:36 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		check_processes_alive(t_list *elem)
{
	t_processes		*proc;

	proc = (t_processes *)elem->content;
	if (proc->live == 0)
	{
		if (elem->next != NULL)
			elem->next->previous = elem->previous;
		if (elem->previous != NULL)
			elem->previous->next = elem->next;
		else
			g_data->processes = elem->next;
		free(proc);
		proc = 0;
		free(elem);
		elem = 0;
		g_data->nb_processes--;
		return ;
	}
	proc->live = 0;
}

static void		play_processes(t_list *elem)
{
	t_processes		*proc;
	t_op			*new_op;

	proc = (t_processes *)elem->content;
	if (proc->print == 0)
	{
		ncur_print_char(proc->pc, 1, 1);
		proc->print = 1;
	}
	if (proc->op == NULL)
	{
		new_op = parse_op(proc->pc);
		proc->op = new_op;
		if (new_op != NULL)
			proc->cycle_left = proc->op->cycle_cost - 1;
		if (new_op == NULL && (proc->print = 0) == 0)
			proc->pc++;
	}
	else if (--proc->cycle_left == 0)
	{
		ncur_print_char(proc->pc, 0, 1);
		proc->print = 0;
		exe_op(proc->op, proc);
		proc->op = NULL;
	}
}

void			game(void)
{
	int		i;
	int		cycles;

	g_data->cycle_die = CYCLE_TO_DIE;
	g_data->check_left = MAX_CHECKS;
	i = 0;
	cycles = i;
	while (++i < 75000)
	{
		ncur_print_data(cycles);
		cycles++;
		if (g_data->arg & 1 && cycles >= g_data->dump)
			return ;
		ft_lstiter(g_data->processes, play_processes);
		if (g_data->cycle_die != 0 && i >= g_data->cycle_die)
		{
			i = 0;
			ft_lstiter(g_data->processes, check_processes_alive);
			if (g_data->nb_processes == 0)
				break ;
			if (g_data->t_live < NBR_LIVE)
				g_data->check_left--;
			if (g_data->check_left == 0 || g_data->t_live >= NBR_LIVE)
			{
				g_data->cycle_die -= CYCLE_DELTA;
				g_data->check_left = MAX_CHECKS;
			}
			g_data->t_live = 0;
		}
	}
}
