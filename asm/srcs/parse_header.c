/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:43:04 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/12 18:01:49 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*ft_beg_trim(char *str)
{
	int			index;

	index = 0;
	while ((str[index] == ' ' || str[index] == '\t'
		|| str[index] == '\n') && str[index])
		index++;
	return (str + index);
}

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

int				get_header(char *str, char *line, int len, int fd)
{
	int		i;
	int		size;
	char	*tmp;

	tmp = line;
	while (*tmp && *tmp != '"')
	{
		if (ft_isspace(*tmp) != 1)
			ft_exit_mess(0);
		tmp++;
	}
	i = 1;
	size = 0;
	while (tmp[i] != '"' && size < len)
	{
		if (tmp[i] == 0)
		{
			i = 0;
			str[size++] = '\n';
			get_next_line(fd, &tmp);
			g_data.line++;
			continue ;
		}
		str[size] = tmp[i];
		size++;
		i++;
	}
	if (i >= len)
		ft_exit_mess(1);
	if (tmp[i++] != '"')
		ft_exit_mess(4);
	check_eol(tmp + i);
	return (1);
}

t_header		*parse_header(int fd)
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
		tmp = ft_beg_trim(line);
		if (ft_strncmp(tmp, NAME_CMD_STRING, 5) == 0)
		{
			if (name == TRUE)
				ft_exit_mess(2);
			name = get_header(header->prog_name, tmp + 5, PROG_NAME_LENGTH, fd);
		}
		else if (ft_strncmp(tmp, COMMENT_CMD_STRING, 8) == 0)
		{
			if (comment == TRUE)
				ft_exit_mess(2);
			comment = get_header(header->comment, tmp + 8, COMMENT_LENGTH, fd);
		}
		else if (ft_empty(line) == 0)
			ft_exit_mess(3);
		if (name == TRUE && comment == TRUE)
			return (header);
		free(line);
		g_data.line++;
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
		binary(header, cmds, str);
}
