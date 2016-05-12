/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:09:00 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/12 17:34:27 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	xor(t_processes *current)
{
	long	ocp;
	int		p1;
	int		p2;
	int		p3;
	int		place;
	int		debug;

	place = current->pc;
	ocp = g_data->vm[place += 1];
	p1 = check_ocp(ocp, 6, &place, 0);
	if (check_type(ocp, 6) == 'r' && check_reg(p1))
		p1 = current->reg[p1 - 1];
	else if (check_type(ocp, 6) == 'i')
		p1 = get_val_from_addr(p1, 0, current);
	p2 = check_ocp(ocp, 4, &place, 0);
	if (check_type(ocp, 4) == 'r' && check_reg(p2))
		p2 = current->reg[p2 - 1];
	else if (check_type(ocp, 4) == 'i')
		p2 = get_val_from_addr(p2, 0, current);
	p3 = check_ocp(ocp, 2, &place, 0);
	if (check_type(ocp, 2) == 'r' && check_reg(p3))
	{
		current->reg[p3 - 1] = p1 ^ p2;
		current->carry = change_carry(p1 ^ p2);
	}
//	printf("P%5d | xor %d %d r%d\n", current->id + 1, p1, p2, p3);
//	printf("ADV 5 (%#06x -> ", current->pc);
	current->pc = place + 1;
	current->pc %= MEM_SIZE;
//	printf("%#06x) ", current->pc);
	debug = 5;
	while (debug)
	{
//		printf("%02x ", g_data->vm[current->pc - debug]);
		debug--;
	}
//	printf("\n");
}
