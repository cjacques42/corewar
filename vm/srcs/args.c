/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:24:07 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/12 14:43:01 by jcornill         ###   ########.fr       */
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
		else if (!ft_strcmp(args[i], "-n") && args[i + 1])
		{
			g_data->arg |= 1 << 1;
			g_data->n[j] = ft_atoi(args[i + 1]);
			*nb_args -= 2;
			i += 3;
			j++;
		}
		else if (!ft_strcmp(args[i], "-nc"))
		{
			g_data->ncurse = 1;
			*nb_args -= 1;
			i += 2;
		}
		else
		{
			store_id(&id, &j);
			i++;
		}
	}
}
