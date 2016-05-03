/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:03:10 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 17:12:17 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int		ft_print_char(va_list *list_args, t_args *arg)
{
	int		ret;

	ret = 1;
	if (ft_strcmp(arg->conv, "l") == 0)
	{
		ft_memset(arg->conv, '\0', 3);
		return (ft_print_wchar(list_args, arg));
	}
	else if (ft_strcmp(arg->conv, "") == 0)
	{
		if (arg->val_field && !arg->val_minus && arg->val_z)
			ft_printnchar(arg->field - 1, '0');
		if (arg->val_field && !arg->val_minus && !arg->val_z)
			ft_printnchar(arg->field - 1, ' ');
		ft_putchar(va_arg(*list_args, int));
		if (arg->val_field == 1 && arg->val_minus == 1)
			ft_printnchar(arg->field - 1, ' ');
		return (ft_retfield(arg, ret));
	}
	else
		return (-1);
}
