/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:45:01 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/04 10:47:47 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		ft_search(char tmp, const char *sep)
{
	int		index;

	index = 0;
	while (sep[index])
	{
		if (sep[index] != tmp)
			index++;
		else
			break ;
	}
	return (sep[index]);
}

char			*ft_strtok(char *str, const char *sep)
{
	static char	*stock = NULL;
	char		*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		stock = str;
	while (*stock != '\0')
	{
		if (i == 0 && *stock != ft_search(*stock, sep))
		{
			i = 1;
			ptr = stock;
		}
		else if (i == 1 && *stock == ft_search(*stock, sep))
		{
			*stock = '\0';
			stock += 1;
			break ;
		}
		stock++;
	}
	return (ptr);
}
