/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:00:44 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 09:27:52 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_header		*init_header(void)
{
	t_header	*header;

	header = (t_header*)malloc(sizeof(*header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	ft_bzero(header->comment, COMMENT_LENGTH);
	return (header);
}

static int			ft_name(int fd, t_header *header)
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
			ft_tok_error(tok, str, NULL, 0);
		free(str);
		if (state == 2)
			return (1);
	}
	return (0);
}

static int			ft_comm(int fd, t_header *header)
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
			ft_tok_error(tok, str, NULL, 0);
		free(str);
		if (state == 2)
			return (1);
	}
	return (0);
}

static t_header		*ft_head(int fd)
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
				ft_tok_error(tok, str, NULL, 0);
			free(str);
		}
		if (name == 1 && comment == 1)
			return (header);
	}
	ft_tok_error(tok, str, NULL, 0);
	free(header);
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
	g_data.header = &header;
	g_data.cmds = &cmds;
	g_data.lbls = &lbls;
	header = ft_head(fd);
	ft_body(fd, header, &lbls, &cmds);
	if (cmds == NULL)
		ft_tok_error(END, ft_strdup("(null)"), NULL, 0);
	if (arg > 0)
		print_information(header, lbls, cmds);
	else
		binary(header, cmds, str);
	free_header(header);
	ft_lstdel(&lbls, free_lbl);
	ft_lstdel(&cmds, free_cmd);
}
