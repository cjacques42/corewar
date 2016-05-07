/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:28:27 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/06 17:53:30 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_isspace(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int		ft_comment(int c)
{
	if (c == ';' || c == COMMENT_CHAR)
		return (1);
	return (0);
}

int		ft_empty(char *str)
{
	while (*str)
	{
		if (ft_comment(*str) == 1)
			return (1);
		if (ft_isspace(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
