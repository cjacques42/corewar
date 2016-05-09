/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:58:56 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/26 16:07:33 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	if (!s2[i])
		return ((char *)s1);
	while (s1[i])
	{
		result = (char *)&s1[i];
		j = 0;
		while (s1[i + j] == s2[j])
		{
			j++;
			if (!s2[j])
				return (result);
		}
		i++;
	}
	return (0);
}
