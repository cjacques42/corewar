/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:24:20 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 14:37:06 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*is1;
	unsigned char	*is2;

	is1 = (unsigned char*)s1;
	is2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (is1[i] - is2[i] != 0)
			return (is1[i] - is2[i]);
		i++;
	}
	return (0);
}
