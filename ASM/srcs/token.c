/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:57:38 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 11:25:02 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

t_token			next_token(int fd, char **str)
{
	int				i;
	int				index;
	int				(*ptr_function[10])(t_token *, char **, int, char **);
	t_token			token;
	static char		*line = NULL;
	static char		*tmp = NULL;

	i = 0;
	*str = NULL;
	token = NONE;
	load_funct(ptr_function);
	if (line == NULL)
		if (read_line(fd, &tmp, &line) < 1)
		{
			*str = ft_strdup("(null)");
			return (END);
		}
	line = ft_beg_trim(line);
	while (i < 9)
		if ((index = (*ptr_function[i++])(&token, &line, fd, str)) >= 1)
		{
			g_data.col += index;
			if (token == STRING && ft_strchr(*str, '\n') != NULL)
			{
				free(tmp);
				tmp = line;
			}
			if (token == NONE)
				ft_lexixal_error();
			return (token);
		}
	free(tmp);
	if (token == NONE)
		ft_lexixal_error();
	return (token);
}
