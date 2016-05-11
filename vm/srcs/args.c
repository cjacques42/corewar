/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:24:07 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/11 16:51:21 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		store_id(int *val, int *n)
{
	g_data->n[*n] = *val;
	(*n)++;
	(*val)++;
}

void			store_args(int *nb_args, char **args)
{
	int i;
	int j;
	int id;
	int tmp;

	i = 1;
	j = 0;
	id = 1;
	tmp = *nb_args;
	while (i <= tmp)
	{
		if (!ft_strcmp(args[i], "-dump") && args[i + 1])
		{
			g_data->arg |= 1;
			g_data->dump = ft_atoi(args[i + 1]);
			*nb_args -= 2;
			i += 2;
		}
		else if (!ft_strcmp(args[i], "-n"))
		{
			g_data->arg |= 1 << 1;
			g_data->n[j] = ft_atoi(args[i + 1]);
			*nb_args -= 2;
			i += 3;
			j++;
		}
		else
		{
			store_id(&id, &j);
			i++;
		}
	}
}
