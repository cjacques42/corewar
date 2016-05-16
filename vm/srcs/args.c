/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:24:07 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/16 12:08:13 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		store_id(int *val, int *n)
{
	g_data->n[*n] = *val;
	(*n)++;
	(*val)++;
}

static void		dump(char **args, int *nb_args, int *i)
{
	if (ft_strcmp(args[*i + 1], ft_itoa(ft_atoi(args[*i + 1]))))
		usage();
	if (!(g_data->arg & 1))
		g_data->arg |= 1;
	g_data->dump = ft_atoi(args[*i + 1]);
	*nb_args -= 2;
	*i += 2;
}

static void		put_player_id(char **args, int *j, int *nb_args, int *i)
{
	int val;
	int i2;

	i2 = 0;
	if (ft_strcmp(args[*i + 1], ft_itoa(ft_atoi(args[*i + 1]))) || *j >= 4)
		usage();
	if (!(g_data->arg & 2))
		g_data->arg |= 1 << 1;
	val = ft_atoi(args[*i + 1]);
	while (i2 < *j)
	{
		if (g_data->n[i2] == val)
			err_exit("Put a different number for each player");
		i2++;
	}
	g_data->n[*j] = val;
	*nb_args -= 2;
	*i += 3;
	(*j)++;
}

static void		enable_ncurse(int *nb_args, int *i)
{
	g_data->ncurse = 1;
	*nb_args -= 1;
	*i += 1;
}

static void		verbose(int *nb_args, int *i)
{
	if (!(g_data->arg & 4))
		g_data->arg |= 1 << 2;
	*nb_args -= 1;
	*i += 1;
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
			dump(args, nb_args, &i);
		else if (!ft_strcmp(args[i], "-n") && args[i + 1])
			put_player_id(args, &j, nb_args, &i);
		else if (!ft_strcmp(args[i], "-nc"))
			enable_ncurse(nb_args, &i);
		else if (!ft_strcmp(args[i], "-v"))
			verbose(nb_args, &i);
		else
		{
			store_id(&id, &j);
			i++;
		}
	}
}
