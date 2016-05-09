/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:42:25 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 14:51:03 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*result;
	unsigned int		i;
	int					j;

	if (!s)
		return (NULL);
	j = 0;
	i = start;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > 0)
	{
		result[j] = s[i];
		j++;
		i++;
		len--;
	}
	result[j] = 0;
	return (result);
}
