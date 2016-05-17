/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:57:38 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/17 18:34:36 by cjacques         ###   ########.fr       */
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

int			is_label(t_token *token, char **line, int fd, char **str)
{
	int		i;

	(void)str;
	(void)fd;
	i = 0;
	while ((*line)[i] && ft_strchr(LABEL_CHARS, (*line)[i]) != NULL)
		i++;
	if (i > 0 && (*line)[i] == LABEL_CHAR)
	{
		*token = LABEL;
		*str = ft_strsub(*line, 0, i + 1);
		*line += i + 1;
		return (1);
	}
	return (0);
}

int			is_direct(t_token *token, char **line, int fd, char **str)
{
	int		i;

	i = 1;
	(void)fd;
	if (**line == DIRECT_CHAR)
	{
		if ((*line)[i] == LABEL_CHAR)
		{
			i++;
			while ((*line)[i] && ft_strchr(LABEL_CHARS, (*line)[i]) != NULL)
				i++;
			if (!(*line)[i] || ft_isspace((*line)[i]) || ft_comment((*line)[i])
					|| (*line)[i] == '"' || (*line)[i] == SEPARATOR_CHAR
					|| (*line)[i] == DIRECT_CHAR)
			{
				*str = ft_strsub(*line, 0, i);
				*line += i;
				*token = DIRECT_LABEL;
				return (1);
			}
		}
		else if (ft_isdigit((*line)[i]) == 1)
		{
			while (ft_isdigit((*line)[i]) == 1)
				i++;
			if (!(*line)[i] || ft_isspace((*line)[i]) || ft_comment((*line)[i])
					|| (*line)[i] == '"' || (*line)[i] == SEPARATOR_CHAR
					|| (*line)[i] == DIRECT_CHAR)
			{
				*str = ft_strsub(*line, 0, i);
				*line += i;
				*token = DIRECT;
				return (1);
			}
		}
	}
	return (0);
}

int			is_indirect(t_token *token, char **line, int fd, char **str)
{
	int		i;

	i = 0;
	(void)fd;
	if ((*line)[i] == LABEL_CHAR)
	{
		i++;
		while ((*line)[i] && ft_strchr(LABEL_CHARS, (*line)[i]) != NULL)
			i++;
		if (!(*line)[i] || ft_isspace((*line)[i]) || ft_comment((*line)[i])
				|| (*line)[i] == '"' || (*line)[i] == SEPARATOR_CHAR
				|| (*line)[i] == DIRECT_CHAR)
		{
			*str = ft_strsub(*line, 0, i);
			*line += i;
			*token = INDIRECT_LABEL;
			return (1);
		}
	}
	else if (ft_isdigit((*line)[i]) == 1)
	{
		while (ft_isdigit((*line)[i]) == 1)
			i++;
		if (!(*line)[i] || ft_isspace((*line)[i]) || ft_comment((*line)[i])
				|| (*line)[i] == '"' || (*line)[i] == SEPARATOR_CHAR
				|| (*line)[i] == DIRECT_CHAR)
		{
			*str = ft_strsub(*line, 0, i);
			*line += i;
			*token = INDIRECT;
			return (1);
		}
	}
	return (0);
}

int			is_reg(t_token *token, char **line, int fd, char **str)
{
	int		i;

	(void)fd;
	if (**line == 'r')
	{
		i = 1;
		if (ft_isdigit((*line)[i]) == 1)
		{
			while (ft_isdigit((*line)[i]) == 1)
				i++;
			if (!(*line)[i] || ft_isspace((*line)[i]) || ft_comment((*line)[i])
					|| (*line)[i] == '"' || (*line)[i] == SEPARATOR_CHAR
					|| (*line)[i] == DIRECT_CHAR)
			{
				*str = ft_strsub(*line, 0, i);
				*line += i;
				*token = REGISTER;
				return (1);
			}
		}
		return (0);
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
			return (1);
		}
		size++;
	}
	free(*str);
	*str = NULL;
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
	ptr_function[5] = &is_direct;
	ptr_function[6] = &is_indirect;
	ptr_function[7] = &is_label;
	ptr_function[8] = &is_reg;
	ptr_function[9] = &is_other;
}

t_token		next_token(int fd, char **str)
{
	int				i;
	int				(*ptr_function[10])(t_token *, char **, int, char **);
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
	while (i < 10)
		if ((*ptr_function[i++])(&token, &line, fd, str) == 1)
		{
			if (token == ENDLINE)
				g_data.line++;
			return (token);
		}
	return (token);
}
