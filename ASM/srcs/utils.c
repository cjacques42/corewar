/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:28:27 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 10:50:41 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_beg_trim(char *str)
{
	int			index;

	index = 0;
	while ((str[index] == ' ' || str[index] == '\t'
		|| str[index] == '\n') && str[index])
	{
		index++;
		if (str[index] == '\t')
			g_data.col += 4;
		else
			g_data.col += 1;
	}
	return (str + index);
}

int		read_line(int fd, char **tmp, char **line)
{
	int			ret;

	free(*tmp);
	ret = get_next_line(fd, tmp);
	if (ret > 0)
	{
		g_data.line++;
		*line = *tmp;
	}
	return (ret);
}

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

char	*ft_freejoin(char *s1, char *s2, int arg1, int arg2)
{
	char		*ptr;

	ptr = ft_strjoin(s1, s2);
	if (arg1 == 1)
		free(s1);
	if (arg2 == 1)
		free(s2);
	return (ptr);
}
