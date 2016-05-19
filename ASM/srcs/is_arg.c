/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 10:54:41 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 11:02:42 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
		return (i + 1);
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
				return (i);
			}
		}
		else if (ft_isdigit((*line)[i]) == 1 || (*line)[i] == '-')
		{
			i++;
			while (ft_isdigit((*line)[i]) == 1)
				i++;
			if (!(*line)[i] || ft_isspace((*line)[i]) || ft_comment((*line)[i])
					|| (*line)[i] == '"' || (*line)[i] == SEPARATOR_CHAR
					|| (*line)[i] == DIRECT_CHAR)
			{
				*str = ft_strsub(*line, 0, i);
				*line += i;
				*token = DIRECT;
				return (i);
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
			return (i);
		}
	}
	else if (ft_isdigit((*line)[i]) == 1 || (*line)[i] == '-')
	{
		i++;
		while (ft_isdigit((*line)[i]) == 1)
			i++;
		if (!(*line)[i] || ft_isspace((*line)[i]) || ft_comment((*line)[i])
				|| (*line)[i] == '"' || (*line)[i] == SEPARATOR_CHAR
				|| (*line)[i] == DIRECT_CHAR)
		{
			*str = ft_strsub(*line, 0, i);
			*line += i;
			*token = INDIRECT;
			return (i);
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
				return (i);
			}
		}
		return (0);
	}
	return (0);
}
