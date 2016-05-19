/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:57:38 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 13:14:57 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				is_instru(t_token *token, char **line, int fd, char **str)
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

int				is_label(t_token *token, char **line, int fd, char **str)
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
		return (i + 1);
	}
	return (0);
}

static void		load_funct(int (**ptr_function)(t_token *token, char **line
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
}

static void		ft_col(t_token *token, char **line, int fd, char **str)
{
	int		i;
	int		index;
	int		(*ptr_function[10])(t_token *, char **, int, char **);

	i = 0;
	load_funct(ptr_function);
	while (i < 9)
		if ((index = (*ptr_function[i++])(token, line, fd, str)) >= 1)
		{
			g_data.col += index;
			return ;
		}
}

t_token			next_token(int fd, char **str)
{
	int				i;
	t_token			token;
	static char		*line = NULL;
	static char		*tmp = NULL;

	i = 0;
	*str = NULL;
	token = NONE;
	if (line == NULL)
		if (read_line(fd, &tmp, &line) < 1)
		{
			*str = ft_strdup("(null)");
			return (END);
		}
	line = ft_beg_trim(line);
	ft_col(&token, &line, fd, str);
	if ((token == STRING && ft_strchr(*str, '\n') != NULL) || (token == NONE))
		free(tmp);
	if (token == STRING && ft_strchr(*str, '\n') != NULL)
		tmp = line;
	if (token == NONE)
		ft_lexixal_error();
	return (token);
}
