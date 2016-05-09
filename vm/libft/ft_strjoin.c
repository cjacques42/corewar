/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:37:14 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/27 14:51:38 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len_s1;
	int		len_s2;
	int		len_result;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))) == NULL)
		return (NULL);
	len_result = 0;
	while (len_s1 > 0)
	{
		result[len_result] = s1[len_result];
		len_s1--;
		len_result++;
	}
	while (len_s1 < len_s2)
	{
		result[len_result + len_s1] = s2[len_s1];
		len_s1++;
	}
	result[len_result + len_s1] = 0;
	return (result);
}
