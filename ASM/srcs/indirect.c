/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:00:54 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 10:50:57 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_search(t_cmd *cmd, t_arg *arg, t_token tok, int index)
{
	int		i;

	i = cmd->nbr;
	if (tok == INDIRECT || tok == DIRECT)
	{
		if (g_op_tab[i].dir_size == 1)
			arg->nb = check_nbr(arg->key, 65536, index);
		else
			arg->nb = check_nbr(arg->key, 4294967296, index);
	}
	else
	{
		index++;
		arg->str = ft_strdup(arg->key + index);
	}
	return (1);
}

int			ft_ind(t_token tok, t_cmd *cmd, t_arg *arg)
{
	ft_search(cmd, arg, tok, 0);
	return (1);
}
