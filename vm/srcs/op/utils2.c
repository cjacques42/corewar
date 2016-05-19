/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:39:52 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/19 18:59:13 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				check_all_reg(int ocp, int p[4])
{
	if (check_type(ocp, 6) == 'r')
		if (!check_reg(p[1]))
			return (0);
	if (check_type(ocp, 4) == 'r')
		if (!check_reg(p[2]))
			return (0);
	if (check_type(ocp, 2) == 'r')
		if (!check_reg(p[3]))
			return (0);
	return (1);
}

int				test_ocp(t_op *op, int ocp)
{
	int		nb_args;
	int		result;
	int		val;
	int		i;

	nb_args = op->nb_arg - 1;
	result = 0;
	i = 0;
	while (nb_args >= 0)
	{
		val = ocp >> (2 * (3 - i)) & 3;
		val = (val == 3) ? 4 : val;
		if ((op->type[i] & val) == 0)
			result++;
		i++;
		nb_args--;
	}
	return (result == 0);
}

int				char_to_nbr(int *adv, const int len, int pc)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (i < len)
	{
		result += (int)get_vm_value(adv, 1, pc) << ((8 * (len - 1)) - (8 * i));
		i++;
	}
	return (result);
}

unsigned char	get_vm_value(int *adv, int add, int pc)
{
	int		addr;

	*adv += add;
	addr = *adv + pc;
	addr %= MEM_SIZE;
	while (addr < 0)
		addr += MEM_SIZE;
	return (g_data->vm[addr]);
}

void			debug_op(t_processes *current, int adv)
{
	int		prev;

	adv += 1;
	if (g_data->arg & 4 && !g_data->ncurse)
	{
		if (current->pc == 0)
			ft_printf("ADV %d (%#04x -> ", adv, current->pc);
		else
			ft_printf("ADV %d (%#06x -> ", adv, current->pc);
	}
	current->pc += adv;
	if (g_data->arg & 4 && !g_data->ncurse)
		ft_printf("%#06x) ", current->pc);
	current->pc %= MEM_SIZE;
	if (g_data->arg & 4 && !g_data->ncurse)
	{
		while (adv)
		{
			if ((prev = (current->pc - adv) % MEM_SIZE) < 0)
				prev += MEM_SIZE;
			ft_printf("%02x ", g_data->vm[prev]);
			adv--;
		}
		ft_printf("\n");
	}
}
