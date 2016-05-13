/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:56:34 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/13 15:09:00 by cjacques         ###   ########.fr       */
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
