/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:27:27 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/28 13:58:53 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ABS(x) (x < 0) ? (-(x)) : (x)

static int		size_calcul(int nbr)
{
	int		index;

	index = 1;
	if (nbr < 0)
		index++;
	while ((nbr = nbr / 10) != 0)
		index++;
	return (index);
}

static char		*ft_itoa_10(int nbr)
{
	char	*convert;
	int		size;

	size = (size_calcul(nbr));
	if ((convert = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	convert[size] = '\0';
	size--;
	if ((nbr = ABS(nbr)) == 0)
	{
		convert[size] = '0';
		size--;
	}
	while (nbr != 0)
	{
		convert[size] = (nbr % 10) + '0';
		nbr = nbr / 10;
		size--;
	}
	if (size == 0)
		convert[size] = '-';
	return (convert);
}

char			*ft_itoa(int n)
{
	char	*ret;

	if (n == -2147483648)
	{
		ret = ft_strdup("-2147483648");
		return (ret);
	}
	ret = ft_itoa_10(n);
	return (ret);
}
