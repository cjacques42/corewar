/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:47:59 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/03 16:09:59 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	char	*swap;
	int		i;
	int		j;

	if (!(swap = (char *)malloc(sizeof(char) * (ft_strlen(s)))))
		return ;
	ft_strcpy(swap, s);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i])
	{
		s[i] = swap[j];
		j--;
		i++;
	}
	free(swap);
	swap = NULL;
}
