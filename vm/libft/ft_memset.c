/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:35:56 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 14:15:33 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)b;
	while (len > 0)
	{
		dst[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
