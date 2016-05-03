/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:38:47 by cjacques          #+#    #+#             */
/*   Updated: 2015/12/08 16:42:42 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	neg;

	neg = 1;
	if (n < 0)
		neg = -1;
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10, fd);
	if (neg == -1 && n <= 0 && n >= -9)
		ft_putchar_fd('-', fd);
	ft_putchar_fd((n % 10) * neg + '0', fd);
}
