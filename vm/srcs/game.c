/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:02:31 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/03 19:03:14 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		check_processes_alive(t_list *elem)
{
	t_processes		*proc;
	t_processes		*prev = NULL;
	t_processes		*next = NULL;

	proc = (t_processes *)elem->content;
	if (proc->live == 0)
	{
		if (elem->previous != NULL)
			prev = elem->previous->content;
		if (elem->next != NULL)
			next = elem->next->content;
		//printf("Killing process %d", proc->id);
		//if (prev != NULL)
		//	printf(" previous %d", prev->id);
		//if (next != NULL)
		//	printf(" next %d", next->id);
		//printf("\n");
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
	else if (proc->live >= NBR_LIVE && g_data->inc == 0)
	{
		g_data->cycle_die -= CYCLE_DELTA;
		g_data->check_left = MAX_CHECKS;
		g_data->inc = 1;
	}
	proc->live = 0;
}

static void		play_processes(t_list *elem)
{
	t_processes		*proc;
	t_op			*new_op;

	proc = (t_processes *)elem->content;
	if (proc->pc >= MEM_SIZE)
		proc->pc -= MEM_SIZE;
//	move(proc->pc * 3 / (64 * 3) + 1, proc->pc * 3 % (64 * 3) + 1);
//	attron(COLOR_PAIR(7));
//	addstr("  ");
//	attroff(COLOR_PAIR(7));
//	refresh();
	if (proc->op == NULL)
	{
		new_op = parse_op(proc->pc);
		proc->op = new_op;
		if (new_op != NULL)
		{
			proc->cycle_left = proc->op->cycle_cost - 1;
			//ft_printf("Create op %s for %d at %d\n", proc->op->label, proc->id, proc->pc);
		}
		if (new_op == NULL)
			proc->pc++;
	}
	else
	{
		proc->cycle_left--;
		if (proc->cycle_left == 0)
		{
			exe_op(proc->op, proc);
			proc->op = NULL;
		}
	}
}

void			game(void)
{
	int		i;

	g_data->cycle_die = CYCLE_TO_DIE;
	g_data->check_left = MAX_CHECKS;
	i = -1;
	while (++i < 75000)
	{
	//	usleep(100000);
		if (g_data->arg & 1 && i == g_data->dump)
			return ;
		ft_lstiter(g_data->processes, play_processes);
		if (g_data->cycle_die != 0 && i >= g_data->cycle_die)
		{
			i = -1;
			//printf("Alive processe : %d\n", g_data->nb_processes);
			g_data->inc = 0;
			ft_lstiter(g_data->processes, check_processes_alive);
			if (g_data->nb_processes == 0)
				break ;
			if (g_data->inc == 0)
				g_data->check_left--;
			if (g_data->check_left == 0)
			{
				g_data->cycle_die -= CYCLE_DELTA;
				g_data->check_left = MAX_CHECKS;
			}
			//printf("%s, cycle_die: %d, check_left: %d\n", "check if process alive", g_data->cycle_die, g_data->check_left);
		}
	}
}
