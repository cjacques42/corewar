/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:18:46 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/11 18:47:00 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_processes *current)
{
	int				ocp;
	int				p1;
	int				p2;
	int				place;
	unsigned short	color;

	place = current->pc;
	ocp = g_data->vm[place += 1];
	p1 = check_ocp(ocp, 6, &place, 0);
	p2 = check_ocp(ocp, 4, &place, 0);
	int paff;
	paff = p2;
	if ((check_type(ocp, 4) == 'r' || check_type(ocp, 4) == 'i') &&
	check_type(ocp, 6) == 'r' && check_reg(p1))
	{
		if (check_type(ocp, 4) == 'r' && check_reg(p2))
			current->reg[p2 - 1] = current->reg[p1 - 1];
		else
		{
			p2 %= IDX_MOD;
			paff = p2;
			p2 += current->pc;
			p2 %= MEM_SIZE;
			while (p2 < 0)
				p2 += MEM_SIZE;
			g_data->vm[p2] = current->reg[p1 - 1] >> 24;
			g_data->vm[(p2 + 1) % MEM_SIZE] = current->reg[p1 - 1] >> 16;
			g_data->vm[(p2 + 2) % MEM_SIZE] = current->reg[p1 - 1] >> 8;
			g_data->vm[(p2 + 3) % MEM_SIZE] = current->reg[p1 - 1];
			color = 1;
			color = color << 8;
			color += 1;
			g_data->vm_color[p2] = color;
			g_data->vm_color[(p2 + 1) % MEM_SIZE] = color;
			g_data->vm_color[(p2 + 2) % MEM_SIZE] = color;
			g_data->vm_color[(p2 + 3) % MEM_SIZE] = color;
			ncur_print_char(p2, 0, 1);
			ncur_print_char((p2 + 1) % MEM_SIZE, 0, 1);
			ncur_print_char((p2 + 2) % MEM_SIZE, 0, 1);
			ncur_print_char((p2 + 3) % MEM_SIZE, 0, 1);
		//	write_int(&g_data->vm[p2], current->reg[p1 - 1]);
		}
	}
//	printf("P%5d | st r%d %d\n", current->id + 1, p1, paff);
//	printf("ADV 5 (%#06x -> ", current->pc);
//	current->pc = place + 1;
//	current->pc %= MEM_SIZE;
//	printf("%#06x) ", current->pc);
//	debug = 5;
//	while (debug)
//	{
//		printf("%02x ", g_data->vm[current->pc - debug]);
//		debug--;
//	}
//	printf("\n");
}
