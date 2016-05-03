/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:40:15 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/19 13:47:04 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void		ft_putbase(uintmax_t nb, unsigned int base, char type)
{
	signed char		add;

	add = (type == 'x' || type == 'p') ? 87 : 55;
	if (nb >= base)
		ft_putbase(nb / base, base, type);
	if (nb % base > 9)
		ft_putchar(nb % base + add);
	else
		ft_putchar(nb % base + '0');
}
