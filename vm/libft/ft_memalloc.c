/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:14:42 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/26 14:35:37 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*result;
	unsigned int	i;

	i = 0;
	if (!(result = malloc(size)))
		return (NULL);
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
