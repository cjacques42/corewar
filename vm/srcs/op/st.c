/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:18:46 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/13 21:39:43 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_processes *current)
{
	int				ocp;
	int				p1;
	int				p2;
	int				place;
	int				paff;
	int				adv;

	place = current->pc;
	ocp = get_vm_value(&place, 1);
	adv = 2;
	if (ocp != 0)
		adv = 5;
	p1 = check_ocp(ocp, 6, &place, 0);
	p2 = check_ocp(ocp, 4, &place, 0);
	if ((check_type(ocp, 4) == 'r' || check_type(ocp, 4) == 'i') &&
	check_type(ocp, 6) == 'r' && check_reg(p1))
	{
		if (check_type(ocp, 4) == 'r' && check_reg(p2))
			current->reg[p2 - 1] = current->reg[p1 - 1];
		else
		{
			paff = p2;
			p2 %= IDX_MOD;
			p2 += current->pc;
			p2 %= MEM_SIZE;
			while (p2 < 0)
				p2 += MEM_SIZE;
			g_data->vm[p2] = current->reg[p1 - 1] >> 24;
			write_val(p2, current->reg[p1 - 1], current->player_id);
			if (g_data->arg & 4)
				ft_printf("P%5d | st r%d %d\n", current->id + 1, p1, paff);
		}
	}
	current->pc = place;
	debug_op(current, current->pc, adv);
}
