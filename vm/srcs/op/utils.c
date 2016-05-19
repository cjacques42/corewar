/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:09:48 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/18 18:30:18 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_val(int pc, int nbr, int player_id)
{
	int		color;

	g_data->vm[pc] = nbr >> 24;
	g_data->vm[(pc + 1) % MEM_SIZE] = nbr >> 16;
	g_data->vm[(pc + 2) % MEM_SIZE] = nbr >> 8;
	g_data->vm[(pc + 3) % MEM_SIZE] = nbr;
	color = -player_id;
	g_data->vm_color[pc] = color;
	g_data->vm_color[(pc + 1) % MEM_SIZE] = color;
	g_data->vm_color[(pc + 2) % MEM_SIZE] = color;
	g_data->vm_color[(pc + 3) % MEM_SIZE] = color;
	ncur_print_char(pc, 0, 1);
	ncur_print_char((pc + 1) % MEM_SIZE, 0, 1);
	ncur_print_char((pc + 2) % MEM_SIZE, 0, 1);
	ncur_print_char((pc + 3) % MEM_SIZE, 0, 1);
}

char	check_type(int ocp, int p_place)
{
	if (((ocp >> p_place) & 3) == REG_CODE)
		return ('r');
	else if (((ocp >> p_place) & 3) == DIR_CODE)
		return ('d');
	else if (((ocp >> p_place) & 3) == IND_CODE)
		return ('i');
	else
		return (0);
}

int		check_reg(int p)
{
	if (p > 16 || p < 1)
		return (0);
	return (1);
}

int		get_val_from_addr(int p, char mod, t_processes *current)
{
	p -= 1;
	if (mod == 1)
		p %= IDX_MOD;
	return (char_to_nbr(&p, 4, current->pc));
}

int		check_ocp(int ocp, int n_param, int *adv, t_processes *current)
{
	int		param;
	int		place_p;

	place_p = 8 - (n_param * 2);
	if (check_type(ocp, place_p) == 'r')
		param = get_vm_value(adv, 1, current->pc);
	else if (check_type(ocp, place_p) == 'i')
		param = (int)(short)char_to_nbr(adv, 2, current->pc);
	else if (check_type(ocp, place_p) == 'd')
	{
		if (current->op->dir_size == 1)
			param = (int)(short)char_to_nbr(adv, 2, current->pc);
		else
			param = (int)char_to_nbr(adv, 4, current->pc);
	}
	else
		return (0);
	return (param);
}
