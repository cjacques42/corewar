/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:21:31 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/26 18:01:32 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int					dst_len;
	unsigned int		j;
	int					s;

	dst_len = ft_strlen(dst);
	s = size - dst_len;
	if (s <= 0)
		return (size + ft_strlen(src));
	j = 0;
	while (src[j] && j < (size - dst_len - 1))
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = 0;
	return (dst_len + (ft_strlen(src)));
}
