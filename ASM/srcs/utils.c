/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:28:27 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/18 11:15:21 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		read_line(int fd, char **tmp, char **line)
{
	int		ret;

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
/*
void	check_eol(char *line)
{
	while (*line)
	{
		if (ft_comment(*line) == 1)
			return ;
		if (ft_isspace(*line) != 1)
			ft_exit_mess(9);
		line++;
	}
}*/

int		ft_separator(char c)
{
	if (ft_isspace(c) || ft_comment(c) || c == SEPARATOR_CHAR || c == '"')
		return (1);
	return (0);
}
