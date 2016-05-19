/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 18:31:44 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/19 17:00:39 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_vm(int boolo)
{
	int		i;

	i = 0;
	if (boolo == 1 && !g_data->ncurse)
	{
		ft_printf("0x%04x : ", i);
		while (i < MEM_SIZE)
		{
			ft_printf("%02x ", g_data->vm[i]);
			if (i % 64 == 63)
			{
				ft_printf("\n");
				if (i < 4095)
					ft_printf("%#.04x : ", i + 1);
			}
			i++;
		}
		ft_printf("\n");
	}
}

void			print(void)
{
	print_vm(1);
}
