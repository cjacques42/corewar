/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:31:20 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/13 14:22:08 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldi(t_processes *current)
{
	long	ocp;
	int		p1;
	int		p2;
	int		p3;
	int		place;

	place = current->pc;
	ocp = g_data->vm[place += 1];
	p1 = check_ocp(ocp, 6, &place, 1);
	if (check_type(ocp, 6) == 'r' && check_reg(p1))
		p1 = current->reg[p1 - 1];
	else if (check_type(ocp, 6) == 'i')
		p1 = get_val_from_addr(p1, 1, current);
	p2 = check_ocp(ocp, 4, &place, 1);
	if (check_type(ocp, 4) == 'r' && check_reg(p2))
		p2 = current->reg[p2 - 1];
	p3 = check_ocp(ocp, 2, &place, 0);
	if (check_type(ocp, 4) != 'i' && check_type(ocp, 4) != 0 &&
	check_type(ocp, 2) == 'r' && check_reg(p3))
	{
		p2 += p1;
		p2 += current->pc;
		current->reg[p3 - 1] = get_val_from_addr(p2, 1, current);
	}
	if (g_data->arg & 4)
	{
		ft_printf("P%5d | ldi %d %d r%d\n", current->id + 1, p1,
		 p2 - (p1 + current->pc), p3);
		 ft_printf("       | -> load from %d + %d = %d (with pc and mod %d) \n",
		  p1, p2 - (p1 + current->pc), p2 - (p1 + current->pc) + p1, p2);
	 }
	debug_op(current, place, 6);
}
