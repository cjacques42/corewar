/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 21:22:25 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/12 15:59:21 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void lld(t_processes *current)
{
	int				p1;
	int				p2;
	int				place;
	unsigned long	ocp;

	place = current->pc;
	ocp = g_data->vm[place += 1];
	p1 = check_ocp(ocp, 6, &place, 0);
	if (check_type(ocp, 6) == 'i')
		p1 = get_val_from_addr(p1, 0, current);
	p2 = check_ocp(ocp, 4, &place, 0);
	if (check_type(ocp, 6) != 'r' && check_type(ocp, 6) != 0 &&
	check_type(ocp, 4) == 'r' && check_reg(p2))
	{
		current->reg[p2 - 1] = p1;
		current->carry = change_carry(p1);
	}
	current->pc = place + 1;
	current->pc %= MEM_SIZE;
}
