/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:28:27 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/10 17:18:13 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		read_line(int fd, char **line)
{
	int		ret;
	char	*tmp;

	ret = get_next_line(fd, line);
	if (ret > 0)
	{
		g_data.line++;
		tmp = *line;
		*line = ft_strtrim(*line);
		free(tmp);
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
}
