/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 21:22:25 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 18:56:02 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld(t_processes *current)
{
	int				p[4];
	int				adv;
	unsigned long	ocp;

	adv = 0;
	ocp = 0;
	if (!current->op->ocp)
		ocp = get_vm_value(&adv, 1, current->pc);
	p[1] = check_ocp(ocp, 1, &adv, current);
	p[2] = check_ocp(ocp, 2, &adv, current);
	p[3] = 0;
	if (check_all_reg(ocp, p) && test_ocp(current->op, ocp))
	{
		if (check_type(ocp, 6) == 'i')
			p[1] = get_val_from_addr(p[1], 0, current);
		current->reg[p[2] - 1] = p[1];
		current->carry = change_carry(p[1]);
		if (g_data->arg & 4 && !g_data->ncurse)
			ft_printf("P%5d | lld %d r%d\n", current->id + 1, p[1], p[2]);
	}
	debug_op(current, adv);
}
