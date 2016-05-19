/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 10:47:41 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 19:25:23 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_arg	*init_arg(char *str, t_token tok)
{
	t_arg	*arg;

	if ((arg = (t_arg*)malloc(sizeof(*arg))) == NULL)
		return (NULL);
	arg->key = str;
	if (tok == REGISTER)
		arg->type = T_REG;
	else if (tok == INDIRECT || tok == INDIRECT_LABEL)
		arg->type = T_IND;
	else
		arg->type = T_DIR;
	arg->token = tok;
	arg->nb = 0;
	arg->str = NULL;
	arg->key = str;
	arg->col = g_data.col;
	return (arg);
}

static int		ft_size(t_cmd *cmd, t_arg *arg)
{
	int		type_arg;
	int		size;

	type_arg = arg->type;
	if (type_arg == T_DIR)
	{
		if (g_op_tab[cmd->nbr].dir_size == 1)
			size = 2;
		else
			size = 4;
	}
	if (type_arg == T_IND)
		size = 2;
	if (type_arg == T_REG)
		size = 1;
	cmd->size += size;
	return (1);
}

int				ft_arg(t_cmd *cmd, int index, t_token tok, char *str)
{
	t_arg	*arg;
	int		type_arg;
	int		type_op;

	arg = init_arg(str, tok);
	if (tok == 1 || tok == 2)
		ft_dir(tok, cmd, arg);
	else if (tok == 3)
		ft_reg(tok, arg);
	else
		ft_ind(tok, cmd, arg);
	type_arg = arg->type;
	type_op = g_op_tab[cmd->nbr].type[index];
	if ((type_op & type_arg))
		ft_lstaddback(&(cmd->arg), ft_lstnew(arg, sizeof(arg)));
	else
	{
		free_arg(arg, 0);
		ft_tok_error(tok, ft_strdup(cmd->str), NULL, 2);
	}
	ft_size(cmd, arg);
	return (1);
}
