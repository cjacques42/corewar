/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:00:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 09:22:23 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_cmd	*init_cmd(t_list **cmds, char *str)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	while (g_op_tab[i].label != NULL)
	{
		if (ft_strcmp(g_op_tab[i].label, str) == 0)
		{
			if ((cmd = (t_cmd*)malloc(sizeof(*cmd))) == NULL)
				return (NULL);
			cmd->str = str;
			cmd->addr = g_data.addr;
			cmd->size = 1;
			cmd->nbr = i;
			cmd->arg = NULL;
			cmd->line = g_data.line;
			cmd->opc = 0;
			ft_lstaddback(cmds, ft_lstnew((void*)cmd, sizeof(cmd)));
			return (cmd);
		}
		i++;
	}
	return (NULL);
}

t_cmd			*ft_cmd(int fd, t_list **cmds, char *str)
{
	int			state;
	t_token		tok;
	char		*tmp;
	int			i;
	t_cmd		*cmd;

	state = 0;
	i = 0;
	if ((cmd = init_cmd(cmds, str)) == NULL)
		ft_tok_error(INSTRUCTION, str, NULL, 0);
	while ((tok = next_token(fd, &tmp)) != ENDLINE)
	{
		if (state % 2 == 0 && tok > 0 && tok < 6)
		{
			ft_arg(cmd, i, tok, tmp);
			state++;
			i++;
		}
		else if (state % 2 && tok == SEPARATOR && g_op_tab[cmd->nbr].nb_arg != i)
		{
			state++;
			free(tmp);
		}
		else
			ft_tok_error(tok, tmp, NULL, 0);
	}
	if (g_op_tab[cmd->nbr].nb_arg != i)
		ft_tok_error(tok, str, NULL, 0);
	if (g_op_tab[cmd->nbr].ocp == 0)
		cmd->size++;
	g_data.addr += cmd->size;
	return (cmd);
}
