/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:41:39 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 17:19:48 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *s, size_t n)
{
	unsigned char	*result;
	unsigned char	*src;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(result = (unsigned char *)malloc(n)))
		return (NULL);
	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		result[i] = src[i];
		i++;
	}
	return (result);
}
