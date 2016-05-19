/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:31:20 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 18:59:43 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ex_ldi(int p[4], t_processes *current)
{
	p[2] += p[1];
	current->reg[p[3] - 1] = get_val_from_addr(p[2], 1, current);
	if (g_data->arg & 4 && !g_data->ncurse)
	{
		ft_printf("P%5d | ldi %d %d r%d\n", current->id + 1, p[1],
		p[2] - p[1], p[3]);
		ft_printf(
		"       | -> load from %d + %d = %d (with pc and mod %d)\n",
		p[1], p[2] - p[1], p[2], (current->pc + p[2]) % IDX_MOD);
	}
}

void		ldi(t_processes *current)
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
		if (check_type(ocp, 6) == 'r' && check_reg(p[1]))
			p[1] = current->reg[p[1] - 1];
		else if (check_type(ocp, 6) == 'i')
			p[1] = get_val_from_addr(p[1], 1, current);
		if (check_type(ocp, 4) == 'r' && check_reg(p[2]))
			p[2] = current->reg[p[2] - 1];
		ex_ldi(p, current);
	}
	debug_op(current, adv);
}
