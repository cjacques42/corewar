/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:56:26 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 18:10:04 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int				ft_print_oct(va_list *list_args, t_args *arg)
{
	uintmax_t		nb;
	int				ret;

	(arg->type == 'O') ? nb = va_arg(*list_args, unsigned long) : 0;
	(arg->type == 'o') ? nb = ft_cast_unsigned(list_args, arg) : 0;
	ret = ft_nbrlen_base(nb, 8);
	(nb == 0 && arg->precis == 0 && arg->val_prec == 1) ? ret = 0 : 0;
	arg->precis -= (arg->val_ht) ? 1 : 0;
	(arg->precis < ret) ? arg->precis = ret : 0;
	(arg->field < arg->precis) ? arg->field = arg->precis : 0;
	arg->field -= (arg->val_ht) ? 1 : 0;
	if (!arg->val_minus && arg->val_field && (arg->val_prec || !arg->val_z))
		ft_printnchar(arg->field - arg->precis, ' ');
	if (arg->val_ht && (arg->val_field || arg->val_prec || nb > 0))
		ft_putstr("0");
	if (!arg->val_minus && arg->val_z && arg->val_prec == 0)
		ft_printnchar(arg->field - arg->precis, '0');
	ft_printnchar(arg->precis - ret, '0');
	if (ret != 0)
		ft_putbase(nb, 8, arg->type);
	(arg->val_minus == 1) ? ft_printnchar(arg->field - arg->precis, ' ') : 0;
	arg->field = (!arg->val_field) ? arg->precis : arg->field;
	if (nb == 0 && !arg->val_field && !arg->val_prec && arg->val_ht)
		arg->field = 0;
	return (ft_retfield(arg, ret));
}
