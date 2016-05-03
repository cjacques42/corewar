/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:33:08 by cjacques          #+#    #+#             */
/*   Updated: 2015/12/14 10:38:04 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	intlen(int n)
{
	int		len;

	len = 1;
	if (n < 0)
		len++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	int		neg;

	neg = 0;
	len = intlen(n);
	if (!(ptr = (char *)malloc(sizeof(ptr) * (len + 1))))
		return (NULL);
	ft_memset(ptr, '0', len);
	if (n < 0)
		neg = 1;
	ptr[len] = '\0';
	len--;
	while ((neg == 0 && len >= 0) || (neg == 1 && len > 0))
	{
		if (neg == 0)
			ptr[len] = n % 10 + 48;
		else
			ptr[len] = -(n % 10) + 48;
		n = n / 10;
		len--;
	}
	if (neg == 1)
		ptr[0] = '-';
	return (ptr);
}
