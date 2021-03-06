/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:00:44 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 17:19:49 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			init_header(t_header *header)
{
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	ft_bzero(header->prog_name, PROG_NAME_LENGTH);
	ft_bzero(header->comment, COMMENT_LENGTH);
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
				ft_head_error(PROG_NAME_LENGTH, header, NAME_CMD_STRING + 1);
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
				ft_head_error(COMMENT_LENGTH, header, COMMENT_CMD_STRING + 1);
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

static void			*ft_head(int fd, t_header *header)
{
	int			name;
	int			comment;
	t_token		tok;
	char		*str;

	name = 0;
	comment = 0;
	init_header(header);
	while ((tok = next_token(fd, &str)) != END)
		if (tok != ENDLINE)
		{
			if (name == 0 && tok == COMMAND_NAME)
				name += ft_name(fd, header);
			else if (comment == 0 && tok == COMMAND_COMMENT)
				comment += ft_comm(fd, header);
			else
				ft_tok_error(tok, str, NULL, 0);
			free(str);
			if (name == 1 && comment == 1)
				return (header);
		}
	ft_tok_error(tok, str, NULL, 0);
	free(header);
	return (header);
}

void				parse_file(int fd, char *str, int arg)
{
	t_header	header;
	t_list		*lbls;
	t_list		*cmds;

	lbls = NULL;
	cmds = NULL;
	g_data.cmds = &cmds;
	g_data.lbls = &lbls;
	ft_head(fd, &header);
	ft_body(fd, &header, &lbls, &cmds);
	if (cmds == NULL)
		ft_tok_error(END, ft_strdup("(null)"), NULL, 0);
	if (arg > 0)
		print_information(&header, lbls, cmds);
	else
		binary(&header, cmds, str);
	ft_lstdel(&lbls, free_lbl);
	ft_lstdel(&cmds, free_cmd);
}
