/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:15:02 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/25 13:35:36 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*result;

	if ((result = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (size > 0)
	{
		result[size] = 0;
		size--;
	}
	result[size] = 0;
	return (result);
}
