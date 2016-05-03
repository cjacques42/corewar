/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:33:37 by cjacques          #+#    #+#             */
/*   Updated: 2015/11/25 13:07:31 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	length;

	length = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i])
	{
		s1[length] = s2[i];
		i++;
		length++;
	}
	s1[length] = '\0';
	return (s1);
}
