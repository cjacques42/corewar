/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:43:04 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/18 12:51:15 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*ft_beg_trim(char *str)
{
	int			index;

	index = 0;
	while ((str[index] == ' ' || str[index] == '\t'
		|| str[index] == '\n') && str[index])
	{
		index++;
		if (str[index] == '\t')
			g_data.col += 4;
		else
			g_data.col += 1;
	}
	return (str + index);
}
/*
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

int				ft_name(int fd, t_header *header)
{
	t_token		tok;
	char		*str;
	int			state;

	state = 0;
	while ((tok = next_token(fd, &str)) != END)
	{
		if (state == 0 && tok == STRING)
		{
			if (ft_strlen(str) > PROG_NAME_LENGTH + 2)
			{
				ft_puterr("Champion name too long (MAX length ");
				ft_putnbr_fd(PROG_NAME_LENGTH, 2);
				ft_puterr(")\n");
				free(header);
				exit(0);
			}
			ft_strncpy(header->prog_name, str + 1, ft_strlen(str) - 2);
			state++;
		}
		else if (state == 1 && tok == ENDLINE)
			state++;
		else
			ft_tok_error(tok, str);
		if (state == 2)
			return (1);
	}
	return (0);
}

int				ft_comm(int fd, t_header *header)
{
	t_token		tok;
	char		*str;
	int			state;

	state = 0;
	while ((tok = next_token(fd, &str)) != END)
	{
		if (state == 0 && tok == STRING)
		{
			if (ft_strlen(str) > COMMENT_LENGTH + 2)
			{
				ft_puterr("Champion name too long (MAX length ");
				ft_putnbr_fd(COMMENT_LENGTH, 2);
				ft_puterr(")\n");
				free(header);
				exit(0);
			}
			ft_strncpy(header->comment, str + 1, ft_strlen(str) - 2);
			state++;
		}
		else if (state == 1 && tok == ENDLINE)
			state++;
		else
			ft_tok_error(tok, str);
		free(str);
		if (state == 2)
			return (1);
	}
	return (0);
}

t_header		*ft_head(int fd)
{
	t_header	*header;
	int			name;
	int			comment;
	t_token		tok;
	char		*str;

	name = 0;
	comment = 0;
	header = init_header();
	while ((tok = next_token(fd, &str)) != END)
	{
		if (tok != ENDLINE)
		{
			if (name == 0 && tok == COMMAND_NAME)
				name += ft_name(fd, header);
			else if (comment == 0 && tok == COMMAND_COMMENT)
				comment += ft_comm(fd, header);
			else
				ft_tok_error(tok, str);
			free(str);
		}
		if (name == 1 && comment == 1)
			return (header);
	}
	ft_tok_error(tok, str);
	free(header);
	return (header);
}

void			parse_file(int fd, char *str, int arg)
{
	char	*line;
	t_header	*header;
	t_token	tok;

	(void)str;
	(void)arg;
	header = ft_head(fd);
	ft_printf("%s\n", header->prog_name);
	ft_printf("%s\n", header->comment);
	while ((tok = next_token(fd, &line)) != END)
	{
		if (tok != NONE)
			printf("%s %d\n", line, tok);
		else
			ft_lexixal_error();
		free(line);
	}
}
