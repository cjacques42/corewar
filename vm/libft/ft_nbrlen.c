/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:23:51 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/22 13:27:41 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	process(long nb, int base)
{
	int		val;

	val = 0;
	if (nb >= base)
	{
		val += process(nb / base, base);
		val += process(nb % base, base);
	}
	else
		val++;
	return (val);
}

int			ft_nbrlen(long nbr, int base)
{
	char	neg;

	neg = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		neg++;
	}
	return (process(nbr, base) + neg);
}
