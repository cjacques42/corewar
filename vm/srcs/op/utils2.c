/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:39:52 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/13 14:03:17 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		char_to_nbr(int *place, const int len)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (i < len)
	{
		result += (int)get_vm_value(place, 1) << ((8 * (len - 1)) - (8 * i));
		i++;
	}
	return (result);
}

int				change_carry(int val)
{
	if (val == 0)
		return (1);
	else
		return (0);
}

unsigned char	get_vm_value(int *place, int add)
{
	*place += add;
	*place %= MEM_SIZE;
	return (g_data->vm[*place]);
}

void			debug_op(t_processes *current, int place, int adv)
{
	if (g_data->arg & 4)
		ft_printf("ADV %d (%#06x -> ", adv, current->pc);
	current->pc = place + 1;
	current->pc %= MEM_SIZE;
	if (g_data->arg & 4)
	{
		ft_printf("%#06x) ", current->pc);
		while (adv)
		{
			ft_printf("%02x ", g_data->vm[current->pc - adv]);
			adv--;
		}
		ft_printf("\n");
	}
}
