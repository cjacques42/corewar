/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:00:34 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 10:48:07 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_nbr(char *str, long nbr, int index)
{
	long		total;
	int			neg;

	total = 0;
	neg = 1;
	if (str[index] == '-')
	{
		index++;
		neg = -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		total = (total * 10 + (str[index] - '0')) % nbr;
		index++;
	}
	return (neg * total);
}

int			ft_dir(t_token tok, t_cmd *cmd, t_arg *arg)
{
	int		index;

	index = 1;
	ft_search(cmd, arg, tok, index);
	return (1);
}
