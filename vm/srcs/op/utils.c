/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:09:48 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/06 19:05:22 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_int(unsigned char *vm, int nbr)
{
	vm[0] = nbr >> 24;
	vm[1] = nbr >> 16;
	vm[2] = nbr >> 8;
	vm[3] = nbr;
}

char	check_type(int ocp, int p_place)
{
	if (((ocp >> p_place) & 3) == 1)
		return ('r');
	else if (((ocp >> p_place) & 3) == 2)
		return ('d');
	else if (((ocp >> p_place) & 3) == 3)
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
	if (mod == 1)
		p %= IDX_MOD;
	p += current->pc;
	if (p >= MEM_SIZE)
		p -= MEM_SIZE;
	else if (p < 0)
		p += MEM_SIZE;
	return (ft_char_to_int(&g_data->vm[p]));
}

int		check_ocp(int ocp, int place_p, int *place, char dir)
{
	int		param;

	if (check_type(ocp, place_p) == 'r')
		param = g_data->vm[*place += 1];
	else if (check_type(ocp, place_p) == 'i')
	{
		param = (int)ft_char_to_short(&g_data->vm[*place += 1]);
		*place += 1;
	}
	else if (check_type(ocp, place_p) == 'd')
	{
		if (dir == 1)
		{
			param = (int)ft_char_to_short(&g_data->vm[*place += 1]);
			*place += 1;
		}
		else
		{
			param = ft_char_to_int(&g_data->vm[*place += 1]);
			*place += 3;
		}
	}
	else
		return (0);
	return (param);
}
