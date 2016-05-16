/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:43:04 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/16 18:24:54 by cjacques         ###   ########.fr       */
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

int				ft_head_cpy(char *str, char **tmp, int len, int fd)
{
	int		i;
	int		size;

	i = 1;
	size = 0;
	while ((*tmp)[i] != '"' && size < len)
	{
		if ((*tmp)[i] == 0)
		{
			i = 0;
			str[size++] = '\n';
			if (get_next_line(fd, tmp) < 1)
				ft_exit_mess(1);
			g_data.line++;
			continue ;
		}
		str[size++] = (*tmp)[i++];
	}
	return (i);
}

int				get_header(char *str, char *line, int len, int fd)
{
	int			i;
	static int	name = 0;
	static int	comment = 0;
	char		*tmp;

	if (len == PROG_NAME_LENGTH)
		name++;
	else
		comment++;
	if (name > 1 || comment > 1)
		ft_exit_mess(2);
	tmp = line;
	while (*tmp && *tmp != '"')
	{
		if (ft_isspace(*tmp) != 1)
			ft_exit_mess(0);
		tmp++;
	}
	i = ft_head_cpy(str, &tmp, len, fd);
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
			name = get_header(header->prog_name, tmp + 5, PROG_NAME_LENGTH, fd);
		else if (ft_strncmp(tmp, COMMENT_CMD_STRING, 8) == 0)
			comment = get_header(header->comment, tmp + 8, COMMENT_LENGTH, fd);
		else if (ft_empty(line) == 0)
			ft_exit_mess(3);
		free(line);
		g_data.line++;
		if (name == TRUE && comment == TRUE)
			return (header);
	}
	return (header);
}

/*void			parse_file(int fd, char *str, int arg)
{
	t_header	*header;
	t_list		*lbls;
	t_list		*cmds;

	header = NULL;
	lbls = NULL;
	cmds = NULL;
	header = parse_header(fd);
	parse_body(fd, header, &lbls, &cmds);
	if (cmds == NULL)
		ft_exit_mess(8);
	if (arg > 0)
		print_information(header, lbls, cmds);
	else
		binary(header, cmds, str);
	free_header(header);
	ft_lstdel(&lbls, free_lbl);
	ft_lstdel(&cmds, free_cmd);
}*/
void			parse_file(int fd, char *str, int arg)
{
	char	*line;

	(void)str;
	(void)arg;
	while (next_token(fd, &line) != END)
	{
		printf("%s\n", line);
	}
}
