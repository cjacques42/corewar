/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:45:45 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 15:28:21 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		g_end_sp(char const *s)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (ft_isspace(s[i]))
		i++;
	while (s[i])
		i++;
	i--;
	while (ft_isspace(s[i]))
	{
		i--;
		space++;
	}
	return (space);
}

static int		g_sp(char const *s)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (ft_isspace(s[i]))
	{
		space++;
		i++;
	}
	if (!s[i])
		return (ft_strlen(s));
	while (s[i])
		i++;
	i--;
	space += g_end_sp(s);
	return (space);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1 - g_sp(s)))))
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == 0)
	{
		result[0] = 0;
		return (result);
	}
	while (s[i + g_end_sp(s)])
	{
		result[j] = s[i];
		j++;
		i++;
	}
	result[j] = 0;
	return (result);
}
