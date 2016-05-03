/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:46:55 by cjacques          #+#    #+#             */
/*   Updated: 2015/11/30 09:24:37 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = len;
	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst == src)
		return (dst);
	else
		while (i > 0)
		{
			str2[i - 1] = str1[i - 1];
			i--;
		}
	return (dst);
}
