/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:27:42 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:56:15 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_processes *current)
{
	int		p[4];
	int		adv;
	int		ocp;

	adv = 0;
	ocp = 0;
	if (!current->op->ocp)
		ocp = get_vm_value(&adv, 1, current->pc);
	p[1] = check_ocp(ocp, 1, &adv, current);
	if (check_all_reg(ocp, p) && test_ocp(current->op, ocp))
	{
		p[1] = current->reg[p[1] - 1] % 256;
		if (!(g_data->arg & 16) && !g_data->ncurse)
			write(1, &p[1], 1);
	}
	debug_op(current, adv);
}
