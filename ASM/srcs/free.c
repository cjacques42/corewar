/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:56:34 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/16 15:59:18 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		free_arg(void *args, size_t size)
{
	t_arg	*arg;

	(void)size;
	arg = args;
	free(arg->key);
	free(arg->str);
	free(arg);
}

void			free_header(t_header *header)
{
	free(header);
}

void			free_cmd(void *cmds, size_t size)
{
	t_cmd	*cmd;

	(void)size;
	cmd = cmds;
	free(cmd->str);
	ft_lstdel(&cmd->arg, free_arg);
	free(cmd);
}

void			free_lbl(void *lbls, size_t size)
{
	t_lbl	*lbl;

	lbl = lbls;
	(void)size;
	free(lbl->lbl_name);
	free(lbl);
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
