/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 18:31:44 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/06 16:08:59 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
/*
static void		print_processes(t_list *elem)
{
	t_processes		*proc;

	proc = (t_processes *)elem->content;
	ft_putstr("process ");
	ft_putnbr(proc->id);
	ft_putstr(" at ");
	ft_putnbr(proc->pc);
	ft_putstr(" doing ");
	if (proc->op != NULL)
		ft_putstr(proc->op->label);
	else
		ft_putstr("NULL");
	ft_putstr(" from player ");
	ft_putnbr(proc->player_id);
	ft_putstr(" with ");
	if (proc->op != NULL)
		ft_putnbr(proc->op->cycle_cost);
	else
		ft_putstr("NULL");
	ft_putstr(" left cycle and live at ");
	ft_putnbr((int)proc->live);
	ft_putchar('\n');
}

static void		print_player(t_list *elem)
{
	t_player	*player;

	player = (t_player *)elem->content;
	ft_putstr("Player ");
	ft_putnbr(player->id);
	ft_putstr(" : ");
	ft_putstr(player->name);
	ft_putstr(" , ");
	ft_putstr(player->comment);
	ft_putstr(" , ");
	ft_putnbr(player->size);
	ft_putchar('\n');
}
*/
static void		print_vm(int boolo)
{
	int		i;

	i = 0;
	if (boolo == 1)
	{
//		ft_putstr("printing VM\n");
		printf("0x%04x : ", i);
		while (i < MEM_SIZE)
		{
			printf("%02x ", g_data->vm[i]);
			if (i % 64 == 63)
			{
				printf("\n");
				if (i < 4095)
					printf("%#.04x : ", i + 1);
			}
			i++;
		}
		printf("\n");
	}
}

void			print(void)
{
	//ft_lstiter(g_data->players, print_player);
	//ft_lstiter(g_data->processes, print_processes);
	print_vm(1);
}
