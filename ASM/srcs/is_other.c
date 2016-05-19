/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 10:56:24 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 11:02:41 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_end(t_token *token, char **line, int fd, char **str)
{
	(void)str;
	(void)fd;
	if (**line == 0 || ft_comment(**line) == 1)
	{
		*token = ENDLINE;
		*line = NULL;
		return (1);
	}
	return (0);
}

int			is_selector(t_token *token, char **line, int fd, char **str)
{
	(void)fd;
	if (**line == SEPARATOR_CHAR)
	{
		(*line)++;
		*token = SEPARATOR;
		*str = ft_strdup(",");
		return (1);
	}
	return (0);
}

int			is_string(t_token *token, char **line, int fd, char **str)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	if (**line == '"')
	{
		i = 1;
		while ((*line)[i] != '"')
		{
			if ((*line)[i] == 0)
			{
				i = 0;
				if (*str == NULL)
					*str = ft_strdup(*line);
				else
					*str = ft_freejoin(*str, *line, 1, 0);
				if (read_line(fd, &tmp, line) < 1)
					return (1);
				*str = ft_freejoin(*str, "\n", 1, 0);
			}
			i++;
		}
		if ((*line)[i] == '"')
		{
			if (*str == NULL)
			{
				*str = ft_strsub(*line, 0, i + 1);
				*line += i + 1;
			}
			else
			{
				tmp = *line;
				*str = ft_freejoin(*str, ft_strsub(*line, 0, i + 1), 1, 1);
				*line = ft_strdup((*line) + i + 1);
				free(tmp);
			}
			*token = STRING;
		}
		return (i + 1);
	}
	return (0);
}

int			is_instru(t_token *token, char **line, int fd, char **str)
{
	int		i;
	int		size;

	(void)fd;
	i = 0;
	size = 0;
	while ((*line)[i] && !ft_isspace((*line)[i])
			&& !ft_comment((*line)[i]) && (*line)[i] != '"'
			&& (*line)[i] != SEPARATOR_CHAR && (*line)[i] != DIRECT_CHAR)
		i++;
	*str = ft_strsub(*line, 0, i);
	while (g_op_tab[size].label != NULL)
	{
		if (ft_strcmp(g_op_tab[size].label, *str) == 0)
		{
			*token = INSTRUCTION;
			*line += i;
			return (i);
		}
		size++;
	}
	free(*str);
	*str = NULL;
	return (0);
}

int			is_command(t_token *token, char **line, int fd, char **str)
{
	int		len;

	(void)fd;
	len = ft_strlen(NAME_CMD_STRING);
	if (ft_strncmp(*line, NAME_CMD_STRING, len) == 0)
	{
		*str = ft_strsub(*line, 0, len);
		*token = COMMAND_NAME;
		*line += len;
		return (len);
	}
	len = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strncmp(*line, COMMENT_CMD_STRING, len) == 0)
	{
		*str = ft_strsub(*line, 0, len);
		*token = COMMAND_COMMENT;
		*line += len;
		return (len);
	}
	return (0);
}
