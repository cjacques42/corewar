/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:42:31 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 14:32:28 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	car;
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)s;
	car = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == car)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
