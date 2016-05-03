/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:45:42 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 18:23:38 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

uintmax_t		ft_cast_unsigned(va_list *list_args, t_args *arg)
{
	if (ft_strcmp(arg->conv, "hh\0") == 0)
		return ((unsigned char)va_arg(*list_args, uintmax_t));
	else if (ft_strcmp(arg->conv, "h\0") == 0)
		return ((unsigned short)va_arg(*list_args, uintmax_t));
	else if (ft_strcmp(arg->conv, "l\0") == 0)
		return ((unsigned long)va_arg(*list_args, uintmax_t));
	else if (ft_strcmp(arg->conv, "ll\0") == 0)
		return ((unsigned long long)va_arg(*list_args, uintmax_t));
	else if (ft_strcmp(arg->conv, "j\0") == 0)
		return (va_arg(*list_args, uintmax_t));
	else if (ft_strcmp(arg->conv, "z\0") == 0)
		return ((size_t)va_arg(*list_args, uintmax_t));
	else if (ft_strcmp(arg->conv, "\0") == 0)
		return ((unsigned int)va_arg(*list_args, uintmax_t));
	else
		return (va_arg(*list_args, uintmax_t));
}
