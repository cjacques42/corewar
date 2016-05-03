/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:49:15 by cjacques          #+#    #+#             */
/*   Updated: 2015/11/30 15:25:10 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	size_t		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	end = len;
	while ((s[start] == ' ' || s[start] == '\t'
				|| s[start] == '\n') && s[start])
		start++;
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n' || s[end] == '\0')
		end--;
	end++;
	if (start == len)
		return (ft_strdup("\0"));
	if (len - end != 0 && start != 0)
		return (ft_strsub(s, start, end - start));
	else
		return (ft_strdup(s));
}
