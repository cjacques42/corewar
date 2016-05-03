/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:04:41 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/13 17:33:42 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wchar_t wchar, int fd)
{
	if (wchar <= 0x7F)
		ft_putchar_fd(wchar, fd);
	else if (wchar <= 0x7FF)
	{
		ft_putchar_fd(((wchar >> 6) & 0x1F) | 0xC0, fd);
		ft_putchar_fd((wchar & 0x3F) | 0x80, fd);
	}
	else if (wchar <= 0xFFFF)
	{
		ft_putchar_fd(((wchar >> 12) & 0xF) | 0xE0, fd);
		ft_putchar_fd(((wchar >> 6) & 0x3F) | 0x80, fd);
		ft_putchar_fd((wchar & 0x3F) | 0x80, fd);
	}
	else if (wchar <= 0x1FFFFF)
	{
		ft_putchar_fd(((wchar >> 18) & 0x7) | 0xF0, fd);
		ft_putchar_fd(((wchar >> 12) & 0x3F) | 0x80, fd);
		ft_putchar_fd(((wchar >> 6) & 0x3F) | 0x80, fd);
		ft_putchar_fd((wchar & 0x3F) | 0x80, fd);
	}
}
