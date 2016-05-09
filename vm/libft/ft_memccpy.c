/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:33:24 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 22:30:44 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dst2;
	unsigned int	i;
	unsigned char	car;

	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	car = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (dst2[i] == car)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
