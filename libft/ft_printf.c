/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:30:10 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 16:26:55 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "utils.h"

int		ft_parse(const char **format, t_args *arg)
{
	ft_memset(arg, 0, sizeof(*arg));
	while (ft_isdigit(**format) || **format == ' ' || **format == '-' ||
			**format == '+' || **format == '#' || **format == 'h' ||
			**format == 'l' || **format == 'j' || **format == 'z' ||
			**format == '.')
	{
		ft_extract_options(format, arg);
		if (**format == 0)
			return (0);
		if (**format >= '1' && **format <= '9')
			arg->field = ft_extract_field(format, arg);
		if (**format == 0)
			return (0);
		if (**format == '.')
			arg->precis = ft_extract_precis(format, arg);
		if (**format == 0)
			return (0);
		if (**format == 'h' || **format == 'l' || **format == 'j' ||
				**format == 'z')
			ft_extract_conv(format, arg);
		if (**format == 0)
			return (0);
	}
	return (1);
}

int		ft_checktype(const char **format, va_list *list_args)
{
	t_args	arg;
	char	type;

	if (*(++*format) == '\0')
		return (0);
	if (ft_parse(format, &arg) == 0)
		return (0);
	if (ft_searchtype(*format, &type) == -1)
	{
		if (arg.val_field == 1 && arg.val_minus == 0)
			ft_printnchar(arg.field - 1, (arg.val_z) ? '0' : ' ');
		ft_putchar(*((*format)++));
		if (arg.val_field == 1 && arg.val_minus == 1)
			ft_printnchar(arg.field - 1, ' ');
		return (ft_retfield(&arg, 1));
	}
	else
	{
		(*format)++;
		arg.type = type;
		return (ft_call_print(list_args, &arg));
	}
}

int		ft_searchtype(const char *format, char *type)
{
	char	str_type[16];
	char	*str;

	ft_strcpy(str_type, "sSpdDioOuUxXcC%\0");
	if ((str = ft_strchr(str_type, *format)) == NULL)
		return (-1);
	else
	{
		*type = *str;
		return (0);
	}
}

int		ft_ft(const char *format, va_list *list_args, int nb_char)
{
	char	*first_arg;
	int		ret;

	ret = 0;
	first_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (nb_char);
	else if (first_arg == NULL)
	{
		ft_putstr(format);
		return (nb_char + ft_strlen(format));
	}
	else if ((*format) == '%')
	{
		if ((ret = ft_checktype(&format, list_args)) == -1)
			return (-1);
		else
			return (ft_ft(format, list_args, nb_char + ret));
	}
	else
	{
		write(1, format, first_arg - format);
		return (ft_ft(first_arg, list_args, nb_char + (first_arg - format)));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		list_args;
	int			len;

	va_start(list_args, format);
	len = ft_ft(format, &list_args, 0);
	va_end(list_args);
	return (len);
}
