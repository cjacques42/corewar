/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:43:04 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/11 18:35:34 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_header		*init_header(void)
{
	t_header	*header;

	header = (t_header*)malloc(sizeof(*header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	ft_bzero(header->comment, COMMENT_LENGTH);
	return (header);
}

int				get_header(char *str, char *line, int len)
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
	check_eol(line);
	return (1);
}

t_header		*parse_header(int fd)
{
	char		*line;
	t_header	*header;
	int			name;
	int			comment;

	name = FALSE;
	comment = FALSE;
	header = init_header();
	while (read_line(fd, &line) > 0)
	{
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
		else if (ft_empty(line) == 0)
			ft_exit_mess(3);
		if (name == TRUE && comment == TRUE)
			return (header);
		free(line);
	}
	return (header);
}

void			parse_file(int fd, char *str, int arg)
{
	t_header	*header;
	t_list		*lbls;
	t_list		*cmds;

	header = NULL;
	lbls = NULL;
	cmds = NULL;
	header = parse_header(fd);
	parse_body(fd, header, &lbls, &cmds);
	if (arg > 0)
		print_information(header, lbls, cmds);
	else
		ft_printf("Writing output program to %s\n", str);
}
