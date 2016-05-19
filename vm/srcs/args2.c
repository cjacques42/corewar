/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:09:59 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/18 17:29:38 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		verbose(int *nb_args, int *i)
{
	if (!(g_data->arg & 4))
		g_data->arg |= 1 << 2;
	*nb_args -= 1;
	*i += 1;
}

void		hide(int *nb_args, int *i, char *str)
{
	if (!ft_strcmp(str, "-hl"))
		if (!(g_data->arg & 8))
			g_data->arg |= 1 << 3;
	if (!ft_strcmp(str, "-ha"))
		if (!(g_data->arg & 16))
			g_data->arg |= 1 << 4;
	*nb_args -= 1;
	*i += 1;
}
