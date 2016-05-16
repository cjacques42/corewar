/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:57:38 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/16 19:04:58 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		next_token(int fd, char **str)
{
	static	char	*tmp = NULL;
	char			*word;
	int				i;

	i = 0;
	*str = NULL;
	if (tmp == NULL)
	{
		
	}
	if (*word == 0)
	{
		return (ENDLINE);
	}
	if (tmp == NULL && get_next_line(fd, &tmp) < 1)
		return (END);
	word = ft_beg_trim(tmp);
	if (*word == 0)
	{
		tmp = NULL;
		return (ENDLINE);
	}
	if (*word == SEPARATOR_CHAR)
	{
		tmp = NULL;
		return (SEPARATOR);
	}
	if (*word == '"')
	{
		tmp = NULL;
		return (STRING);
	}
	while (tmp[i])
	{
		if (ft_separator(tmp[i]) == 1)
			break;
		i++;
	}
	*str = ft_strsub(tmp, 0, i);
	tmp += i;
	return (NONE);
}
