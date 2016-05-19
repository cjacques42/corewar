/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:18:46 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:58:08 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ex_st(t_processes *current, int paff, int p[4], int ocp)
{
	if (check_type(ocp, 4) == 'r' && check_reg(p[2]))
		current->reg[p[2] - 1] = current->reg[p[1] - 1];
	else
	{
		paff = p[2];
		p[2] %= IDX_MOD;
		p[2] += current->pc;
		p[2] %= MEM_SIZE;
		while (p[2] < 0)
			p[2] += MEM_SIZE;
		g_data->vm[p[2]] = current->reg[p[1] - 1] >> 24;
		write_val(p[2], current->reg[p[1] - 1], current->player_id);
		if (g_data->arg & 4 && !g_data->ncurse)
			ft_printf("P%5d | st r%d %d\n",
			current->id + 1, p[1], paff);
	}
}

void		st(t_processes *current)
{
	int				ocp;
	int				p[3];
	int				adv;

	adv = 0;
	ocp = 0;
	if (!current->op->ocp)
		ocp = get_vm_value(&adv, 1, current->pc);
	p[1] = check_ocp(ocp, 1, &adv, current);
	p[2] = check_ocp(ocp, 2, &adv, current);
	if (check_all_reg(ocp, p) && test_ocp(current->op, ocp))
		ex_st(current, 0, p, ocp);
	debug_op(current, adv);
}
