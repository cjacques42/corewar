/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:41:14 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 17:27:02 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static int	ft_behind(t_args *arg, char *str)
{
	int		ret;

	ret = 0;
	if (arg->field > arg->precis)
	{
		if (arg->val_field && !arg->val_minus && arg->val_z)
			ft_printnchar(arg->field - arg->precis, '0');
		if (arg->val_field && !arg->val_minus && !arg->val_z)
			ft_printnchar(arg->field - arg->precis, ' ');
	}
	write(1, str, arg->precis);
	ret = arg->precis;
	if (arg->val_field == 1 && arg->val_minus == 1)
		ft_printnchar(arg->field - arg->precis, ' ');
	return (ret);
}

static int	ft_ret_str(va_list *list_args, t_args *arg)
{
	char	*str;
	int		ret;

	str = ft_strdup(va_arg(*list_args, char *));
	(str == NULL) ? str = ft_strdup("(null)") : 0;
	ret = ft_strlen(str);
	if (ret < arg->precis || arg->val_prec == 0)
	{
		if (ret > arg->precis || ret < arg->field)
		{
			if (arg->val_field && !arg->val_minus && arg->val_z)
				ft_printnchar(arg->field - ret, '0');
			if (arg->val_field && !arg->val_minus && !arg->val_z)
				ft_printnchar(arg->field - ret, ' ');
		}
		ft_putstr(str);
		if (arg->val_field == 1 && arg->val_minus == 1)
			ft_printnchar(arg->field - ft_strlen(str), ' ');
	}
	else
		ret = ft_behind(arg, str);
	free(str);
	return (ft_retfield(arg, ret));
}

int			ft_print_str(va_list *list_args, t_args *arg)
{
	if (ft_strcmp(arg->conv, "l") == 0)
	{
		ft_memset(arg->conv, 0, 3);
		return (ft_print_wstr(list_args, arg));
	}
	else if (ft_strcmp(arg->conv, "") == 0)
		return (ft_ret_str(list_args, arg));
	else
		return (-1);
}
