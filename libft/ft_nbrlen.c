/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:16:38 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/15 11:49:34 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t		ft_nbrlen(intmax_t nbr)
{
	size_t		len;

	len = 1;
	while (nbr > 9 || nbr < -9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

size_t		ft_nbrlen_base(uintmax_t nbr, unsigned int base)
{
	size_t		len;

	len = 1;
	while (nbr >= base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
