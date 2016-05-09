/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:55:51 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/26 19:24:16 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i + 1 != 0)
		{
			dst2[i] = src2[i];
			i--;
		}
	}
	return (dst);
}
