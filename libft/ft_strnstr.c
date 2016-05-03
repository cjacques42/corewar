/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:07:09 by cjacques          #+#    #+#             */
/*   Updated: 2015/11/30 16:36:08 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s2);
	if (n < length)
		return (NULL);
	while (i <= ft_strlen(s1) - length && i <= n - length && s1[i])
	{
		if (ft_strncmp(&s1[i], &s2[0], length) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
