/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:37:47 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 13:09:38 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		process(char *str, int len)
{
	int				result;
	int				multiplicateur;

	result = 0;
	multiplicateur = 1;
	while (len >= 0)
	{
		if (str[len] == '+')
			return (result);
		if (str[len] == '-')
			result *= -1;
		else
			result += (str[len] - '0') * multiplicateur;
		multiplicateur *= 10;
		len--;
	}
	return (result);
}

int				ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		len;
	int		result;

	i = 0;
	len = 0;
	if (!(s = ft_strtrim(str)))
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i + len]))
		len++;
	result = process(s, len - 1 + i);
	free(s);
	s = NULL;
	return (result);
}
