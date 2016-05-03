/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:13:03 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/20 16:27:00 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int				ft_print_hex(va_list *list_args, t_args *arg)
{
	uintmax_t	nb;
	int			ret;

	nb = ft_cast_unsigned(list_args, arg);
	ret = ft_nbrlen_base(nb, 16);
	(nb == 0 && arg->precis == 0 && arg->val_prec == 1) ? ret = 0 : 0;
	if ((arg->type == 'x' || arg->type == 'X') && arg->val_ht && nb > 0)
		arg->field -= 2;
	(arg->precis < ret) ? arg->precis = ret : 0;
	(arg->field < arg->precis) ? arg->field = arg->precis : 0;
	if (!arg->val_minus && arg->val_field && (arg->val_prec || !arg->val_z))
		ft_printnchar(arg->field - arg->precis, ' ');
	(arg->type == 'x' && arg->val_ht && nb > 0) ? ft_putstr("0x") : 0;
	(arg->type == 'X' && arg->val_ht && nb > 0) ? ft_putstr("0X") : 0;
	if (!arg->val_minus && arg->val_z && arg->val_prec == 0)
		ft_printnchar(arg->field - arg->precis, '0');
	ft_printnchar(arg->precis - ret, '0');
	if (ret != 0)
		ft_putbase(nb, 16, arg->type);
	(arg->val_minus == 1) ? ft_printnchar(arg->field - arg->precis, ' ') : 0;
	arg->field -= (nb == 0 && arg->val_ht == 1) ? 2 : 0;
	return (ft_retfield(arg, ret));
}
