/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:10:48 by cjacques          #+#    #+#             */
/*   Updated: 2015/11/25 15:09:22 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length_src;
	size_t	length_dst;
	size_t	len;

	len = ft_strlen(src) + ft_strlen(dst);
	length_src = ft_strlen(src);
	length_dst = ft_strlen(dst);
	if (size > length_dst)
	{
		ft_strncat(dst, src, size - length_dst - 1);
		return (length_src + length_dst);
	}
	else
	{
		return (len - (length_dst - size));
	}
}
