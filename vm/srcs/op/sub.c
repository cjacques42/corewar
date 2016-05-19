/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:42:13 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:58:25 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub(t_processes *current)
{
	long	ocp;
	int		p[4];
	int		adv;

	adv = 0;
	ocp = 0;
	if (!current->op->ocp)
		ocp = get_vm_value(&adv, 1, current->pc);
	p[1] = check_ocp(ocp, 1, &adv, current);
	p[2] = check_ocp(ocp, 2, &adv, current);
	p[3] = check_ocp(ocp, 3, &adv, current);
	if (check_all_reg(ocp, p) && test_ocp(current->op, ocp))
	{
		current->reg[p[3] - 1] = current->reg[p[1] - 1] -
		current->reg[p[2] - 1];
		current->carry =
		change_carry(current->reg[p[1] - 1] - current->reg[p[2] - 1]);
		if (g_data->arg & 4 && !g_data->ncurse)
			ft_printf("P%5d | sub r%d r%d r%d\n",
			current->id + 1, p[1], p[2], p[3]);
	}
	debug_op(current, adv);
}
