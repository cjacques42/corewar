/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:49:05 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/19 17:50:14 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int		ft_print_percent(va_list *list_args, t_args *arg)
{
	(void)*list_args;
	if (arg->val_minus == 0 && arg->field > 1)
	{
		if (arg->val_z == 0)
			ft_printnchar(arg->field - 1, ' ');
		else
			ft_printnchar(arg->field - 1, '0');
	}
	ft_putchar('%');
	if (arg->val_minus == 1 && arg->field > 1)
		ft_printnchar(arg->field - 1, ' ');
	return (ft_retfield(arg, 1));
}
