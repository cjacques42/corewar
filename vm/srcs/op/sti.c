/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:27:42 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 16:58:19 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ex_sti(t_processes *current, int p[4], int paff)
{
	paff = p[2];
	p[2] += p[3];
	p[2] %= IDX_MOD;
	p[2] += current->pc;
	p[2] %= MEM_SIZE;
	while (p[2] < 0)
		p[2] += MEM_SIZE;
	g_data->vm[p[2]] = current->reg[p[1] - 1] >> 24;
	write_val(p[2], current->reg[p[1] - 1], current->player_id);
	if (g_data->arg & 4 && !g_data->ncurse)
	{
		ft_printf("P%5d | sti r%d %d %d\n", current->id + 1, p[1],
		paff, p[3]);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		paff, p[3], paff + p[3], (paff + p[3]) % IDX_MOD + current->pc);
	}
}

void		sti(t_processes *current)
{
	int					ocp;
	int					p[4];
	int					adv;

	adv = 0;
	ocp = 0;
	if (!current->op->ocp)
		ocp = get_vm_value(&adv, 1, current->pc);
	p[1] = check_ocp(ocp, 1, &adv, current);
	p[2] = check_ocp(ocp, 2, &adv, current);
	p[3] = check_ocp(ocp, 3, &adv, current);
	if (check_all_reg(ocp, p) && test_ocp(current->op, ocp))
	{
		if (check_type(ocp, 4) == 'i')
			p[2] = get_val_from_addr(p[2], 1, current);
		else if (check_type(ocp, 4) == 'r' && check_reg(p[2]))
			p[2] = current->reg[p[2] - 1];
		if (check_type(ocp, 2) == 'r' && check_reg(p[3]))
			p[3] = current->reg[p[3] - 1];
		ex_sti(current, p, 0);
	}
	debug_op(current, adv);
}
