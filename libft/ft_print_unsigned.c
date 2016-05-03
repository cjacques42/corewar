/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:15:57 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 17:39:11 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int				ft_print_unsigned(va_list *list_args, t_args *arg)
{
	unsigned long	nb;
	int				ret;

	if (arg->type == 'U')
		nb = va_arg(*list_args, unsigned long);
	else
		nb = ft_cast_unsigned(list_args, arg);
	ret = ft_nbrlen_base(nb, 10);
	if (nb == 0 && arg->precis == 0 && arg->val_prec == 1)
		ret = 0;
	(arg->precis < ret) ? arg->precis = ret : 0;
	(arg->field < arg->precis) ? arg->field = arg->precis : 0;
	if (!arg->val_minus && arg->val_field && (arg->val_prec || !arg->val_z))
		ft_printnchar(arg->field - arg->precis, ' ');
	if (!arg->val_minus && arg->val_z && arg->val_prec == 0)
		ft_printnchar(arg->field - arg->precis, '0');
	ft_printnchar(arg->precis - ret, '0');
	if (ret != 0)
		ft_putbase(nb, 10, arg->type);
	(arg->val_minus == 1) ? ft_printnchar(arg->field - arg->precis, ' ') : 0;
	return (ft_retfield(arg, ret));
}
