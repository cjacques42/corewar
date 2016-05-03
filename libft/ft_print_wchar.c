/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:14:28 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 17:14:30 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int		ft_print_wchar(va_list *list_args, t_args *arg)
{
	wchar_t		wchar;

	wchar = (wchar_t)va_arg(*list_args, wint_t);
	ft_memset(arg->conv, '\0', 3);
	if (arg->val_field && !arg->val_minus && arg->val_z)
		ft_printnchar(arg->field - ft_wcharlen(wchar), '0');
	if (arg->val_field && !arg->val_minus && !arg->val_z)
		ft_printnchar(arg->field - ft_wcharlen(wchar), ' ');
	ft_putwchar(wchar);
	if (arg->val_field == 1 && arg->val_minus == 1)
		ft_printnchar(arg->field - ft_wcharlen(wchar), ' ');
	return (ft_retfield(arg, ft_wcharlen(wchar)));
}
