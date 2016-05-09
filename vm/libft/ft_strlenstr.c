/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:28:04 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/11 11:51:07 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlenstr(const char *s, const char *find)
{
	size_t			len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (s[len])
	{
		if (s[len] == find[i])
		{
			i++;
			if (!find[i])
				return (len - 1);
		}
		else
			i = 0;
		len++;
	}
	return (len);
}
