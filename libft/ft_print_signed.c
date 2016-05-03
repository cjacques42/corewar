/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:04:10 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 18:23:42 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static intmax_t	ft_cast_type_dec(va_list *list_args, t_args *arg)
{
	if (ft_strcmp(arg->conv, "hh\0") == 0)
		return ((signed char)va_arg(*list_args, intmax_t));
	else if (ft_strcmp(arg->conv, "h\0") == 0)
		return ((short)va_arg(*list_args, intmax_t));
	else if (ft_strcmp(arg->conv, "l\0") == 0)
		return ((long)va_arg(*list_args, intmax_t));
	else if (ft_strcmp(arg->conv, "ll\0") == 0)
		return ((long long)va_arg(*list_args, intmax_t));
	else if (ft_strcmp(arg->conv, "j\0") == 0)
		return (va_arg(*list_args, intmax_t));
	else if (ft_strcmp(arg->conv, "z\0") == 0)
		return ((long)va_arg(*list_args, intmax_t));
	else if (ft_strcmp(arg->conv, "\0") == 0)
		return ((int)va_arg(*list_args, intmax_t));
	else
		return (va_arg(*list_args, intmax_t));
}

static void		ft_print_dec(intmax_t nb)
{
	signed char	sign;

	sign = 1;
	if (nb < 0)
		sign = -1;
	if (nb > 9 || nb < -9)
		ft_print_dec(nb / 10);
	ft_putchar((nb % 10) * sign + '0');
}

static void		ft_before(t_args *arg, int ret, intmax_t nb, int zero)
{
	if (arg->val_plus || arg->val_sp)
		arg->field -= 1;
	if (nb < 0 && !arg->val_sp && !arg->val_plus)
		arg->field -= 1;
	(arg->precis < ret) ? arg->precis = ret : 0;
	(arg->field < arg->precis) ? arg->field = arg->precis : 0;
	if (!arg->val_minus && arg->val_field && (arg->val_prec || !arg->val_z))
		ft_printnchar((zero) ? arg->field - arg->precis + 1 :
				arg->field - arg->precis, ' ');
	if (arg->val_plus && nb >= 0)
		ft_putstr("+");
	else if (nb >= 0 && arg->val_sp)
		ft_putchar(' ');
	(nb < 0) ? ft_putchar('-') : 0;
	if (arg->val_minus == 0 && arg->val_z == 1 && arg->val_prec == 0)
		ft_printnchar(arg->field - arg->precis, '0');
	ft_printnchar(arg->precis - ret, '0');
}

int				ft_print_signed(va_list *list_args, t_args *arg)
{
	intmax_t	nb;
	int			ret;
	int			zero;

	if (arg->type == 'i' || arg->type == 'd')
		nb = ft_cast_type_dec(list_args, arg);
	else
		nb = va_arg(*list_args, long);
	zero = (!arg->precis && arg->val_prec && nb == 0) ? 1 : 0;
	ret = ft_nbrlen(nb);
	ft_before(arg, ret, nb, zero);
	(zero == 0) ? ft_print_dec(nb) : 0;
	arg->field -= (zero == 1 && !arg->val_field) ? 1 : 0;
	(arg->val_minus == 1) ? ft_printnchar(arg->field - arg->precis, ' ') : 0;
	arg->field += (nb < 0 && !arg->val_sp && !arg->val_plus) ? 1 : 0;
	return (ft_retfield(arg, (zero) ? 0 : ret));
}
