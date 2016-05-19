/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:37:39 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:57:54 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ex_lldi(int p[4], t_processes *current, int ocp)
{
	if (check_type(ocp, 6) == 'r' && check_reg(p[1]))
		p[1] = current->reg[p[1] - 1];
	else if (check_type(ocp, 2) == 'i')
		p[1] = get_val_from_addr(p[1], 1, current);
	if (check_type(ocp, 4) == 'r' && check_reg(p[2]))
		p[2] = current->reg[p[2] - 1];
	p[2] += p[1];
	current->reg[p[3] - 1] = get_val_from_addr(p[2], 1, current);
	current->carry = change_carry(get_val_from_addr(p[2], 1, current));
	if (g_data->arg & 4 && !g_data->ncurse)
	{
		ft_printf("P%5d | lldi %d %d r%d\n", current->id + 1, p[1],
		p[2] - p[1], p[3]);
		ft_printf(
		"       | -> load from %d + %d = %d (with pc %d)\n",
		p[1], p[2] - p[1], p[2], (current->pc + p[2]));
	}
}

void		lldi(t_processes *current)
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
		ex_lldi(p, current, ocp);
	debug_op(current, adv);
}
