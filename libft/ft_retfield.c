/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:13:59 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/20 14:23:46 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_retfield(t_args *arg, int ret)
{
	if ((arg->type == 'x' || arg->type == 'X') && arg->val_ht == 1)
		return (arg->field + 2);
	else if (arg->type == 'p')
		return (arg->field + 2);
	else if ((arg->type == 'o' || arg->type == 'O') && arg->val_ht == 1)
		return (arg->field + 1);
	else if ((arg->type == 'i' || arg->type == 'd') &&
			(arg->val_plus || arg->val_sp))
		return (arg->field + 1);
	if (arg->field > ret)
		return (arg->field);
	else
		return (ret);
}
