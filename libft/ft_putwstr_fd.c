/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <cjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:23:25 by cjacques          #+#    #+#             */
/*   Updated: 2016/01/13 17:29:43 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr_fd(wchar_t *wstr, int fd)
{
	int		i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar_fd(wstr[i], fd);
		i++;
	}
}
