/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 10:54:41 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 15:30:40 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_direct_token(char **line, int *i, char **str, t_token *token)
{
	int		index;

	index = *i;
	if ((*line)[1] == LABEL_CHAR)
		while ((*line)[*i] && ft_strchr(LABEL_CHARS, (*line)[*i]) != NULL)
			(*i)++;
	else
		while (ft_isdigit((*line)[*i]) == 1)
			(*i)++;
	if (!(*line)[*i] || ft_isspace((*line)[*i]) || ft_comment((*line)[*i])
			|| (*line)[*i] == '"' || (*line)[*i] == SEPARATOR_CHAR
			|| (*line)[*i] == DIRECT_CHAR)
	{
		if (index == *i)
			return (0);
		*str = ft_strsub(*line, 0, *i);
		if ((*line)[1] == LABEL_CHAR)
			*token = DIRECT_LABEL;
		else
			*token = DIRECT;
		*line += *i;
		return (*i);
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
			return (ft_direct_token(line, &i, str, token));
		}
		else if (ft_isdigit((*line)[i]) == 1 || (*line)[i] == '-')
		{
			if ((*line)[i] == '-')
				i++;
			return (ft_direct_token(line, &i, str, token));
		}
	}
	return (0);
}

static int	ft_indirect_token(char **line, int *i, char **str, t_token *token)
{
	int		index;

	index = *i;
	if ((*line)[0] == LABEL_CHAR)
		while ((*line)[*i] && ft_strchr(LABEL_CHARS, (*line)[*i]) != NULL)
			(*i)++;
	else
		while (ft_isdigit((*line)[*i]) == 1)
			(*i)++;
	if (!(*line)[*i] || ft_isspace((*line)[*i]) || ft_comment((*line)[*i])
			|| (*line)[*i] == '"' || (*line)[*i] == SEPARATOR_CHAR
			|| (*line)[*i] == DIRECT_CHAR)
	{
		if (index == *i)
			return (0);
		*str = ft_strsub(*line, 0, *i);
		if ((*line)[0] == LABEL_CHAR)
			*token = INDIRECT_LABEL;
		else
			*token = INDIRECT;
		*line += *i;
		return (*i);
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
		return (ft_indirect_token(line, &i, str, token));
	}
	else if (ft_isdigit((*line)[i]) == 1 || (*line)[i] == '-')
	{
		if ((*line)[i] == '-')
			i++;
		return (ft_indirect_token(line, &i, str, token));
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
				return (i);
			}
		}
		return (0);
	}
	return (0);
}
