/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:17:11 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/15 11:56:24 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_printnchar(size_t len, char c)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
}
