/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:43:45 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 16:51:34 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static wchar_t		*ft_wstrdup(wchar_t *wstr)
{
	size_t	i;
	size_t	j;
	wchar_t	*dest;

	i = 0;
	j = 0;
	if (wstr == NULL)
		return (NULL);
	while (wstr[i])
		i++;
	dest = (wchar_t *)malloc(sizeof(*wstr) * (i + 1));
	while (wstr[j])
	{
		dest[j] = wstr[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

static size_t		ft_putnwstr(wchar_t *wstr, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < n)
	{
		i += ft_wcharlen(wstr[j]);
		if (i <= n)
			ft_putwchar(wstr[j]);
		j++;
	}
	return (i);
}

static size_t		ft_ret_nwstr(wchar_t *wstr, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= n)
	{
		i += ft_wcharlen(wstr[j]);
		j++;
	}
	i -= ft_wcharlen(wstr[--j]);
	return (i);
}

static int			ft_ret_wstr(t_args *arg, wchar_t *wstr)
{
	int		ret;

	ret = ft_ret_nwstr(wstr, arg->precis);
	if (arg->field > arg->precis)
	{
		if (arg->val_field && !arg->val_minus && arg->val_z)
			ft_printnchar(arg->field - ret, '0');
		if (arg->val_field && !arg->val_minus && !arg->val_z)
		{
			if (arg->precis == 0)
				ft_printnchar(arg->field, ' ');
			else
				ft_printnchar(arg->field - ret, ' ');
		}
	}
	ret = ft_putnwstr(wstr, arg->precis);
	if (arg->val_field == 1 && arg->val_minus == 1)
		ft_printnchar(arg->field - arg->precis, ' ');
	(arg->val_field == 0) ? ret = ft_ret_nwstr(wstr, arg->precis) : 0;
	return (ret);
}

int					ft_print_wstr(va_list *list_args, t_args *arg)
{
	wchar_t	*wstr;
	int		ret;

	wstr = ft_wstrdup(va_arg(*list_args, wchar_t *));
	(wstr == NULL) ? wstr = ft_wstrdup(L"(null)") : 0;
	ret = ft_wstrlen(wstr);
	if (ret < arg->precis || arg->val_prec == 0)
	{
		if (ret > arg->precis || ret < arg->field)
		{
			if (arg->val_field && !arg->val_minus && arg->val_z)
				ft_printnchar(arg->field - ret, '0');
			if (arg->val_field && !arg->val_minus && !arg->val_z)
				ft_printnchar(arg->field - ret, ' ');
		}
		ft_putwstr(wstr);
		if (arg->val_field == 1 && arg->val_minus == 1)
			ft_printnchar(arg->field - ret, ' ');
	}
	else
		ret = ft_ret_wstr(arg, wstr);
	free(wstr);
	return (ft_retfield(arg, ret));
}
