/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:42:13 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/12 16:01:42 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub(t_processes *current)
{
	long	ocp;
	int		p1;
	int		p2;
	int		p3;
	int		place;

	place = current->pc;
	ocp = g_data->vm[place += 1];
	if (ocp == 84)
	{
		p1 = check_ocp(ocp, 6, &place, 0);
		p2 = check_ocp(ocp, 4, &place, 0);
		p3 = check_ocp(ocp, 2, &place, 0);
		if (check_reg(p1) && check_reg(p2) && check_reg(p3))
		{
			current->reg[p3 - 1] = current->reg[p1 - 1] - current->reg[p2 - 1];
			current->carry = change_carry(current->reg[p1 - 1] - current->reg[p2 - 1]);
		}
	}
	current->pc = place + 1;
	current->pc %= MEM_SIZE;
}
