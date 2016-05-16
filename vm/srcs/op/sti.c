/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:27:42 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/16 15:10:49 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_processes *current)
{
	int					ocp;
	int					p[4];
	int					place;
	int					adv;
	int					paff;

	place = current->pc;
	ocp = get_vm_value(&place, 1);
	p[1] = check_ocp(ocp, 6, &place, 0);
	p[2] = check_ocp(ocp, 4, &place, 1);
	// penser a check si p2 et p3 quand c'est des registre si c'est bien entre 1 et 16
	adv = 7;
	if (check_type(ocp, 4) == 'i')
		p[2] = get_val_from_addr(p[2], 1, current);
	else if (check_type(ocp, 4) == 'r' && check_reg(p[2]))
	{
		p[2] = current->reg[p[2] - 1];
		adv -= 1;
	}
	p[3] = check_ocp(ocp, 2, &place, 1);
	if (check_type(ocp, 2) == 'r' && check_reg(p[3]))
	{
		p[3] = current->reg[p[3] - 1];
		adv -= 1;
	}
	if ((check_type(ocp, 2) == 'd' || check_type(ocp, 2) == 'r') &&
	check_type(ocp, 6) == 'r' && check_type(ocp, 4) != 0 && check_reg(p[1]))
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
		current->pc = place;
	}
	if (g_data->arg & 4)
	{
		ft_printf("P%5d | sti r%d %d %d\n", current->id + 1, p[1],
		paff, p[3]);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		paff, p[3], paff + p[3], paff + p[3] + current->pc - adv + 1);
	}
	debug_op(current, place, adv);
}
