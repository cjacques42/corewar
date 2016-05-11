/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:02:31 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/11 18:46:39 by jcornill         ###   ########.fr       */
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
	proc->live = 0;
}

static void		play_processes(t_list *elem)
{
	t_processes		*proc;
	t_op			*new_op;

	proc = (t_processes *)elem->content;
	proc->pc %= MEM_SIZE;
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
		{
			proc->cycle_left = proc->op->cycle_cost - 1;
			//ft_printf("Create op %s for %d at %d\n", proc->op->label, proc->id, proc->pc);
		}
		if (new_op == NULL)
		{
			ncur_print_char(proc->pc, 0, 1);
			proc->print = 0;
			proc->pc++;
		}
	}
	else
	{
		proc->cycle_left--;
		if (proc->cycle_left == 0)
		{
			ncur_print_char(proc->pc, 0, 1);
			proc->print = 0;
			exe_op(proc->op, proc);
			proc->op = NULL;
		}
	}
}

void			game(void)
{
	int		i;
	int		cycles;

	g_data->cycle_die = CYCLE_TO_DIE;
	g_data->check_left = MAX_CHECKS;
	i = -1;
	cycles = i;
	while (++i < 75000)
	{
		timeout(10);
		move(0, 200);
		g_data->pause = 1;
		while (g_data->pause == 1)
		{
			if (getch() == 'p')
				g_data->pause = 0;
			move(0, 200);
		}
		move(1, 200);
		printw("%d", cycles + 1);
		move(2, 200);
		printw("%d", g_data->nb_processes);
		move(3, 200);
		printw("%d", g_data->cycle_die);
		move(4, 200);
		printw("%d", g_data->check_left);
		cycles++;
		if (g_data->arg & 1 && cycles >= g_data->dump)
			return ;
		ft_lstiter(g_data->processes, play_processes);
		if (g_data->cycle_die != 0 && i >= g_data->cycle_die)
		{
			i = -1;
			//printf("Alive processe : %d\n", g_data->nb_processes);
			ft_lstiter(g_data->processes, check_processes_alive);
			if (g_data->nb_processes == 0)
				break ;
			if (g_data->t_live < NBR_LIVE)
				g_data->check_left--;
			if (g_data->check_left == 0 || g_data->t_live >= NBR_LIVE)
			{
				g_data->pause = 1;
				g_data->cycle_die -= CYCLE_DELTA;
				g_data->check_left = MAX_CHECKS;
			}
			g_data->t_live = 0;
			//printf("%s, cycle_die: %d, check_left: %d\n", "check if process alive", g_data->cycle_die, g_data->check_left);
		}
	}
}
