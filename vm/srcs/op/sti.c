/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:27:42 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/10 12:32:54 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_processes *current)
{
	int		ocp;
	int		p1;
	int		p2;
	int		p3;
	int		place;

	place = current->pc;
	ocp = g_data->vm[place += 1];
	p1 = check_ocp(ocp, 6, &place, 0);
	p2 = check_ocp(ocp, 4, &place, 1);
	if (check_type(ocp, 4) == 'i')
		p2 = get_val_from_addr(p2, 1, current);
	else if (check_type(ocp, 4) == 'r' && check_reg(p2))
		p2 = current->reg[p2 - 1];
	p3 = check_ocp(ocp, 2, &place, 1);
	if (check_type(ocp, 2) == 'r' && check_reg(p3))
		p3 = current->reg[p3 - 1];
	if ((check_type(ocp, 2) == 'd' || check_type(ocp, 2) == 'r') &&
	check_type(ocp, 6) == 'r' && check_type(ocp, 4) != 0 && check_reg(p1))
	{
		p2 += p3;
		while (p2 >= MEM_SIZE)
			p2 -= MEM_SIZE;
		while (p2 < 0)
			p2 += MEM_SIZE;
		p2 %= IDX_MOD;
		p2 += current->pc;
		g_data->vm[p2] = current->reg[p1 - 1] >> 24;
		g_data->vm[(p2 + 1) % 4096] = current->reg[p1 - 1] >> 16;
		g_data->vm[(p2 + 2) % 4096] = current->reg[p1 - 1] >> 8;
		g_data->vm[(p2 + 3) % 4096] = current->reg[p1 - 1];
		//	write_int(&g_data->vm[p2], current->reg[p1 - 1]);
	}
//	printf("currentpc == %x\n", current->pc);
	printf("sti r%d %d %d\n", p1, p2, p3);
	printf("(%#06x -> ", current->pc);
	current->pc = place + 1;
	current->pc %= MEM_SIZE;
	printf(" %#06x)\n", current->pc);
}
