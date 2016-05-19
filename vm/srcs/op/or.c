/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:27:03 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:58:00 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ex_or(t_processes *current, int p[4], int ocp)
{
	if (check_type(ocp, 6) == 'r' && check_reg(p[1]))
		p[1] = current->reg[p[1] - 1];
	else if (check_type(ocp, 6) == 'i')
		p[1] = get_val_from_addr(p[1], 0, current);
	if (check_type(ocp, 4) == 'r' && check_reg(p[2]))
		p[2] = current->reg[p[2] - 1];
	else if (check_type(ocp, 4) == 'i')
		p[2] = get_val_from_addr(p[2], 0, current);
	current->reg[p[3] - 1] = p[1] | p[2];
	current->carry = change_carry(p[1] | p[2]);
	if (g_data->arg & 4 && !g_data->ncurse)
		ft_printf("P%5d | or %d %d r%d\n", current->id + 1, p[1], p[2], p[3]);
}

void		or(t_processes *current)
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
		ex_or(current, p, ocp);
	debug_op(current, adv);
}
