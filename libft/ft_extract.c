/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:26:12 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/21 18:26:11 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_extract_options(const char **format, t_args *arg)
{
	int		j;

	j = 0;
	while (**format == ' ' || **format == '-' || **format == '+'
			|| **format == '0' || **format == '#')
	{
		(**format == '#') ? arg->val_ht = 1 : 0;
		(**format == '0') ? arg->val_z = 1 : 0;
		(**format == '-') ? arg->val_minus = 1 : 0;
		(**format == '+') ? arg->val_plus = 1 : 0;
		(**format == ' ') ? arg->val_sp = 1 : 0;
		if (*(++(*format)) == 0)
			return ;
	}
}

int		ft_extract_field(const char **format, t_args *arg)
{
	int		total;

	total = 0;
	if (**format >= '1' && **format <= '9')
	{
		total = ft_atoi(*format);
		arg->val_field = 1;
		(*format) += ft_nbrlen(total);
	}
	return (total);
}

int		ft_extract_precis(const char **format, t_args *arg)
{
	int		total;

	total = 0;
	if (**format == '.')
	{
		arg->val_prec = 1;
		(*format)++;
	}
	else
		return (total);
	if (**format >= '0' && **format <= '9')
	{
		total = ft_atoi(*format);
		(*format) += ft_nbrlen(total);
	}
	return (total);
}

void	ft_extract_conv(const char **format, t_args *arg)
{
	int		j;

	j = 0;
	ft_memset(arg->conv, 0, 3);
	while ((**format == 'h' || **format == 'l' || **format == 'j'
			|| **format == 'z') && j < 2)
	{
		arg->conv[j++] = **format;
		arg->val_conv = 1;
		if (*(++(*format)) == 0)
			return ;
	}
}
