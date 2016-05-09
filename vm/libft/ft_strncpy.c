/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:06:02 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 22:41:54 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	char			a;

	i = 0;
	a = 0;
	while (i < n)
	{
		if (!src[i])
			a = 1;
		if (a)
			dst[i] = 0;
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
