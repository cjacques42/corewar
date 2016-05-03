/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:18:46 by stoussay          #+#    #+#             */
/*   Updated: 2016/04/29 16:38:47 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_processes *current)
{
	int		ocp;
	int		p1;
	int		p2;
	int		place;

	place = current->pc;
	ocp = g_data->vm[place += 1];
	p1 = check_ocp(ocp, 6, &place, 0);
	p2 = check_ocp(ocp, 4, &place, 0);
	if ((check_type(ocp, 4) == 'r' || check_type(ocp, 4) == 'i') &&
	check_type(ocp, 6) == 'r' && check_reg(p1))
	{
		if (check_type(ocp, 4) == 'r' && check_reg(p2))
			current->reg[p2 - 1] = current->reg[p1 - 1];
		else
		{
			p2 %= IDX_MOD;
			p2 += current->pc;
			while (p2 >= MEM_SIZE)
				p2 -= MEM_SIZE;
			while (p2 < 0)
				p2 += MEM_SIZE;
			write_int(&g_data->vm[p2], current->reg[p1 - 1]);
		}
	}
	current->pc = place + 1;
}
