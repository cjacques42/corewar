/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:01:03 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/18 17:49:39 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_reg(t_token tok, t_arg *arg)
{
	size_t		i;
	int			total;

	total = 0;
	i = 1;
	while (arg->key[i] >= '0' && arg->key[i] <= '9')
	{
		total = total * 10 + (arg->key[i] - '0');
		if (total < 1 || total > 16)
			ft_tok_error(tok, arg->key, NULL, 0);
		i++;
	}
	arg->nb = total;
	return (1);
}
