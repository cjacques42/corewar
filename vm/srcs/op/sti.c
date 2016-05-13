/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:27:42 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/13 14:17:42 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_processes *current)
{
	int					ocp;
	int					p1;
	int					p2;
	int					p3;
	int					place;

	place = current->pc;
	ocp = get_vm_value(&place, 1);
	p1 = check_ocp(ocp, 6, &place, 0);
	p2 = check_ocp(ocp, 4, &place, 1);
	// penser a check si p2 et p3 quand c'est des registre si c'est bien entre 1 et 16
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
		p2 %= IDX_MOD;
		p2 += current->pc;
		p2 %= MEM_SIZE;
		while (p2 < 0)
			p2 += MEM_SIZE;
		g_data->vm[p2] = current->reg[p1 - 1] >> 24;
		write_val(p2, current->reg[p1 - 1], current->player_id);
		current->pc = place;
	}
	if (g_data->arg & 4)
	{
		ft_printf("P%5d | sti r%d %d %d\n", current->id + 1, p1,
		 p2 - (p3 + current->pc - 5), p3);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d) \n",
		 p2 - (p3 + current->pc - 5), p3, p2 - (p3 + current->pc - 5) + p3, p2);
	}
	debug_op(current, place, 6);
}
