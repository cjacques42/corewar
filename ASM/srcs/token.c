/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:57:38 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/17 12:24:50 by cjacques         ###   ########.fr       */
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
					*str = ft_strjoin(*str, *line);
				if (get_next_line(fd, line) < 1)
					ft_puterr("Lexical error");
				*str = ft_strjoin(*str, "\n");
			}
			i++;
		}
		if ((*line)[i] == '"')
		{
			if (*str == NULL)
				*str = ft_strsub(*line, 0, i + 1);
			else
				*str = ft_strjoin(*str, ft_strsub(*line, 0, i + 1));
			*line += i + 1;
			*token = STRING;
			return (1);
		}
		ft_puterr("Lexical error");
	}
	return (0);
}

int			is_instru(t_token *token, char **line, int fd, char **str)
{
	int		i;
	int		len;

	(void)fd;
	i = 0;
	while (g_op_tab[i].label != NULL)
	{
		len = ft_strlen(g_op_tab[i].label);
		if (ft_strncmp(g_op_tab[i].label, *line, len) == 0
				&& ft_isspace((*line)[len]))
		{
			*token = INSTRUCTION;
			*str = ft_strsub(*line, 0, len);
			return (1);
		}
		i++;
	}
	return (0);
}

int			is_other(t_token *token, char **line, int fd, char **str)
{
	int		i;

	(void)token;
	(void)fd;
	i = 0;
	while ((*line)[i] && !ft_isspace((*line)[i])
			&& !ft_comment((*line)[i]) && (*line)[i] != '"'
			&& (*line)[i] != SEPARATOR_CHAR)
		i++;
	*str = ft_strsub(*line, 0, i);
	*line += i;
	return (1);
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
		return (1);
	}
	len = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strncmp(*line, COMMENT_CMD_STRING, len) == 0)
	{
		*str = ft_strsub(*line, 0, len);
		*token = COMMAND_COMMENT;
		*line += len;
		return (1);
	}
	return (0);
}

void		load_funct(int (**ptr_function)(t_token *token, char **line
		, int fd, char **str))
{
	ptr_function[0] = &is_end;
	ptr_function[1] = &is_selector;
	ptr_function[2] = &is_string;
	ptr_function[3] = &is_command;
	ptr_function[4] = &is_instru;
	ptr_function[4] = &is_other;
}

t_token		next_token(int fd, char **str)
{
	int				i;
	int				(*ptr_function[5])(t_token *, char **, int, char **);
	t_token			token;
	static char		*line = NULL;

	i = 0;
	*str = NULL;
	token = NONE;
	load_funct(ptr_function);
	if (line == NULL)
		if (get_next_line(fd, &line) < 1)
		{
			*str = ft_strdup("(null)");
			return (END);
		}
	line = ft_beg_trim(line);
	while (i < 5)
	{
		if ((*ptr_function[i])(&token, &line, fd, str) == 1)
			return (token);
		i++;
	}
	return (token);
}
