/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 09:56:04 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/14 13:05:56 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t		len;
	size_t		i;

	len = 0;
	i = 0;
	while (wstr[i])
	{
		len += ft_wcharlen(wstr[i]);
		i++;
	}
	return (len);
}
