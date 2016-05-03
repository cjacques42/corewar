/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:59:02 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/20 16:24:46 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	else if (wchar <= 0x7FF)
		return (2);
	else if (wchar <= 0xFFFF)
		return (3);
	else if (wchar <= 0x1FFFFF)
		return (4);
	else
		return (0);
}
