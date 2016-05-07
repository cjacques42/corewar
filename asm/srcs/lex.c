/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 09:55:43 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/06 12:32:46 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_header	*init_header(void)
{
	t_header	*header;

	header = (t_header*)malloc(sizeof(*header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	ft_bzero(header->comment, COMMENT_LENGTH);
	return (header);
}

int			get_header(char *str, char *line, int len)
{
	int		i;

	while (*line && *line != '"')
	{
		if (ft_isspace(*line) != 1)
			ft_exit_mess(0);
		line++;
	}
	line++;
	i = 0;
	while (*line && *line != '"' && i < len)
	{
		str[i] = *line;
		line++;
		i++;
	}
	if (i >= len)
		ft_exit_mess(1);
	if (*(line++) != '"')
		ft_exit_mess(4);
	while (*line)
	{
		if (ft_comment(*line) == 1)
			return (1);
		if (ft_isspace(*line) != 1)
			ft_exit_mess(0);
		line++;
	}
	return (1);
}

void		start_lex(int fd)
{
	char		*line;
	t_header	*header;
	int			name;
	int			comment;
	char		*tmp;

	name = FALSE;
	comment = FALSE;
	header = init_header();
	while (get_next_line(fd, &line) > 0)
	{
		g_data.line++;
		tmp = line;
		line = ft_strtrim(line);
		free(tmp);
		if (ft_strncmp(line, NAME_CMD_STRING, 5) == 0)
		{
			if (name == TRUE)
				ft_exit_mess(2);
			name = get_header(header->prog_name, line + 5, PROG_NAME_LENGTH);
		}
		else if (ft_strncmp(line, COMMENT_CMD_STRING, 8) == 0)
		{
			if (comment == TRUE)
				ft_exit_mess(2);
			comment = get_header(header->comment, line + 8, COMMENT_LENGTH);
		}
		else
		{
			if (name == TRUE && comment == TRUE)
			{
				ft_printf("%s\n", header->prog_name);
				ft_putstr(header->comment);
				return;
			}
			if (ft_empty(line) == 0)
				ft_exit_mess(3);
		}
		free(line);
	}
}
