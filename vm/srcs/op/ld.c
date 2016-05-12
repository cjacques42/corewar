/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 21:24:41 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/12 17:34:27 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_processes *current)
{
	int				p1;
	int				p2;
	int				place;
	int				ocp;
	int				debug;

	place = current->pc;
	ocp = g_data->vm[place += 1];
	p1 = check_ocp(ocp, 6, &place, 0);
	if (check_type(ocp, 6) == 'i')
		p1 = get_val_from_addr(p1, 1, current);
	p2 = check_ocp(ocp, 4, &place, 0);
	if (check_type(ocp, 6) != 'r' && check_type(ocp, 6) != 0 &&
	check_type(ocp, 4) == 'r' && check_reg(p2))
	{
		current->reg[p2 - 1] = p1;
		current->carry = change_carry(p1);
	}
//	printf("P%5d | ld %d r%d\n", current->id + 1, p1, p2);
//	printf("ADV 7 (%#06x -> ", current->pc);
	current->pc = place + 1;
	current->pc %= MEM_SIZE;
//	printf(" %#06x) ", current->pc);
	debug = 7;
	while (debug)
	{
//		printf("%02x ", g_data->vm[current->pc - debug]);
		debug--;
	}
//	printf("\n");
}
